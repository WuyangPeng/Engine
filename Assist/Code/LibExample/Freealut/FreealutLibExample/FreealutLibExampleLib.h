// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 11:28)

#ifndef FREEALUT_LIB_EXAMPLE_LIB_H
#define FREEALUT_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FREEALUT_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FreealutLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreealutLibExample.lib")
		#endif // _DEBUG

	#else // !FREEALUT_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FreealutLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FreealutLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // FREEALUT_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FREEALUT_LIB_EXAMPLE_LIB_H
