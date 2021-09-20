// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.1.0 (2019/11/06 09:42)

#ifndef BOOK_GAME_PROGRAMMING_LIB_H
#define BOOK_GAME_PROGRAMMING_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_GAME_PROGRAMMING_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookGameProgrammingD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookGameProgramming.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_GAME_PROGRAMMING_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BookGameProgrammingStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookGameProgrammingStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_GAME_PROGRAMMING_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_GAME_PROGRAMMING_LIB_H
