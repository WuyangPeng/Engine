// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/24 0:15)

#ifndef DATABASE_EXAMPLE_LIB_H
#define DATABASE_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DATABASE_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DatabaseExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_DATABASE_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"DatabaseExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DatabaseExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_DATABASE_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // DATABASE_EXAMPLE_LIB_H
