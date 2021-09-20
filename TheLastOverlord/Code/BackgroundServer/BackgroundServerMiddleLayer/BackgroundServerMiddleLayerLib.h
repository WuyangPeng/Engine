// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:13)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_LIB_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BACKGROUND_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_LIB_H
