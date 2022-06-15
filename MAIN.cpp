#include <iostream>

#include "Engine/Engine.hpp"
#include "Render/RenderOpenGL.hpp"
#include "Audio/AudioManagerFMOD.hpp"

#if ENGINE_DEBUG
	Debug_t Debug;
#endif

int main()
{
	#ifdef RENDER_OPENGL
		RenderOpenGL render;
	#else
	#endif

	#ifdef AUDIO_FMOD
		AudioManagerFMOD audio;
	#else
	#endif

	Engine engine;
	engine.init(dynamic_cast<RenderInterface*>(&render),
				dynamic_cast<AudioManagerInterface*>(&audio)
				);

	engine.gameLoop();

	return 0;
}
