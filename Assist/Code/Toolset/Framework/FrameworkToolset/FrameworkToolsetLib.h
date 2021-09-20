// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/20 21:08)

#ifndef FRAMEWORK_TOOLSET_LIB_H
#define FRAMEWORK_TOOLSET_LIB_H

#include "Framework/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FRAMEWORK_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_FRAMEWORK_STATIC

		#include "DllLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FRAMEWORK_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FRAMEWORK_TOOLSET_LIB_H
