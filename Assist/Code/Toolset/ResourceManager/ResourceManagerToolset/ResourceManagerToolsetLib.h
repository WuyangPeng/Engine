// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 19:29)

#ifndef RESOURCE_MANAGER_TOOLSET_LIB_H
#define RESOURCE_MANAGER_TOOLSET_LIB_H

#include "ResourceManager/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RESOURCE_MANAGER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManagerToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_RESOURCE_MANAGER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "ResourceManager/ResourceManagerLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ResourceManagerToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ResourceManagerToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RESOURCE_MANAGER_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // RESOURCE_MANAGER_TOOLSET_LIB_H
