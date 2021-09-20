// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 20:19)

#ifndef ANIMATION_EXAMPLE_LIB_H
#define ANIMATION_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ANIMATION_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_ANIMATION_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ANIMATION_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ANIMATION_EXAMPLE_LIB_H
