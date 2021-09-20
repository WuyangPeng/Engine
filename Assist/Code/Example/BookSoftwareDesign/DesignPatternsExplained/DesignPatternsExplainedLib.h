// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.3.0 (2020/03/24 23:23)

#ifndef DESIGN_PATTERNS_EXPLAINED_LIB_H
#define DESIGN_PATTERNS_EXPLAINED_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DesignPatternsExplainedD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DesignPatternsExplained.lib")
		#endif // _DEBUG

	#else // !BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"DesignPatternsExplainedStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DesignPatternsExplainedStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_DESIGN_PATTERNS_EXPLAINED_STATIC

#endif // TCRE_USE_MSVC 

#endif // DESIGN_PATTERNS_EXPLAINED_LIB_H
