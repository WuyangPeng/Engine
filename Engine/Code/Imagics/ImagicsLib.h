// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/30 11:16)

#ifndef IMAGICS_LIB_H
#define IMAGICS_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_IMAGICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Imagics.lib")
		#endif // _DEBUG

	#else // !BUILDING_IMAGICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Mathematics/Mathematics.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ImagicsStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_IMAGICS_STATIC

#endif // TCRE_USE_MSVC   

#endif // IMAGICS_LIB_H