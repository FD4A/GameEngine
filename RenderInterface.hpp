#ifndef RENDERINTERFACE_HPP_
#define RENDERINTERFACE_HPP_

#include "GameObject.hpp"

struct RenderInterface
{
	virtual void draw(GameObject& obj)=0;
	virtual void draw(GameObject* obj)=0;
	virtual void bindTexture(int&& value)=0;
	virtual void bindTexture(int& value)=0;
	virtual void unbindTexture()=0;
	virtual ~RenderInterface(){};
};

#endif /* RENDERINTERFACE_HPP_ */
