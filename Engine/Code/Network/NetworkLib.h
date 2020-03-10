// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/09 19:16)

#ifndef NETWORK_LIB_H
#define NETWORK_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_NETWORK_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Network.lib")
		#endif // _DEBUG

	#else // !BUILDING_NETWORK_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"NetworkStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_NETWORK_STATIC

#endif // TCRE_USE_MSVC 

#endif // NETWORK_LIB_H
