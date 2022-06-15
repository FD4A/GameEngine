#ifndef RENDER_RENDERTYPES_HPP_
#define RENDER_RENDERTYPES_HPP_

#define RENDER_OPENGL

#if defined(RENDER_OPENGL)
	#include <GLES3/gl32.h>
	using textureID = GLuint;
	using shaderID = unsigned int;
#endif

#endif
