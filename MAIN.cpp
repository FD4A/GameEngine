#include <iostream>

#include "Engine/Engine.hpp"
#include "Render/RenderOpenGL.hpp"

#if defined(ENGINE_DEBUG)
	Debug_t Debug;
#endif

int main(int argc, char **argv)
{
	Debug.render = true;
	RenderOpenGL render;
	Engine engine;
	for(size_t i=0; i<3; ++i)
		{engine.scene.addObject(GameObject(i*5,i*10));}

	engine.initRender(static_cast<RenderInterface*>(&render));
	engine.gameLoop();

	return 0;
}
