// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/06 14:19)

#ifndef BOOK_GEOMETRY_LIB_H
#define BOOK_GEOMETRY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_BOOK_GEOMETRY_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"BookGeometryD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookGeometry.lib")
		#endif // _DEBUG

	#else // !BUILDING_BOOK_GEOMETRY_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"BookGeometryStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"BookGeometryStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_BOOK_GEOMETRY_STATIC

#endif // TCRE_USE_MSVC 

#endif // BOOK_GEOMETRY_LIB_H
