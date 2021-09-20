// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.2 (2020/01/24 19:29)

#ifndef SCRIPT_EXAMPLE_LIB_H
#define SCRIPT_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCRIPT_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCRIPT_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCRIPT_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SCRIPT_EXAMPLE_LIB_H
