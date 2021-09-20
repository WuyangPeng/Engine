// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 9:16)

#ifndef IRRLICHT_LIB_EXAMPLE_LIB_H
#define IRRLICHT_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_IRRLICHT_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"IrrlichtLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"IrrlichtLibExample.lib")
		#endif // _DEBUG

	#else // !IRRLICHT_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"IrrlichtLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"IrrlichtLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // IRRLICHT_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // IRRLICHT_LIB_EXAMPLE_LIB_H
