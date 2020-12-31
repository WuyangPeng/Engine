// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/20 0:08)

#ifndef FRAMEWORK_LIB_H
#define FRAMEWORK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FRAMEWORK_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Framework.lib")
		#endif // _DEBUG

	#else // !BUILDING_FRAMEWORK_STATIC

		#include "DllLib.h"  

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FRAMEWORK_STATIC

#endif // TCRE_USE_MSVC  

#endif // FRAMEWORK_LIB_H
