// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/26 16:00)

#ifndef PHYSICS_EXAMPLE_LIB_H
#define PHYSICS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_PHYSICS_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PhysicsExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_PHYSICS_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PhysicsExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_PHYSICS_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // PHYSICS_EXAMPLE_LIB_H
