#ifndef RENDERA_HPP_
#define RENDERA_HPP_

#include <GLFW/glfw3.h>
#include <string>
#include "../Game/GameInterface.hpp"
#include "RenderInterface.hpp"
#include "../Game/Game.hpp"
#include "ShadersOpenGL/ShaderOpenGL.hpp"

struct RenderOpenGL: public RenderInterface
{
private:
	static inline int height = 1024;
	static inline int width = 768;
	GLFWwindow *window=nullptr;
	char title[9]="GameName";
	Shader square;
	void initShaderSquare();
	static inline GameInterface* game = nullptr;
	static inline double xpos = 0.0;
	static inline double ypos = 0.0;
public:
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void resize_callback(GLFWwindow* window, int x, int y);

	void init(GameInterface* game) override;
	void frameStart() override;
	bool frameEnd() override;

	textureID createTexture(std::string name) override;
	void bindTexture(textureID& value) override;
	void deleteTexture(textureID& value) override;

	void draw(GameObject& obj) override;

	int getW() override;
	int getH() override;

	~RenderOpenGL()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};

#endif /* RENDERA_HPP_ */
