// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 14:37)

#ifndef WILD_MAGIC_LIB_EXAMPLE_LIB_H
#define WILD_MAGIC_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_WILD_MAGIC_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"WildMagicLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WildMagicLibExample.lib")
		#endif // _DEBUG

	#else // !WILD_MAGIC_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"WildMagicLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WildMagicLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // WILD_MAGIC_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // WILD_MAGIC_LIB_EXAMPLE_LIB_H
