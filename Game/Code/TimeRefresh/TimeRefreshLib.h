// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 21:38)

#ifndef ACTIVITY_LIB_H
#define ACTIVITY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ACTIVITY_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ActivityD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Activity.lib")
		#endif // _DEBUG

	#else // !BUILDING_ACTIVITY_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ActivityStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ActivityStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ACTIVITY_STATIC

#endif // TCRE_USE_MSVC 

#endif // ACTIVITY_LIB_H
