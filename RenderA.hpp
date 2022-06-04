#ifndef RENDERA_HPP_
#define RENDERA_HPP_

#include "RenderInterface.hpp"

struct RenderA: public RenderInterface
{
	void bindTexture(int&& value) override
	{
		std::cout << __FUNCTION__ <<  "A" << '\n';
	}

	void bindTexture(int& value) override
	{
		std::cout << __FUNCTION__ <<  "A" << '\n';
	}

	void unbindTexture() override
	{
		std::cout << __FUNCTION__ << "A" << '\n';
		std::cout << "glDeleteTexturesA\n";
	}

	void draw(GameObject* obj) override
	{
		std::cout << __FUNCTION__ << "A " << "objId=" << obj->id << '\n';
	}

	void draw(GameObject& obj) override
	{
		std::cout << __FUNCTION__ << "A " << "objId=" << obj.id << '\n';
	}
};

#endif /* RENDERA_HPP_ */
