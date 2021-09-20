// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 10:37)

#ifndef BOOST_LIB_EXAMPLE_LIB_H
#define BOOST_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOST_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BoostLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BoostLibExample.lib")
		#endif // _DEBUG

	#else // !BOOST_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BoostLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BoostLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // BOOST_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // BOOST_LIB_EXAMPLE_LIB_H
