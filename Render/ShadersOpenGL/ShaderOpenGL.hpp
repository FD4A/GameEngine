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
	unsigned int ID=0;/*shader programm ID*/
	unsigned int VBO=0, VAO=0, EBO=0;
	unsigned int modelLoc=0;
//	unsigned int tex1=0, tex2=0, tex3=0;
	/*constructor read from disk and build shader*/
	void init(const char *vertexPath, const char *fragmentPath);
	void use();

//    void setVec3(const std::string& name, const glm::vec3& value) const
//    	{glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);}
//	void setVec3f(const std::string &name, float x , float y, float z) const
//		{glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);}
private:
	unsigned int load_from_file_create_compile(const char* path, GLenum shaderType);
};

#endif /* SHADER_HPP_ */
