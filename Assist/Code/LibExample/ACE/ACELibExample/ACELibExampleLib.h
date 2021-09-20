// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/09/30 23:04)

#ifndef ACE_LIB_EXAMPLE_LIB_H
#define ACE_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ACE_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ACELibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ACELibExample.lib")
		#endif // _DEBUG

	#else // !ACE_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ACELibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ACELibExampleStatic.lib")
		#endif // _DEBUG

	#endif // ACE_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ACE_LIB_EXAMPLE_LIB_H
