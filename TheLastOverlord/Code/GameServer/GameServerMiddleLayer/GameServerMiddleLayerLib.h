// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 17:44)

#ifndef GAME_SERVER_MIDDLE_LAYER_LIB_H
#define GAME_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GameServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GameServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GameServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GAME_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // GAME_SERVER_MIDDLE_LAYER_LIB_H
