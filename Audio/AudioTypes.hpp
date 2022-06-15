#ifndef AUDIO_AUDIOTYPES_HPP_
#define AUDIO_AUDIOTYPES_HPP_

#include "../Config.h"

#if defined(AUDIO_FMOD)
	#include <fmod_errors.h>
	#include <fmod.hpp>
	#include <fmod.h>
	using soundID = uint32_t;
#endif

#endif /* AUDIO_AUDIOTYPES_HPP_ */
