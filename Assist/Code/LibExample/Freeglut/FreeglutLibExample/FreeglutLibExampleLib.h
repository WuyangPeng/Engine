// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 12:52)

#ifndef FREEGLUT_LIB_EXAMPLE_LIB_H
#define FREEGLUT_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FREEGLUT_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FreeglutLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreeglutLibExample.lib")
		#endif // _DEBUG

	#else // !FREEGLUT_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FreeglutLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreeglutLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // FREEGLUT_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FREEGLUT_LIB_EXAMPLE_LIB_H
