#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "ShaderOpenGL.hpp"
#include "../../Debug.h"

unsigned int Shader::load_from_file_create_compile(const char* path, GLenum shaderType)
{
	unsigned int shader;
	GLint success;
	/*shader*/
	std::string code;
	{
		std::stringstream strStream;
		std::ifstream fromstream{path};
		if( !fromstream )
			{ELOG << "fail open path=" << path << "\n";}
		else
			{ DEBUG_SHORT(shader,print("success open path\n");) }
		strStream << fromstream.rdbuf();
		fromstream.close();
		code = strStream.str();
	}

	{
		const char* shaderCpp = code.c_str();
		shader = glCreateShader(shaderType);
		glShaderSource(shader, 1, &shaderCpp, NULL);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(!success)
			{ELOG << "fail glCompileShader()\n";}
		else
			{ DEBUG_SHORT(shader,print("success glCompileShader()\n");) }
	}
	return shader;
}

Shader::Shader()
{}

void Shader::init(const char *vertexPath, const char *fragmentPath)
{
	unsigned int vertexShader = load_from_file_create_compile(vertexPath, GL_VERTEX_SHADER);
	unsigned int fragmentShader = load_from_file_create_compile(fragmentPath, GL_FRAGMENT_SHADER);
	/*link program*/
	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);
	GLint status;
	glGetProgramiv(programID, GL_LINK_STATUS, &status);
	if( !status )
		{ELOG << "fail glLinkProgram\n";}
	else
		{ DEBUG_SHORT(shader,print("success glLinkProgram()\n");) }
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
	{glUseProgram(programID);}

