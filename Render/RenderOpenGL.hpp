#ifndef RENDERA_HPP_
#define RENDERA_HPP_

#include <GLFW/glfw3.h>
#include <string>
#include "RenderInterface.hpp"
#include "../Game/Scene.hpp"
#include "ShadersOpenGL/ShaderOpenGL.hpp"

struct RenderOpenGL: public RenderInterface
{
private:
	static int height;
	static int width;
	static Scene *scene;
	GLFWwindow *window=nullptr;
	char title[9]="GameName";
	Shader square;
	void initShaderSquare();
public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void resize_callback(GLFWwindow* window, int x, int y);

	void init() override;
	void frameStart() override;
	bool frameEnd() override;

	void bindTexture(int&& value) override
	{
		DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	}

	void bindTexture(int& value) override
	{
		DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	}

	void unbindTexture() override
	{
		DEBUG_SHORT(render,print("Render::",__FUNCTION__,'\n');)
	}

	void draw(GameObject* obj) override;
};

#endif /* RENDERA_HPP_ */
