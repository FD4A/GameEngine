#include <GLFW/glfw3.h>
#include <GLES3/gl32.h>
#include <iostream>
#include "../Debug.h"
#include "RenderOpenGL.hpp"

int RenderOpenGL::height=600;
int RenderOpenGL::width=800;
Scene* RenderOpenGL::scene=nullptr;

void RenderOpenGL::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch(key)
	{
	}
}

void RenderOpenGL::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	DEBUG_SHORT(render,print("button=",button," action=",action," mods=",mods);)
}
void RenderOpenGL::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	DEBUG_SHORT(render,print("xpos=",xpos," ypos=",ypos);)
}
void RenderOpenGL::cursor_enter_callback(GLFWwindow* window, int entered)
{}
void RenderOpenGL::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{}
void RenderOpenGL::resize_callback(GLFWwindow* window, int x, int y)
{}






