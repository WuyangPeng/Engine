// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 09:52)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_LIB_H
#define FIGHTING_SERVER_MIDDLE_LAYER_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FightingServerMiddleLayerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FightingServerMiddleLayer.lib")
		#endif // _DEBUG

	#else // !BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FightingServerMiddleLayerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FightingServerMiddleLayerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FIGHTING_SERVER_MIDDLE_LAYER_STATIC

#endif // TCRE_USE_MSVC 

#endif // FIGHTING_SERVER_MIDDLE_LAYER_LIB_H
