// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:13)

#ifndef WORLD_SERVER_MIDDLE_LAYER_LIB_H
#define WORLD_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"WorldServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WorldServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"WorldServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WorldServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_WORLD_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // WORLD_SERVER_MIDDLE_LAYER_LIB_H
