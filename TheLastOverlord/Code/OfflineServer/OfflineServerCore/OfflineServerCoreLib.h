// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:02)

#ifndef OFFLINE_SERVER_CORE_LIB_H
#define OFFLINE_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_OFFLINE_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"OfflineServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OfflineServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_OFFLINE_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"OfflineServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OfflineServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_OFFLINE_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // OFFLINE_SERVER_CORE_LIB_H
