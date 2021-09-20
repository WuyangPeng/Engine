// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 1:13)

#ifndef RENDERING_EXAMPLE_LIB_H
#define RENDERING_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RENDERING_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RenderingExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_RENDERING_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RenderingExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RENDERING_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // RENDERING_EXAMPLE_LIB_H
