// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 20:12)

#ifndef DIRECTX_LIB_EXAMPLE_LIB_H
#define DIRECTX_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DIRECTX_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DirectXLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DirectXLibExample.lib")
		#endif // _DEBUG

	#else // !DIRECTX_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"DirectXLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DirectXLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // DIRECTX_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // DIRECTX_LIB_EXAMPLE_LIB_H
