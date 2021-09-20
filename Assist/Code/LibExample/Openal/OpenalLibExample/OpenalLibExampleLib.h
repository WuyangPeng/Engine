// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:33)

#ifndef OPENAL_LIB_EXAMPLE_LIB_H
#define OPENAL_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef OPENAL_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"OpenalLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpenalLibExample.lib")
		#endif // _DEBUG

	#else // !OPENAL_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"OpenalLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpenalLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // OPENAL_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // OPENAL_LIB_EXAMPLE_LIB_H
