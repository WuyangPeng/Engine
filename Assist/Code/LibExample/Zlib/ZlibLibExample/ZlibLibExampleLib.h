// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:09)

#ifndef ZLIB_LIB_EXAMPLE_LIB_H
#define ZLIB_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ZLIB_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ZlibLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ZlibLibExample.lib")
		#endif // _DEBUG

	#else // !ZLIB_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ZlibLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ZlibLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // ZLIB_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ZLIB_LIB_EXAMPLE_LIB_H
