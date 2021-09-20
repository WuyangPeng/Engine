// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 0:19)

#ifndef GLEW_LIB_EXAMPLE_LIB_H
#define GLEW_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_GLEW_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"GlewLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GlewLibExample.lib")
		#endif // _DEBUG

	#else // !GLEW_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"GlewLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"GlewLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // GLEW_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // GLEW_LIB_EXAMPLE_LIB_H
