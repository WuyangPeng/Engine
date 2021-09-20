// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/01 10:59)

#ifndef LUA_LIB_EXAMPLE_LIB_H
#define LUA_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_LUA_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"LuaLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LuaLibExample.lib")
		#endif // _DEBUG

	#else // !LUA_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"LuaLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LuaLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // LUA_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // LUA_LIB_EXAMPLE_LIB_H
