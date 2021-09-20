// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 18:02)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundClientMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundClientMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BackgroundClientMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BackgroundClientMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BACKGROUND_CLIENT_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // BACKGROUND_CLIENT_MIDDLE_LAYER_LIB_H
