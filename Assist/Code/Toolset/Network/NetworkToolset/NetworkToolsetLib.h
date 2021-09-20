// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 1:20)

#ifndef NETWORK_TOOLSET_LIB_H
#define NETWORK_TOOLSET_LIB_H

#include "Network/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_NETWORK_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"NetworkToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_NETWORK_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Network/NetworkLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"NetworkToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"NetworkToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_NETWORK_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // NETWORK_TOOLSET_LIB_H
