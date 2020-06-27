// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/17 10:56)

#ifndef SCRIPT_LIB_H
#define SCRIPT_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCRIPT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Script.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCRIPT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCRIPT_STATIC

#endif // TCRE_USE_MSVC  

#endif // SCRIPT_LIB_H