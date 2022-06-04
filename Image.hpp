#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include <iostream>
#include "RenderInterface.hpp"

struct Image
{
private:
	static RenderInterface* render;
public:
	int a;

	static void initRender(RenderInterface* newRender)
		{render = newRender;}

	Image(int& value): a(value)
		{}
	Image(int&& value): a(value)
		{}

	void bindTexture()
	{
		std::cout << "Image::bindTexture()\n";
		render->bindTexture(a);
	}

	void unbindTexture()
	{
		std::cout << "Image::unbindTexture()\n";
		render->unbindTexture();
	}
};


#endif /* IMAGE_HPP_ */
