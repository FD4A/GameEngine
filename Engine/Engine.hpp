#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "../Render/RenderInterface.hpp"
#include "../Game/Scene.hpp"

struct Engine
{
private:
	RenderInterface* render;
public:
	void initRender(RenderInterface* newRender)
	{
		render=newRender;
		Scene::initRender(newRender);
		render->init();
	}
	Scene scene{1000};

	void gameLoop()
	{
		while(!scene.finish)
		{
			//scene.update();+gameupdate
			//scene.update();+animation update
			//scene.playsound();

			render->frameStart();
			scene.draw();
			scene.finish = render->frameEnd();
		}
	}
};



#endif /* ENGINE_HPP_ */
