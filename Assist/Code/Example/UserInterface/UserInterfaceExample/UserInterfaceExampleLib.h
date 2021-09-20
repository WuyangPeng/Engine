// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/27 14:00)

#ifndef USER_INTERFACE_EXAMPLE_LIB_H
#define USER_INTERFACE_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_USER_INTERFACE_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_USER_INTERFACE_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_USER_INTERFACE_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // USER_INTERFACE_EXAMPLE_LIB_H
