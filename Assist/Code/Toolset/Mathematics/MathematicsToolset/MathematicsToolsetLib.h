// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 17:36)

#ifndef MATHEMATICS_TOOLSET_LIB_H
#define MATHEMATICS_TOOLSET_LIB_H

#include "Mathematics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MATHEMATICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MathematicsToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_MATHEMATICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Mathematics/MathematicsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"MathematicsToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MathematicsToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MATHEMATICS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MATHEMATICS_TOOLSET_LIB_H
