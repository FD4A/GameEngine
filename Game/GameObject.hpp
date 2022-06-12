#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

#include "../Render/RenderTypes.hpp"/*TODO пока так*/

struct GameObject
{
	static int gid;
	textureID textureId=0;
	shaderID shaderId=0;
	int id=0;
	int posHor=0;
	int posVer=0;
	int speedH = 0;
	int speedV = 0;

	GameObject() = delete;
	GameObject(const GameObject& copy) = delete;
	GameObject& operator=(const GameObject& copy) = delete;
	GameObject& operator=(GameObject&& moveobj) = delete;

	void setTextureId(textureID& id)
		{textureId = id;}

	void setShaderId(shaderID& id)
		{shaderId = id;}

	GameObject(int posHor, int posVer, textureID tid, int hspeed, int vspeed) noexcept: id(GameObject::gid), posHor(posHor), posVer(posVer), textureId{tid},
			speedH(hspeed), speedV(vspeed)
		{gid++;}//пока не думаем о переполнении

	GameObject(GameObject&& moveobj) noexcept: id(moveobj.id),  posHor(moveobj.posHor),  posVer(moveobj.posVer) ,  textureId(moveobj.textureId),
			speedH(moveobj.speedH), speedV(moveobj.speedV)
		{moveobj.id = 0;}

	void update(int limL, int limR, int limT, int limB);

};

#endif /* GAMEOBJECT_HPP_ */
