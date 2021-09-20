// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.3 (2020/05/01 14:09)

#ifndef FRAMEWORK_EXAMPLE_LIB_H
#define FRAMEWORK_EXAMPLE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_FRAMEWORK_EXAMPLE_STATIC

		#include "DllLib.h"		

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FRAMEWORK_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FRAMEWORK_EXAMPLE_LIB_H
