#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <vector>
#include "../Debug.h"
#include "GameInterface.hpp"
#include "../Render/RenderInterface.hpp"
#include "../Game/GameObject.hpp"

struct Game: public GameInterface
{
private:
	static RenderInterface* render;
	std::vector<GameObject> objects;
	bool click = false;
public:
	size_t cposx=0;
	size_t cposy=0;
	int state=0;/*TODO сделать enum? menu-?loading?-lvl*/
	bool finish = false;
	Game() = delete;

	static void initRender(RenderInterface* newRender);
	explicit Game(size_t N);

	void addObject(GameObject&& obj);
	void update();
	void draw();
	void clear();

	void eraseClick()
		{click=false;}
	void setClick(size_t xpos, size_t ypos) override
	{
		click=true;
		cposx = xpos;
		cposy = ypos;
		objects[0].targetposH = xpos;
		objects[0].targetposV = ypos;
	}
	bool isClick() override
		{return click;}
	/**/
};

#endif /* SCENE_HPP_ */
