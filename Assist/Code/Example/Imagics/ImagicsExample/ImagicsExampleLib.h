// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/26 19:14)

#ifndef IMAGICS_EXAMPLE_LIB_H
#define IMAGICS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_IMAGICS_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ImagicsExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_IMAGICS_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ImagicsExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_IMAGICS_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // IMAGICS_EXAMPLE_LIB_H
