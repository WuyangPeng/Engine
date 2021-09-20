// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 18:59)

#ifndef SOUND_EFFECT_TOOLSET_LIB_H
#define SOUND_EFFECT_TOOLSET_LIB_H

#include "SoundEffect/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SOUND_EFFECT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffectToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_SOUND_EFFECT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "SoundEffect/SoundEffectLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"SoundEffectToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SoundEffectToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SOUND_EFFECT_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SOUND_EFFECT_TOOLSET_LIB_H
