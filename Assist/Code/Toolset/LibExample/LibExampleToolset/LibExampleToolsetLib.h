// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 1:46)

#ifndef LIB_EXAMPLE_TOOLSET_LIB_H
#define LIB_EXAMPLE_TOOLSET_LIB_H

#include "Macro/Macro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"LibExampleToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LibExampleToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"LibExampleToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LibExampleToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // LIB_EXAMPLE_TOOLSET_LIB_H
