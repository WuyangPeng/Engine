// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:17)

#ifndef FREETYPE_LIB_EXAMPLE_LIB_H
#define FREETYPE_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FREETYPE_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FreetypeLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreetypeLibExample.lib")
		#endif // _DEBUG

	#else // !FREETYPE_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FreetypeLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreetypeLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // FREETYPE_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FREETYPE_LIB_EXAMPLE_LIB_H
