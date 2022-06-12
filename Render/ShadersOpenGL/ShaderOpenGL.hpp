#ifndef SHADER_OPENGL_HPP_
#define SHADER_OPENGL_HPP_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <GLES3/gl32.h>

class Shader
{
public:
	Shader();
	unsigned int programID=0;
	unsigned int VBO=0, VAO=0, EBO=0;
	unsigned int modelLoc=0;

	/*read from disk and build shader*/
	void init(const char *vertexPath, const char *fragmentPath);
	void use();
	~Shader()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteBuffers(1, &EBO);
		glDeleteProgram(programID);
	}
private:
	unsigned int load_from_file_create_compile(const char* path, GLenum shaderType);

};

#endif
