#include "Game.hpp"

RenderInterface* Game::render = nullptr;

void Game::initRender(RenderInterface* newRender)
	{render = newRender;}

Game::Game(size_t N)
	{objects.reserve(N);}

void Game::addObject(GameObject&& obj)
{
	DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)
	objects.push_back(std::move(obj));
}

void Game::update()
{
	DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)
	for(GameObject& obj: objects)
	{
		obj.update(0, render->getW(), render->getH(), 0);
	}
}

void Game::draw()
{
	DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)
	for(GameObject& obj: objects)
	{
		render->draw(obj);
	}
}

void Game::clear()
{
	DEBUG_SHORT(scene,print("Scene::",__FUNCTION__,'\n');)
	objects.clear();
}
