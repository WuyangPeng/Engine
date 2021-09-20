// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 23:00)

#ifndef ANIMATION_TOOLSET_LIB_H
#define ANIMATION_TOOLSET_LIB_H

#include "Animation/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ANIMATION_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_ANIMATION_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Animation/AnimationLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ANIMATION_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ANIMATION_TOOLSET_LIB_H