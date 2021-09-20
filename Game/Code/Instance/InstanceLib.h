// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 21:12)

#ifndef INSTANCE_LIB_H
#define INSTANCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_INSTANCE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"InstanceD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Instance.lib")
		#endif // _DEBUG

	#else // !BUILDING_INSTANCE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"InstanceStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InstanceStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_INSTANCE_STATIC

#endif // TCRE_USE_MSVC 

#endif // INSTANCE_LIB_H
