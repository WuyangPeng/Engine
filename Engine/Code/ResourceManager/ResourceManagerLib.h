// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 10:20)

#ifndef SOUND_RESOURCE_MANAGER_LIB_H
#define SOUND_RESOURCE_MANAGER_LIB_H
 
#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RESOURCE_MANAGER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManager.lib")
		#endif // _DEBUG

	#else // !BUILDING_RESOURCE_MANAGER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManagerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RESOURCE_MANAGER_STATIC

#endif // TCRE_USE_MSVC  

#endif // SOUND_RESOURCE_MANAGER_LIB_H