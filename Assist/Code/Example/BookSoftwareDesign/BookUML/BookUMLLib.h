// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 17:51)

#ifndef BOOK_UML_LIB_H
#define BOOK_UML_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_UML_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookUMLD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookUML.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_UML_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BookUMLStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookUMLStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_UML_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_UML_LIB_H
