// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.0 (2020/04/04 15:34)

#ifndef BOOK_DATABASE_LIB_H
#define BOOK_DATABASE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_DATABASE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookDatabaseD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookDatabase.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_DATABASE_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BookDatabaseStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookDatabaseStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_DATABASE_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_DATABASE_LIB_H
