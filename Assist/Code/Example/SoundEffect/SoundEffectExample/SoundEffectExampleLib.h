// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 21:33)

#ifndef SOUND_EFFECT_EXAMPLE_LIB_H
#define SOUND_EFFECT_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffectExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffectExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SOUND_EFFECT_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SOUND_EFFECT_EXAMPLE_LIB_H
