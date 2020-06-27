// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 10:15)

#ifndef SYSTEM_LIB_H
#define SYSTEM_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SYSTEM_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SystemD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"System.lib")
		#endif // _DEBUG

	#else // !BUILDING_SYSTEM_STATIC

		#include "DllLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"SystemStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SystemStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SYSTEM_STATIC

#endif // TCRE_USE_MSVC

#endif // SYSTEM_LIB_H