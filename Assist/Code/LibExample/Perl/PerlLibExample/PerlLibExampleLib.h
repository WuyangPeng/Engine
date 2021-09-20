// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:14)

#ifndef PERL_LIB_EXAMPLE_LIB_H
#define PERL_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_PERL_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"PerlLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PerlLibExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_PERL_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"PerlLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PerlLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_PERL_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // PERL_LIB_EXAMPLE_LIB_H
