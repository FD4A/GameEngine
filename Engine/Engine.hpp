#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "../Render/RenderInterface.hpp"
#include "../ResourceManager/TextureManager.hpp"
#include "../Game/Game.hpp"

struct Engine
{
private:
	RenderInterface* render;
	TextureManager textureManager;
public:
	void init(RenderInterface* newRender)
	{
		render=newRender;
		Game::initRender(newRender);
		render->init();
		textureManager.init(newRender);
		createScene2();
	}
	Game game{1000};

	void createScene1();
	void createScene2();
	void clearScene();

	void gameLoop()
	{
		int sw = 0;
		while(!game.finish)
		{
			game.update();
			//animation update?
			//playsound?
			render->frameStart();
			game.draw();
			game.finish = render->frameEnd();
		}
	}
};

#endif /* ENGINE_HPP_ */
