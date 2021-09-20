// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/03 21:49)

#ifndef USER_INFO_LIB_H
#define USER_INFO_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_USER_INFO_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInfoD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInfo.lib")
		#endif // _DEBUG

	#else // !BUILDING_USER_INFO_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInfoStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInfoStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_USER_INFO_STATIC

#endif // TCRE_USE_MSVC 

#endif // USER_INFO_LIB_H
