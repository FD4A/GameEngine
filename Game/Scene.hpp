#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <vector>
#include "../Debug.h"
#include "../Render/RenderInterface.hpp"
#include "../Game/GameObject.hpp"

template<typename Container, typename Operation>
void for_all(Container& c, Operation op)
{
	for(auto& x:c)
	{
		op(x);
	}
}

struct Scene
{
private:
	static RenderInterface* render;
	std::vector<GameObject> objects;

public:
	bool finish = false;
	Scene() = delete;

	static void initRender(RenderInterface* newRender)
		{render = newRender;}

	Scene(size_t N)
		{objects.reserve(N);}

	void addObject(GameObject&& obj)
	{
		DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)
		objects.push_back(std::move(obj));
	}

	void draw()
	{
		DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)

		//1
		for(auto& obj: objects)
			{render->draw( static_cast<GameObject*>(&obj) );}//как указатель заменить на ссылку >.<?
		//2
//		std::for_each(objects.begin(), objects.end(), [](GameObject& obj){render->draw(obj);} );
		//3
//		for_all(objects, [](GameObject& obj){render->draw(obj);} );
		//4
//		for(size_t i=0; i<objects.size(); ++i)
//		{
//			render->draw(&objects[i]);
//		}
	}
};

#endif /* SCENE_HPP_ */
