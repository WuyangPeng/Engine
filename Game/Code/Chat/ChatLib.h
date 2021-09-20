// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê”Œœ∑∞Ê±æ£∫0.0.0.1 (2019/10/06 20:18)

#ifndef CHAT_LIB_H
#define CHAT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_CHAT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ChatD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Chat.lib")
		#endif // _DEBUG

	#else // !BUILDING_CHAT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ChatStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ChatStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_CHAT_STATIC

#endif // TCRE_USE_MSVC 

#endif // CHAT_LIB_H
