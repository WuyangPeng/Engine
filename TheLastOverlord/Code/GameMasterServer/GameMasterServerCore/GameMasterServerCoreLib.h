// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 15:45)

#ifndef GAME_MASTER_SERVER_CORE_LIB_H
#define GAME_MASTER_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GAME_MASTER_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GameMasterServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameMasterServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_GAME_MASTER_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GameMasterServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameMasterServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GAME_MASTER_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // GAME_MASTER_SERVER_CORE_LIB_H
