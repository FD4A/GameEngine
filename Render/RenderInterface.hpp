#ifndef RENDERINTERFACE_HPP_
#define RENDERINTERFACE_HPP_

#include <string>
#include "RenderTypes.hpp"
#include "../Game/GameObject.hpp"

struct RenderInterface
{
	virtual void init()=0;
	virtual void frameStart()=0;
	virtual bool frameEnd()=0;

	virtual void draw(GameObject& obj)=0;
	virtual textureID createTexture(std::string name)=0;
	virtual void bindTexture(textureID& value)=0;
	virtual void deleteTexture(textureID& value)=0;

	virtual int getW()=0;
	virtual int getH()=0;

	virtual ~RenderInterface(){};
};

#endif /* RENDERINTERFACE_HPP_ */
