// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/07 10:12)

#ifndef SYSTEM_DLL_LIB_H
#define SYSTEM_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#pragma comment(lib,"Ws2_32.lib")
	#pragma comment(lib,"Dbghelp.lib")
	#pragma comment(lib,"Wininet.lib")		

	#if !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)
		#pragma comment(lib,"opengl32.lib")
	#endif // SYSTEM_USE_GLUT

#endif // TCRE_USE_MSVC

#endif // SYSTEM_DLL_LIB_H