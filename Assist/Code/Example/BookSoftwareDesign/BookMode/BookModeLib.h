// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.3.0 (2020/03/24 21:32)

#ifndef BOOK_MODE_LIB_H
#define BOOK_MODE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_MODE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookModeD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookMode.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_MODE_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BookModeStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookModeStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_MODE_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_MODE_LIB_H
