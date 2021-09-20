// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 1:38)

#ifndef EXAMPLE_TOOLSET_LIB_H
#define EXAMPLE_TOOLSET_LIB_H

#include "Macro/Macro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ExampleToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ExampleToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ExampleToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ExampleToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // EXAMPLE_TOOLSET_LIB_H
