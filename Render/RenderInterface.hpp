#ifndef RENDERINTERFACE_HPP_
#define RENDERINTERFACE_HPP_

#include "../Game/GameObject.hpp"

struct RenderInterface
{
	virtual void init()=0;
	virtual void frameStart()=0;
	virtual bool frameEnd()=0;

	virtual void draw(GameObject* obj)=0;
	virtual void bindTexture(int&& value)=0;
	virtual void bindTexture(int& value)=0;
	virtual void unbindTexture()=0;
	virtual ~RenderInterface(){};
};

#endif /* RENDERINTERFACE_HPP_ */
