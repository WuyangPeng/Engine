// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/12 23:03)

#ifndef LOG_SERVER_MIDDLE_LAYER_LIB_H
#define LOG_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"LogServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LogServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"LogServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LogServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_LOG_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // LOG_SERVER_MIDDLE_LAYER_LIB_H