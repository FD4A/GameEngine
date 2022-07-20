#include <GLFW/glfw3.h>
#include <GLES3/gl32.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Debug.h"
#include "RenderOpenGL.hpp"
#include "../Game/Game.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb_image.h"

//TODO добавить проверку ошибок gl функций

void RenderOpenGL::init(GameInterface* Game_)
{
	RenderOpenGL::game = Game_;
	if( GLFW_TRUE!=glfwInit() )
	{
		std::cerr << "fail glfwInit " << glfwGetError(nullptr) << '\n';
		std::exit(EXIT_FAILURE);
	}

	/*GLFW version*/
	int v_major;
	int v_minor;
	int v_rev;
	glfwGetVersion(&v_major,&v_minor,&v_rev);
	DEBUG_SHORT(render, print("glfwGetVersion() major=",v_major," minor=",v_minor," rev=",v_rev,'\n'); )
	DEBUG_SHORT(render,	const char *ver; ver = glfwGetVersionString(); print(ver,'\n');)

	/*4x smooth*/
	glfwWindowHint(GLFW_SAMPLES, 4);
	/*opengl version*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);/*ban resize*/

	/* open window and create opengl context */
	window = glfwCreateWindow( RenderOpenGL::width, RenderOpenGL::height,  title, NULL, NULL);
	if(NULL==window)
	{
		std::cerr << "fail glfwCreateWindow()\n";
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}
	glViewport(0, 0, RenderOpenGL::width, RenderOpenGL::height);/*0,0 lower left corner here*/

	/*context opengl*/
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, RenderOpenGL::key_callback);
	glfwSetMouseButtonCallback(window, RenderOpenGL::mouse_button_callback);
	glfwSetScrollCallback(window, RenderOpenGL::scroll_callback);
	glfwSetCursorEnterCallback(window, RenderOpenGL::cursor_enter_callback);
	glfwSetCursorPosCallback(window, RenderOpenGL::cursor_position_callback);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	DEBUG_SHORT(render_line_mode,glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);)

	this->initShaderSquare();
}

void RenderOpenGL::frameStart()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); // | GL_DEPTH_BUFFER_BIT);
}

bool RenderOpenGL::frameEnd()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
	if( GLFW_PRESS == glfwGetKey(window,GLFW_KEY_ESCAPE) || glfwWindowShouldClose(window) )
    {
		return true;
    }
	return false;
}

void RenderOpenGL::draw(GameObject& obj)
{
	DEBUG_SHORT(render, print("Render::",__FUNCTION__,'\n'); )
	square.use();
	glBindVertexArray(square.VAO);

	//texId
	glBindTexture(GL_TEXTURE_2D, obj.textureId);
	glm::mat4 modelM = glm::mat4(1.0f);
	modelM = glm::translate(modelM, glm::vec3(
			(static_cast<float>(obj.posHor)-RenderOpenGL::width/2.0f)*(2.0f/static_cast<float>(RenderOpenGL::width)),
			(static_cast<float>(obj.posVer)-RenderOpenGL::height/2.0f)*(2.0f/static_cast<float>(RenderOpenGL::height)),
             0.0f));
	float scaleObj=obj.scale;
	float resolutionScale = static_cast<float>(RenderOpenGL::height)/static_cast<float>(RenderOpenGL::width);
	modelM = glm::scale(modelM, glm::vec3(resolutionScale*scaleObj,scaleObj,scaleObj) );
	glUniformMatrix4fv(square.modelLoc, 1, GL_FALSE, glm::value_ptr(modelM));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RenderOpenGL::initShaderSquare()
{
	square.init("./Render/ShadersOpenGL/source/pole2.vs","./Render/ShadersOpenGL/source/pole2.fs");
	//перенести в другое место чтобы была возможность масштабирования экрана? + у каждого объекта должен быть scale
	float vertices[]={
	//передняя грань куба =)
	-1.0f, -1.0f, 0.0f,//A
		 0.0f, 0.0f,
	1.0f, -1.0f,  0.0f,//B
		 1.0f, 0.0f,
	1.0f, 1.0f,   0.0f,//D
		 1.0f, 1.0f,
	1.0f, 1.0f,   0.0f,//D
		 1.0f, 1.0f,
	-1.0f, 1.0f,  0.0f,//C
		 0.0f, 1.0f,
	-1.0f, -1.0f, 0.0f,//A
		 0.0f, 0.0f
	};

	unsigned int indices[6];
	for(unsigned int i=0; i<6; i++)
		{indices[i]=i;}

	glGenVertexArrays(1, &square.VAO);
	glGenBuffers(1, &square.VBO);
	glGenBuffers(1, &square.EBO);
	glBindVertexArray(square.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, square.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)) );
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, square.EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	square.modelLoc = glGetUniformLocation(square.programID,"transform");
}

textureID RenderOpenGL::createTexture(std::string name)
{
	DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	textureID id;
	int hor=0, ver=0, ch=0;
	unsigned char *buffer=nullptr;
	stbi_set_flip_vertically_on_load(true);
	buffer = stbi_load(name.c_str(), &hor, &ver, &ch, 0);//динамическое выделение?
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	if (nullptr!=buffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, hor, ver, 0, GL_RGB, GL_UNSIGNED_BYTE, buffer);
		glGenerateMipmap(GL_TEXTURE_2D);/*пока всё плоское*/
	}
	else
	{
		std::cerr << "Failed to load texture" << std::endl;
	}
	stbi_image_free(buffer);

	return id;
}

void RenderOpenGL::bindTexture(textureID& value)
{
	DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	glBindTexture(GL_TEXTURE_2D, value);
}

void RenderOpenGL::deleteTexture(textureID& value)
{
	DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	glDeleteTextures(1, &value);
}

int RenderOpenGL::getW()
{
	return RenderOpenGL::width;
}

int RenderOpenGL::getH()
{
	return RenderOpenGL::height;
}

