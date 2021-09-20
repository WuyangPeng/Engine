// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/02 22:57)

#ifndef CORE_TOOLS_TOOLSET_LIB_H
#define CORE_TOOLS_TOOLSET_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_CORE_TOOLS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"CoreToolsToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CoreToolsToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_CORE_TOOLS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"CoreToolsToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CoreToolsToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_CORE_TOOLS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // CORE_TOOLS_TOOLSET_LIB_H
