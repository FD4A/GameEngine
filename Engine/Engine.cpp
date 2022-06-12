#include "Engine.hpp"
#include "../Game/Game.hpp"

void Engine::clearScene()
{
	game.clear();
}

void Engine::createScene1()
{
	textureID tid = textureManager.getTextureId( std::string("./resource/")+std::string("tex7.png") );

	game.addObject(GameObject(40,120,tid,11,12));
	game.addObject(GameObject(500,300,tid,3,2));
	game.addObject(GameObject(300,400,tid,15,7));

	tid = textureManager.getTextureId( std::string("./resource/")+std::string("c15-46-karlov-of-the-ghost-council.jpg") );
	game.addObject(GameObject(300,400,tid,0,0));
}

void Engine::createScene2()
{
	textureID tid = textureManager.getTextureId( std::string("./resource/")+std::string("mh1-202-hogaak-arisen-necropolis.jpg") );

	game.addObject(GameObject(40,120,tid,3,4));
	game.addObject(GameObject(500,300,tid,3,1));
	game.addObject(GameObject(300,400,tid,5,4));

	tid = textureManager.getTextureId( std::string("./resource/")+std::string("Karlov.jpg") );
	game.addObject(GameObject(200,300,tid,0,0));
}
