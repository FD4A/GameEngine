#include "../Debug.h"
#include "AudioManagerFMOD.hpp"
#include "../Game/Game.hpp"

AudioManagerFMOD::AudioManagerFMOD()
{

}

void AudioManagerFMOD::init(GameInterface* Game_)
{
	AudioManagerFMOD::game =Game_;
	FMOD_RESULT res;
	FMOD::Debug_Initialize(FMOD_DEBUG_LEVEL_ERROR |
						   FMOD_DEBUG_LEVEL_WARNING |
						   FMOD_DEBUG_LEVEL_LOG |
						   FMOD_DEBUG_TYPE_MEMORY |
						   FMOD_DEBUG_TYPE_FILE |
						   FMOD_DEBUG_TYPE_CODEC |
						   FMOD_DEBUG_TYPE_TRACE |
						   FMOD_DEBUG_DISPLAY_TIMESTAMPS |
						   FMOD_DEBUG_DISPLAY_LINENUMBERS |
						   FMOD_DEBUG_DISPLAY_THREAD  , FMOD_DEBUG_MODE_TTY,  0, 0 );


	res = FMOD::System_Create(&asystem, FMOD_VERSION);
	if(res)
	{
		std::cerr << "fail System_Create " << FMOD_ErrorString(res) << "\n";
		return std::exit(EXIT_FAILURE);
	}

	int maxchannels=1000;//TODO вынести в поле класса?
	res = asystem->init(maxchannels, FMOD_INIT_NORMAL, nullptr);
	if(res)
	{
		std::cerr << "fail System_Create " << FMOD_ErrorString(res) << "\n";
		return std::exit(EXIT_FAILURE);
	}

	DEBUG_SHORT(audio,
			unsigned int version=0;
			res = asystem->getVersion(&version);
			if(res)
			{
				std::cerr << "fail System_Create " << FMOD_ErrorString(res) << "\n";
				return std::exit(EXIT_FAILURE);
			}
			print("FMOD getVersion=",version);
	)

	createSound( std::string("./resource/")+std::string("click.wav") );

	/*listener*/
	FMOD_VECTOR v;	v.x = 0;	v.y = 0;	v.z = 0;
	FMOD_VECTOR f;	f.x = 0;	f.y = 1.0;	f.z = 0.0;
	FMOD_VECTOR u;	u.x = 0;	u.y = 0;	u.z = 1.0;
	asystem->set3DListenerAttributes(0, &v, nullptr, &f, &u);
}

void AudioManagerFMOD::createSound(std::string name)
{
	DEBUG_SHORT(audio,print("createSound(",name,")\n");)
	FMOD_RESULT res;
    res = asystem->createSound(name.c_str(), FMOD_DEFAULT | FMOD_UNIQUE, nullptr, &sounds[0].sound );
    if(res)
    	{DEBUG_SHORT(audio,print("fail createSound(%s)\n",FMOD_ErrorString(res));)}
    else
    	{DEBUG_SHORT(audio,print("success createSound()\n");)}
}

//void AudioManagerFMOD::playSound(soundID id)
//{
//}

void AudioManagerFMOD::update()
{
	if( game->isClick() )
	{
		FMOD_RESULT res = asystem->playSound(sounds[0].sound, nullptr, false, &channelAlwaysNearListener);
		DEBUG_SHORT(audio,printf("%s\n",FMOD_ErrorString(res)));
		FMOD_VECTOR v;
		v.x = 0.5;
		v.y = 0.5;
		v.z = 0;
		asystem->set3DListenerAttributes(0, &v, nullptr, nullptr, nullptr);//(0, &listener_pos, &listener_vel, &listener_forward, &listener_up);
	}
	asystem->update();
}
