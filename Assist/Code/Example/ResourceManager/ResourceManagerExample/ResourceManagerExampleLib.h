// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 0:50)

#ifndef RESOURCE_MANAGER_EXAMPLE_LIB_H
#define RESOURCE_MANAGER_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManagerExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManagerExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RESOURCE_MANAGER_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // RESOURCE_MANAGER_EXAMPLE_LIB_H
