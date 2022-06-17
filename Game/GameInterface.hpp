#ifndef GAME_GAMEINTERFACE_HPP_
#define GAME_GAMEINTERFACE_HPP_

struct GameInterface
{
	virtual void setClick(size_t xpos, size_t ypos)=0;
	virtual bool isClick()=0;
	virtual ~GameInterface(){};
};



#endif /* GAME_GAMEINTERFACE_HPP_ */
