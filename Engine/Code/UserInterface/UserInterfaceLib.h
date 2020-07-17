// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 10:28)

#ifndef USER_INTERFACE_LIB_H
#define USER_INTERFACE_LIB_H 

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_USER_INTERFACE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterface.lib")
		#endif // _DEBUG

	#else // !BUILDING_USER_INTERFACE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_USER_INTERFACE_STATIC

#endif // TCRE_USE_MSVC   

#endif // USER_INTERFACE_LIB_H