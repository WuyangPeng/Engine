// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/15 11:58)

#ifndef CORE_TOOLS_DLL_LIB_H
#define CORE_TOOLS_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifdef _DEBUG 
		#pragma comment(lib,"zlibd.lib")
		#pragma comment(lib,"freetyped.lib")
	#else // !_DEBUG
		#pragma comment(lib,"zlib.lib")
		#pragma comment(lib,"freetype.lib")
	#endif // _DEBUG	

#endif // TCRE_USE_MSVC

#endif // CORE_TOOLS_DLL_LIB_H