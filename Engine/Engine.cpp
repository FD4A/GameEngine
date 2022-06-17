#include "Engine.hpp"
#include "../Game/Game.hpp"

void Engine::clearScene()
{
	game.clear();
}

void Engine::createScene1()
{
	textureID tid = textureManager.getTextureId( std::string("./resource/")+std::string("tex7.png") );
	float cardscale = 0.5f;

	game.addObject(GameObject(40,120,cardscale,tid,11,12));
	game.addObject(GameObject(500,300,cardscale,tid,3,2));
	game.addObject(GameObject(300,400,cardscale,tid,15,7));

	tid = textureManager.getTextureId( std::string("./resource/")+std::string("c15-46-karlov-of-the-ghost-council.jpg") );
	game.addObject(GameObject(300,400,cardscale,tid,0,0));
}

void Engine::createScene2()
{
	textureID tid = textureManager.getTextureId( std::string("./resource/")+std::string("mh1-202-hogaak-arisen-necropolis.jpg") );
	float cardscale = 0.5f;
	game.addObject(GameObject(40,120,cardscale,tid,3,4));
	game.addObject(GameObject(500,300,cardscale,tid,3,1));
	game.addObject(GameObject(300,400,cardscale,tid,5,4));

	tid = textureManager.getTextureId( std::string("./resource/")+std::string("Karlov.jpg") );
	game.addObject(GameObject(200,300,cardscale,tid,0,0));
}

void Engine::createScene3()
{
	textureID tid = textureManager.getTextureId( std::string("./resource/")+std::string("square.png") );
	game.addObject(GameObject(300,500,0.1f,tid,0,0));
}
