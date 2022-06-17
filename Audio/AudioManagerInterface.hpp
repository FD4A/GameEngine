#ifndef AUDIOMANAGERINTERFACE_HPP_
#define AUDIOMANAGERINTERFACE_HPP_

#include "../Game/GameInterface.hpp"
#include "AudioTypes.hpp"

struct AudioManagerInterface
{
	virtual void init(GameInterface* game)=0;
	virtual void update()=0;
	virtual void createSound(std::string name)=0;
//	virtual void playSound(soundID id)=0;
	virtual ~AudioManagerInterface(){};
};

#endif /* AUDIOMANAGERINTERFACE_HPP_ */
