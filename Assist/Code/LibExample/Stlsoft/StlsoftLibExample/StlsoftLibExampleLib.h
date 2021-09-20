// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 16:14) 

#ifndef STLSOFT_LIB_EXAMPLE_LIB_H
#define STLSOFT_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_STLSOFT_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"StlsoftLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"StlsoftLibExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_STLSOFT_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"StlsoftLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"StlsoftLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_STLSOFT_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // STLSOFT_LIB_EXAMPLE_LIB_H
