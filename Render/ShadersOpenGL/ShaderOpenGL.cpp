#include "ShaderOpenGL.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#if !defined(LOG)
	#define LOGGER std::cout
#endif

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
			{LOGGER << "fail open path=" << path << "\n";}
		else
			{LOGGER << "success open path\n";}
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
			{LOGGER << "fail glCompileShader()\n";}
		else
			{LOGGER << "success glCompileShader()\n";}
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
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	GLint status;
	glGetProgramiv(ID, GL_LINK_STATUS, &status);
	if( !status )
		{LOGGER << "fail glLinkProgram\n";}
	else
		{LOGGER << "success glLinkProgram\n";}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use()
	{glUseProgram(ID);}

