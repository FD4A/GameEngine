#ifndef RESOURCEMANAGER_TEXTUREMANAGER_HPP_
#define RESOURCEMANAGER_TEXTUREMANAGER_HPP_

/*
 * По имени техтуры возвращает id, если id нет, то грузит текстура
 * создаёт рендером и возвращает id
 */


#include <unordered_map>
#include <string>
#include "../Render/RenderInterface.hpp"

struct Image
{

};

struct TextureManager
{
private:
	std::unordered_map<std::string,textureID> storage;
	static RenderInterface* render;
	textureID loadImageCreateTexture(std::string texturePathName);
public:
	//unsigned int -> на свой тип который определиться в зависимости от рендера
	void init(RenderInterface* newRender);
	textureID getTextureId(std::string& texturePathName);
	textureID getTextureId(std::string&& texturePathName);
};



#endif /* RESOURCEMANAGER_TEXTUREMANAGER_HPP_ */
