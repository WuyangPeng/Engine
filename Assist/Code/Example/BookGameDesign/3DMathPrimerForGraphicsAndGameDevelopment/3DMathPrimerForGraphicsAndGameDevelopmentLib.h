// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/07 21:09)

#ifndef THREE_D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_LIB_H
#define THREE_D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"3DMathPrimerForGraphicsAndGameDevelopmentD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"3DMathPrimerForGraphicsAndGameDevelopment.lib")
		#endif // _DEBUG

	#else // !BUILDING_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_STATIC

		#include "DllLib.h" 
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"3DMathPrimerForGraphicsAndGameDevelopmentStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"3DMathPrimerForGraphicsAndGameDevelopmentStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_3D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_STATIC

#endif // TCRE_USE_MSVC 

#endif // THREE_D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_LIB_H
