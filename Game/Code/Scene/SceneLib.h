// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/05 21:14)

#ifndef SCENE_LIB_H
#define SCENE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCENE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SceneD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Scene.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCENE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"SceneStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SceneStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCENE_STATIC

#endif // TCRE_USE_MSVC 

#endif // SCENE_LIB_H
