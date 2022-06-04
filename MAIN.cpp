#include <iostream>

#include "Image.hpp"
#include "RenderA.hpp"
#include "RenderB.hpp"
#include "Engine.hpp"

int main(int argc, char **argv)
{
	RenderA renderA;
	RenderB renderB;

	/*работа с ресурсами отдельный вопрос*/
//	Image::initRender(static_cast<RenderInterface*>(&renderA));
//	Image img(10);
//	img.bindTexture();
//	img.unbindTexture();

	/*
	 * Организация классов - как сделать чтобы не было вызовов
	 * opengl или directx нигде кроме конкретного рендера.
	*/
	Engine engine;
	for(size_t i=0; i<3; ++i)
		{engine.scene.addObject(GameObject(i*5,i*10));}

	engine.initRender(static_cast<RenderInterface*>(&renderA));
	engine.scene.draw();//внутри вызовы renderA.draw(GameObject*), но на renderA смотрим через RenderInterface*

	engine.initRender(static_cast<RenderInterface*>(&renderB));
	engine.scene.draw();//внутри вызовы renderB.draw(GameObject*), но на renderA смотрим через RenderInterface*

	return 0;
}
