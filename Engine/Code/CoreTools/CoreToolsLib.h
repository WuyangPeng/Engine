// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/15 11:58)

#ifndef CORE_TOOLS_LIB_H
#define CORE_TOOLS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SYSTEM_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"CoreToolsD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CoreTools.lib")
		#endif // _DEBUG

	#else // !BUILDING_SYSTEM_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"CoreToolsStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"CoreToolsStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SYSTEM_STATIC

#endif // TCRE_USE_MSVC

#endif // CORE_TOOLS_LIB_H