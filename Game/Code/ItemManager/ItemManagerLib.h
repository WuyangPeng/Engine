// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/04 23:43)

#ifndef ITEM_MANAGER_LIB_H
#define ITEM_MANAGER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ITEM_MANAGER_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ItemManagerD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ItemManager.lib")
		#endif // _DEBUG

	#else // !BUILDING_ITEM_MANAGER_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ItemManagerStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ItemManagerStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ITEM_MANAGER_STATIC

#endif // TCRE_USE_MSVC 

#endif // ITEM_MANAGER_LIB_H
