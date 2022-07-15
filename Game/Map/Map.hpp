#ifndef GAME_MAP_MAP_HPP_
#define GAME_MAP_MAP_HPP_

#include <array>
#include "Title.hpp"

struct Map
{
	uint16_t size_hor = 32;
	uint16_t size_ver = 24;
	uint16_t title_pix_size = 32;
	std::array<Title,24*32> titles;

	Map()
	{
		for(uint16_t hor=0; hor<size_hor; ++hor)
		{
			for(uint16_t ver=0; ver<size_ver; ++ver)
			{
				titles[hor*size_ver+ver].ver = ver;
				titles[hor*size_ver+ver].hor = hor;
				titles[hor*size_ver+ver].value = 0;
			}
		}
	}
};



#endif /* GAME_MAP_MAP_HPP_ */
