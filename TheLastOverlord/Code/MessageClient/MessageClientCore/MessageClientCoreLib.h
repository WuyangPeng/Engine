// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:28)

#ifndef MESSAGE_CLIENT_CORE_LIB_H
#define MESSAGE_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MESSAGE_CLIENT_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MessageClientCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MessageClientCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_MESSAGE_CLIENT_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MessageClientCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MessageClientCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MESSAGE_CLIENT_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // MESSAGE_CLIENT_CORE_LIB_H
