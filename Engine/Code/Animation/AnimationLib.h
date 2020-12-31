// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.4.0.0 (2020/07/15 14:32)

#ifndef ANIMATION_LIB_H
#define ANIMATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ANIMATION_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Animation.lib")
		#endif // _DEBUG

	#else // !BUILDING_ANIMATION_STATIC

		#include "DllLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ANIMATION_STATIC

#endif // TCRE_USE_MSVC  

#endif // ANIMATION_LIB_H