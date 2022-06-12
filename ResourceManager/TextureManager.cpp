#include "../Debug.h"
#include "TextureManager.hpp"

RenderInterface* TextureManager::render = nullptr;

void TextureManager::init(RenderInterface* newRender)
{
	render = newRender;
}

textureID TextureManager::loadImageCreateTexture(std::string textureName)
{
	textureID id;
	id = render->createTexture(textureName);
	return id;
}

textureID TextureManager::getTextureId(std::string&& texturePathName)
{
	textureID id;
	std::unordered_map<std::string,textureID>::iterator item = storage.find(texturePathName);
	if(nullptr!=item)
		{id = (*item).second;}
	else
	{
		id = loadImageCreateTexture(texturePathName);
		storage.insert( std::pair<std::string,textureID>(texturePathName,id) );
	}
	return id;
}

