#ifndef GAMEOBJECT_HPP_
#define GAMEOBJECT_HPP_

struct GameObject
{
	static int gid;
	unsigned int textureId=0;
	int id=0;
	int posHor=0;
	int posVer=0;

	GameObject(int posHor, int posVer) noexcept: id(GameObject::gid), posHor(posHor), posVer(posVer)
		{gid++;}

	GameObject(GameObject&& moveobj) noexcept: id(moveobj.id),  posHor(moveobj.posHor),  posVer(moveobj.posVer)
	{
		moveobj.id = 0;
	}
};



#endif /* GAMEOBJECT_HPP_ */
