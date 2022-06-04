#ifndef RENDERB_HPP_
#define RENDERB_HPP_

#include "RenderInterface.hpp"

struct RenderB: public RenderInterface
{
	void bindTexture(int&& value) override
	{
		std::cout << __FUNCTION__ <<  "B" << '\n';
	}

	void bindTexture(int& value) override
	{
		std::cout << __FUNCTION__ <<  "B" << '\n';
	}

	void unbindTexture() override
	{
		std::cout << __FUNCTION__ << "B" << '\n';
		std::cout << "glDeleteTexturesB\n";
	}

	void draw(GameObject* obj) override
	{
		std::cout << __FUNCTION__ << "B " << "objId=" << obj->id << '\n';
	}

	void draw(GameObject& obj) override
	{
		std::cout << __FUNCTION__ << "B " << "objId=" << obj.id << '\n';
	}
};

#endif /* RENDERB_HPP_ */
