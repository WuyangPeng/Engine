// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/25 22:54)

#ifndef INPUT_OUTPUT_EXAMPLE_LIB_H
#define INPUT_OUTPUT_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutputExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutputExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // INPUT_OUTPUT_EXAMPLE_LIB_H
