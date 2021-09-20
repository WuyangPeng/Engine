// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/07 22:44)

#ifndef IMAGICS_TOOLSET_LIB_H
#define IMAGICS_TOOLSET_LIB_H

#include "Imagics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_IMAGICS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ImagicsToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_IMAGICS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Imagics/ImagicsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"ImagicsToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ImagicsToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_IMAGICS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // IMAGICS_TOOLSET_LIB_H
