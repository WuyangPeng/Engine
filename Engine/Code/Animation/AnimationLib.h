// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 09:45)

#ifndef ANIMATION_LIB_H
#define ANIMATION_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ANIMATION_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Animation.lib")
		#endif // _DEBUG

	#else // !BUILDING_ANIMATION_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ANIMATION_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ANIMATION_LIB_H