#ifndef DEBUG_EEENGINE_H_
#define DEBUG_EEENGINE_H_

#include <iostream>
#include "Config.h"


template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	//тут бы для не строк, а переменных сделать имя=значение
	std::cout << head << ' ';
	if constexpr ( sizeof...(tail)>0 )
		{print(tail...);}
	else
		{std::cout << '\n';}
}

#define ELOG std::cerr
#if ENGINE_DEBUG
	#define DEBUG_SHORT(flag,action) if(Debug.flag){action;};
	struct Debug_t
	{
		bool scene = false;
		bool render = false;
			bool render_line_mode = false;
			bool render_mouse_button_callback = false;
			bool cursor_position_callback = false;
		bool shader = false;
		bool audio = false;
		bool gameobject = false;
		bool game_setClick = false;
	};
	extern Debug_t Debug;

#else
	#define DEBUG_SHORT(flag,action) {}
#endif

#endif
