#ifndef DEBUG_EEENGINE_H_
#define DEBUG_EEENGINE_H_

#include <iostream>

#define ENGINE_DEBUG

template <typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	//тут бы для не строк, а переменных сделать имя=значение
	std::cout << head;
	if constexpr ( sizeof...(tail)>0 )
		{print(tail...);}
}

#if defined(ENGINE_DEBUG)
	#define DEBUG_SHORT(flag,action) if(Debug.flag){action;};
	struct Debug_t
	{
		bool scene=false;
		bool render=false;
		bool gameobject=false;
	};
	extern Debug_t Debug;
#elif
	#define DEBUG_SHORT {}
#endif

#endif
