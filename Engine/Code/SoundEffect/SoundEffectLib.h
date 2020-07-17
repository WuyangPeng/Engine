// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 13:25)

#ifndef SOUND_EFFECT_LIB_H
#define SOUND_EFFECT_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SOUND_EFFECT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffect.lib")
		#endif // _DEBUG

	#else // !BUILDING_SOUND_EFFECT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffectStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SOUND_EFFECT_STATIC

#endif // TCRE_USE_MSVC  

#endif // SOUND_EFFECT_LIB_H