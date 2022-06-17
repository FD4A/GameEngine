#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "../Render/RenderInterface.hpp"
	#include "../ResourceManager/TextureManager.hpp"
#include "../Audio/AudioManagerInterface.hpp"

#include "../Game/Game.hpp"

struct Engine
{
private:
	RenderInterface* render;
		TextureManager textureManager;
	AudioManagerInterface* audio;
public:
	void init(RenderInterface* newRender, AudioManagerInterface* newAudio)
	{
		render=newRender;
		Game::initRender(newRender);
		render->init(&game);
		textureManager.init(newRender);

		audio = newAudio;
		audio->init(&game);

		createScene3();
	}
	Game game{1000};

	void createScene1();
	void createScene2();
	void createScene3();
	void clearScene();

	void gameLoop()
	{
		while(!game.finish)
		{
			render->frameStart();
			game.draw();
			game.finish = render->frameEnd();

			game.update();

			audio->update();//playsound?

			game.eraseClick();
		}
	}
};

#endif /* ENGINE_HPP_ */
