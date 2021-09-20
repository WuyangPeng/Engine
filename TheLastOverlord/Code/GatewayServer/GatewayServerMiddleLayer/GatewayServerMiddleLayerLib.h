// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:49)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_LIB_H
#define GATEWAY_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GatewayServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GatewayServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GatewayServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GatewayServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_GATEWAY_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // GATEWAY_SERVER_MIDDLE_LAYER_LIB_H
