#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <vector>
#include "../Debug.h"
#include "../Render/RenderInterface.hpp"
#include "../Game/GameObject.hpp"

struct Game
{
private:
	static RenderInterface* render;
	std::vector<GameObject> objects;
public:
	int state=0;/*TODO сделать enum? menu-?loading?-lvl*/
	bool finish = false;
	Game() = delete;

	static void initRender(RenderInterface* newRender);
	explicit Game(size_t N);

	void addObject(GameObject&& obj);
	void update();
	void draw();
	void clear();

	/**/
};

#endif /* SCENE_HPP_ */
