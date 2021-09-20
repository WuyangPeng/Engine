// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 0:04)

#ifndef OPENSSL_LIB_EXAMPLE_LIB_H
#define OPENSSL_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_OPENSSL_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"OpensslLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpensslLibExample.lib")
		#endif // _DEBUG

	#else // !OPENSSL_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"OpensslLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"OpensslLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // OPENSSL_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // OPENSSL_LIB_EXAMPLE_LIB_H
