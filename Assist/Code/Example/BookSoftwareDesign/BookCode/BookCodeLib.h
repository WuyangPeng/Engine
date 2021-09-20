// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.3 (2020/04/27 23:58)

#ifndef BOOK_CODE_LIB_H
#define BOOK_CODE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_CODE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookCodeD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookCode.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_CODE_STATIC

		#include "DllLib.h"  

		#ifdef _DEBUG 
			#pragma comment(lib,"BookCodeStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookCodeStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_CODE_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_CODE_LIB_H
