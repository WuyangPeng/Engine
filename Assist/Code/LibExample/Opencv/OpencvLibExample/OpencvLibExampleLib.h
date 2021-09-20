// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 13:56)

#ifndef OPENCV_LIB_EXAMPLE_LIB_H
#define OPENCV_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_OPENCV_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"OpencvLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpencvLibExample.lib")
		#endif // _DEBUG

	#else // !OPENCV_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"OpencvLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpencvLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // OPENCV_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // OPENCV_LIB_EXAMPLE_LIB_H
