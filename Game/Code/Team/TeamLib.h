// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 22:52)

#ifndef TEAM_LIB_H
#define TEAM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_TEAM_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"TeamD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Team.lib")
		#endif // _DEBUG

	#else // !BUILDING_TEAM_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"TeamStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"TeamStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_TEAM_STATIC

#endif // TCRE_USE_MSVC 

#endif // TEAM_LIB_H
