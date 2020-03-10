// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2017
//
// “˝«Ê∞Ê±æ£∫1.0.0.0 (2017/11/22 10:42)

#ifndef FRAMEWORK_LIB_H
#define FRAMEWORK_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FRAMEWORK_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Framework.lib")
		#endif // _DEBUG

	#else // !BUILDING_FRAMEWORK_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"FrameworkStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FrameworkStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FRAMEWORK_STATIC

#endif // TCRE_USE_MSVC  

#endif // FRAMEWORK_LIB_H
