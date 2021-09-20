// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 22:36)

#ifndef PHYSICS_TOOLSET_LIB_H
#define PHYSICS_TOOLSET_LIB_H

#include "Physics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_PHYSICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PhysicsToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_PHYSICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Physics/PhysicsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"PhysicsToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"PhysicsToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_PHYSICS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // PHYSICS_TOOLSET_LIB_H
