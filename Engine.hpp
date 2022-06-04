#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include "RenderInterface.hpp"
#include "Scene.hpp"

struct Engine
{
private:
	RenderInterface* render;
public:
	void initRender(RenderInterface* newRender)
	{
		render=newRender;
		Scene::initRender(newRender);
	}
	Scene scene{1000};
};



#endif /* ENGINE_HPP_ */
