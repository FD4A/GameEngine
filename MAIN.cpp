#include <iostream>

#include "Engine/Engine.hpp"
#include "Render/RenderOpenGL.hpp"

#if ENGINE_DEBUG
	Debug_t Debug;
#endif

int main(int argc, char **argv)
{
	RenderOpenGL render;
	Engine engine;

	engine.init(dynamic_cast<RenderInterface*>(&render));
	engine.gameLoop();

	return 0;
}
