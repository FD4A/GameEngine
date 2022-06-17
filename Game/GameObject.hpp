#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include "../Render/RenderTypes.hpp"/*TODO пока так*/

struct GameObject
{
	static int gid;
	int id=0;
	int posHor=0;
	int posVer=0;
	float scale =1.0;
	textureID textureId=0;
	int speedH = 0;
	int speedV = 0;
	int targetposH = 0;
	int targetposV = 0;
	shaderID shaderId=0;

	GameObject() = delete;
	GameObject(const GameObject& copy) = delete;
	GameObject& operator=(const GameObject& copy) = delete;
	GameObject& operator=(GameObject&& moveobj) = delete;

	void setTextureId(textureID& id)
		{textureId = id;}

	void setShaderId(shaderID& id)
		{shaderId = id;}

	GameObject(int posHor_, int posVer_, float scale_, textureID tid_, int hspeed_, int vspeed_) noexcept:
			id(GameObject::gid),
			posHor(posHor_), posVer(posVer_),
			scale{scale_},
			textureId{tid_},
			speedH(hspeed_), speedV(vspeed_),
			targetposH(posHor_), targetposV(posVer_)
		{gid++;}//пока не думаем о переполнении

	GameObject(GameObject&& moveobj) noexcept:
			id(moveobj.id),
			posHor(moveobj.posHor),  posVer(moveobj.posVer),
			scale{moveobj.scale},
			textureId(moveobj.textureId),
			speedH(moveobj.speedH), speedV(moveobj.speedV),
			targetposH(moveobj.posHor), targetposV(moveobj.posVer)
		{moveobj.id = 0;}

	void update(int limL, int limR, int limT, int limB);

};

#endif /* GAMEOBJECT_HPP_ */
