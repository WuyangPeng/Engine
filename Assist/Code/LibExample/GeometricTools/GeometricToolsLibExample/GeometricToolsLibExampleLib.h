// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 22:08)

#ifndef GEOMETRIC_TOOLS_LIB_EXAMPLE_LIB_H
#define GEOMETRIC_TOOLS_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GeometricToolsLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GeometricToolsLibExample.lib")
		#endif // _DEBUG

	#else // !GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GeometricToolsLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GeometricToolsLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // GEOMETRIC_TOOLS_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // GEOMETRIC_TOOLS_LIB_EXAMPLE_LIB_H
