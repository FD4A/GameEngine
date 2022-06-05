#include <GLFW/glfw3.h>
#include <GLES3/gl32.h>
#include <iostream>
#include "../Debug.h"
#include "RenderOpenGL.hpp"

void RenderOpenGL::init()
{
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
	const char *ver;
	ver = glfwGetVersionString();
	DEBUG_SHORT(render,print(ver,'\n');)

	/*4x smooth*/
	glfwWindowHint(GLFW_SAMPLES, 4);
	/*opengl version*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);/*ban resize*/

	/* open window and create opengl context */
	window = glfwCreateWindow( RenderOpenGL::width, RenderOpenGL::height, title, NULL, NULL);
	if(NULL==window)
	{
		std::cerr << "fail glfwCreateWindow()\n";
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	glViewport(0, 0, width, height);/*0,0 lower left corner here*/

	/*context opengl*/
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, RenderOpenGL::key_callback);
	glfwSetMouseButtonCallback(window, RenderOpenGL::mouse_button_callback);
	glfwSetScrollCallback(window, RenderOpenGL::scroll_callback);
	glfwSetCursorEnterCallback(window, RenderOpenGL::cursor_enter_callback);
	glfwSetCursorPosCallback(window, RenderOpenGL::cursor_position_callback);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
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
	if( GLFW_PRESS == glfwGetKey(window,GLFW_KEY_ESCAPE) )
    	{return true;}
	return false;
}

void RenderOpenGL::draw(GameObject* obj)
{
	DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)

	//shader ID
//	square.use();
//	glBindVertexArray(square.VAO); это mesh?

	//texId
//	glBindTexture(GL_TEXTURE_2D, o->tex);
//	glm::mat4 modelM = glm::mat4(1.0f);
//	modelM = glm::translate(modelM, glm::vec3(
//			(static_cast<float>(o->posHor)-Render::width/2.0f)*(2.0f/static_cast<float>(Render::width)),
//			(static_cast<float>(o->posVer)-Render::height/2.0f)*(2.0f/static_cast<float>(Render::height)),
//             0.0f));
//	glUniformMatrix4fv(square.modelLoc, 1, GL_FALSE, glm::value_ptr(modelM));
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void RenderOpenGL::initShaderSquare()
{
	square.init("./ShadersOpenGL/source/pole2.vs","./ShadersOpenGL/source/pole2.fs");
	float vPOS = 0.1f;
	float dp = 1.0f;
	float scale = 600.0f/800.0f;//перенести в другое место чтобы была возможность масштабирования экрана?
	float vertices[]={
	//передняя грань куба =)
	scale*-vPOS, -vPOS, 0.0f,
		 dp, 1.0f,
	scale*vPOS, -vPOS,  0.0f,
		 0.0f, 1.0f,
	scale*vPOS,  vPOS,  0.0f,
		 0.0f, 0.0f,
	scale*vPOS,  vPOS,  0.0f,
		 0.0f, 0.0f,
	scale*-vPOS,  vPOS, 0.0f,
		 dp, 0.0f,
	scale*-vPOS, -vPOS, 0.0f,
		 dp, 1.0f
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

	square.modelLoc = glGetUniformLocation(square.ID,"transform");
}

