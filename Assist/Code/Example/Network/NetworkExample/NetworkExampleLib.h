// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/23 23:18)

#ifndef NETWORK_EXAMPLE_LIB_H
#define NETWORK_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_NETWORK_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"NetworkExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_NETWORK_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"NetworkExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_NETWORK_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // NETWORK_EXAMPLE_LIB_H
