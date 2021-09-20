// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/13 16:39)

#ifndef SERVER_MANAGER_CORE_LIB_H
#define SERVER_MANAGER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SERVER_MANAGER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ServerManagerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ServerManagerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_SERVER_MANAGER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ServerManagerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ServerManagerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SERVER_MANAGER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // SERVER_MANAGER_CORE_LIB_H
