#include "GameObject.hpp"

int GameObject::gid=1;

void GameObject::update(int limL, int limR, int limT, int limB)
{
	posHor+=speedH;
	posVer+=speedV;
	if(posHor>limR)
		{speedH*=-1;}
	if(posHor<limL)
		{speedH*=-1;}
	if(posVer>limT)
		{speedV*=-1;}
	if(posVer<limB)
		{speedV*=-1;}
}
