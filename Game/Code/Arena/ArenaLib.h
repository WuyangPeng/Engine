// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 20:42)

#ifndef ARENA_LIB_H
#define ARENA_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ARENA_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ArenaD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Arena.lib")
		#endif // _DEBUG

	#else // !BUILDING_ARENA_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ArenaStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArenaStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ARENA_STATIC

#endif // TCRE_USE_MSVC 

#endif // ARENA_LIB_H
