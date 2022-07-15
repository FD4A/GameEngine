#ifndef RESOURCEMANAGER_TEXTUREMANAGER_HPP_
#define RESOURCEMANAGER_TEXTUREMANAGER_HPP_

/*
 * По имени текстуры возвращает id, если id нет, то грузит текстуру
 * создаёт рендером и возвращает id
 */

#include <unordered_map>
#include <string>
#include "../Render/RenderInterface.hpp"

struct TextureManager
{
private:
	std::unordered_map<std::string,textureID> storage;
	static inline RenderInterface* render = nullptr;
	textureID loadImageCreateTexture(std::string texturePathName);
public:
	void init(RenderInterface* newRender);
	textureID getTextureId(std::string& texturePathName);
	textureID getTextureId(std::string&& texturePathName);
};



#endif /* RESOURCEMANAGER_TEXTUREMANAGER_HPP_ */
