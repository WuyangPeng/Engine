// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 18:01)

#ifndef RECHARGE_SERVER_CORE_LIB_H
#define RECHARGE_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RECHARGE_SERVER_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"RechargeServerCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RechargeServerCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_RECHARGE_SERVER_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"RechargeServerCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RechargeServerCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RECHARGE_SERVER_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // RECHARGE_SERVER_CORE_LIB_H
