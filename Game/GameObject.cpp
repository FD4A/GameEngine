#include <algorithm>
#include "../Debug.h"
#include "GameObject.hpp"

int GameObject::gid=1;

void GameObject::update(int limL, int limR, int limT, int limB)
{
	static int SPEEDLIM = 5;
	//не через speedX и speedY а через курс и скорость ( и ускорение для красоты =) )?

	speedH = std::min( (targetposH - posHor), SPEEDLIM );
	speedH = std::max( speedH, -SPEEDLIM );
	posHor+=speedH;
	if(posHor>limR)
		{speedH*=-1;}
	if(posHor<limL)
		{speedH*=-1;}

	speedV = std::min( (targetposV - posVer), SPEEDLIM );
	speedV = std::max( speedV, -SPEEDLIM );
	posVer+=speedV;
	if(posVer>limT)
		{speedV*=-1;}
	if(posVer<limB)
		{speedV*=-1;}

//	print(targetposH," ",targetposV);
//	print(posHor," ",posVer);
//	print(speedH," ",speedV,"\n");

}
