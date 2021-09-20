// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/25 19:23)

#ifndef MATHEMATICS_EXAMPLE_LIB_H
#define MATHEMATICS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MATHEMATICS_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MathematicsExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_MATHEMATICS_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MathematicsExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MATHEMATICS_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MATHEMATICS_EXAMPLE_LIB_H
