// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 14:47)

#ifndef PHYSICS_LIB_H
#define PHYSICS_LIB_H

#include "Macro/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_PHYSICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Physics.lib")
		#endif // _DEBUG

	#else // !BUILDING_PHYSICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Mathematics/Mathematics.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PhysicsStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_PHYSICS_STATIC

#endif // TCRE_USE_MSVC  

#endif // PHYSICS_LIB_H