// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:49)

#ifndef BACKGROUND_CLIENT_CORE_LIB_H
#define BACKGROUND_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundClientCoreD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundClientCore.lib")
		#endif // _DEBUG

	#else // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundClientCoreStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundClientCoreStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BACKGROUND_CLIENT_CORE_STATIC

#endif // TCRE_USE_MSVC 

#endif // BACKGROUND_CLIENT_CORE_LIB_H
