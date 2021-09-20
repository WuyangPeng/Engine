// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 16:59)

#ifndef GAME_SERVER_CORE_LIB_H
#define GAME_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GAME_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GameServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_GAME_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GameServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GAME_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // GAME_SERVER_CORE_LIB_H
