// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2019/12/31 14:53)

#ifndef SYSTEM_DLL_LIB_H
#define SYSTEM_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#pragma comment(lib,"Ws2_32.lib")
	#pragma comment(lib,"Dbghelp.lib")
	#pragma comment(lib,"Wininet.lib")		

	#if !defined(SYSTEM_USE_GLUT)
		#pragma comment(lib,"opengl32.lib")
	#endif // SYSTEM_USE_GLUT

#endif // TCRE_USE_MSVC

#endif // SYSTEM_DLL_LIB_H