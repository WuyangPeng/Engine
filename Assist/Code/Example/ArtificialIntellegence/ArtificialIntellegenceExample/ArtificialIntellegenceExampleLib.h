// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 1:14)

#ifndef ARTIFICIAL_INTELLEGENCE_EXAMPLE_LIB_H
#define ARTIFICIAL_INTELLEGENCE_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegenceExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ArtificialIntellegenceExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ArtificialIntellegenceExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ARTIFICIAL_INTELLEGENCE_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ARTIFICIAL_INTELLEGENCE_EXAMPLE_LIB_H
