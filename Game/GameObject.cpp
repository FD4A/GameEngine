#include <algorithm>
#include <cmath>
#include "../Debug.h"
#include "GameObject.hpp"

void GameObject::update(int limL, int limR, int limT, int limB)
{
	static float SPEEDLIM = 5;
	int dh = static_cast<float>(targetposH - posHor);
	int dv = static_cast<float>(targetposV - posVer);
	float way = sqrt(dh*dh+dv*dv);
	if(way>0)
	{
		float parts = std::ceil(way/(1.0f*SPEEDLIM));
		speedH = std::ceil(1.0f*dh/parts);
		speedV = std::ceil(1.0f*dv/parts);
	}
	else
	{
		speedH = 0;
		speedV = 0;
	}

//	static int SPEEDLIM = 5;
//	speedH = std::min( (targetposH - posHor), SPEEDLIM );
//	speedH = std::max( speedH, -SPEEDLIM );
	posHor+=speedH;
	if(posHor>limR)
		{speedH*=-1;}
	if(posHor<limL)
		{speedH*=-1;}

//	speedV = std::min( (targetposV - posVer), SPEEDLIM );
//	speedV = std::max( speedV, -SPEEDLIM );
	posVer+=speedV;
	if(posVer>limT)
		{speedV*=-1;}
	if(posVer<limB)
		{speedV*=-1;}
}
