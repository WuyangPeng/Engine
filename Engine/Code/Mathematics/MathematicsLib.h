// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 15:00)

#ifndef MATHEMATICS_LIB_H
#define MATHEMATICS_LIB_H

#include "Macro/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MATHEMATICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Mathematics.lib")
		#endif // _DEBUG

	#else // !BUILDING_MATHEMATICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MathematicsStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MATHEMATICS_STATIC

#endif // TCRE_USE_MSVC

#endif // MATHEMATICS_LIB_H