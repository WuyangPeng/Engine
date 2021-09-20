// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/08 23:50)

#ifndef GAME_CLIENT_CORE_LIB_H
#define GAME_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GAME_CLIENT_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GameClientCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameClientCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_GAME_CLIENT_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GameClientCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameClientCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GAME_CLIENT_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // GAME_CLIENT_CORE_LIB_H