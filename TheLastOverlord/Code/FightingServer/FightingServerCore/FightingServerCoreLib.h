// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:37)

#ifndef FIGHTING_SERVER_CORE_LIB_H
#define FIGHTING_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FIGHTING_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FightingServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FightingServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_FIGHTING_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FightingServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FightingServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FIGHTING_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // FIGHTING_SERVER_CORE_LIB_H
