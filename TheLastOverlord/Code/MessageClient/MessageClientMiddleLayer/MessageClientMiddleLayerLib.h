// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:55)

#ifndef MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H
#define MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MessageClientMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MessageClientMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MessageClientMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MessageClientMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MESSAGE_CLIENT_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // MESSAGE_CLIENT_MIDDLE_LAYER_LIB_H
