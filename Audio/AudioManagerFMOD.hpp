#ifndef AUDIO_AUDIOMANAGERFMOD_HPP_
#define AUDIO_AUDIOMANAGERFMOD_HPP_

#include <fmod_errors.h>
#include <fmod.hpp>
#include <fmod.h>
#include <array>

#include "AudioManagerInterface.hpp"
#include "../Game/Game.hpp"

typedef struct
{
	soundID id;
	FMOD::Sound *sound;
	std::string filename;
} sound_t;

struct AudioManagerFMOD: public AudioManagerInterface
{
	static Game* game;
	FMOD::System *asystem=nullptr;
	std::array<sound_t,1> sounds;

//	FMOD::ChannelGroup *channelMusic=nullptr;
	FMOD::ChannelGroup *channelEffects=nullptr;
//		FMOD::Channel *channelL=nullptr;
//		FMOD::Channel *channelR=nullptr;
		FMOD::Channel *channelAlwaysNearListener=nullptr;

	void init(void* game) override;
	void update() override;
	void createSound(std::string name) override;
//	void playSound(soundID id) override;

	AudioManagerFMOD();
};

#endif /* AUDIO_AUDIOMANAGERFMOD_HPP_ */
