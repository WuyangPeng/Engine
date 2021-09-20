// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 19:03)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_LIB_H
#define UPDATE_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UpdateServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UpdateServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"UpdateServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UpdateServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_UPDATE_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // UPDATE_SERVER_MIDDLE_LAYER_LIB_H
