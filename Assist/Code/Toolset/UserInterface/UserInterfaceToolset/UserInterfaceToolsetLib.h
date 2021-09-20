// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/08 21:34)

#ifndef USER_INTERFACE_TOOLSET_LIB_H
#define USER_INTERFACE_TOOLSET_LIB_H

#include "UserInterface/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_USER_INTERFACE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_USER_INTERFACE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "UserInterface/UserInterfaceLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_USER_INTERFACE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // USER_INTERFACE_TOOLSET_LIB_H
