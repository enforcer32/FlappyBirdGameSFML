#pragma once

#include "FlappyBird/Util/Platform.h"
#include "FlappyBird/Util/Logger.h"

#if defined FLAPPYBIRD_DEBUG
	#ifdef FLAPPYBIRD_PLATFORM_WINDOWS
		#define FLAPPYBIRD_DEBUGBREAK() __debugbreak()	
	#else
		#error "Platform doesnt support debugbreak"
	#endif
	#define FLAPPYBIRD_ENABLE_ASSERTS
#else
	#define FLAPPYBIRD_DEBUGBREAK()
#endif

#ifdef FLAPPYBIRD_ENABLE_ASSERTS
	#define FLAPPYBIRD_ASSERT(x, msg) { if(!(x)) { FLAPPYBIRD_LOG_ERROR("Assertion Error: {}, File: {}, Line: {}", msg, __FILE__, __LINE__); FLAPPYBIRD_DEBUGBREAK(); } }
#else
	#define FLAPPYBIRD_ASSERT(...)
#endif
