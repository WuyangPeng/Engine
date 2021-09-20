// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 15:27)

#ifndef LEADERBOARD_SERVER_CORE_LIB_H
#define LEADERBOARD_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_LEADERBOARD_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"LeaderboardServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LeaderboardServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_LEADERBOARD_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"LeaderboardServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LeaderboardServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_LEADERBOARD_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // LEADERBOARD_SERVER_CORE_LIB_H
