// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 14:39)

#ifndef INPUT_OUTPUT_LIB_H
#define INPUT_OUTPUT_LIB_H

#include "Macro/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_INPUT_OUTPUT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutput.lib")
		#endif // _DEBUG

	#else // !BUILDING_INPUT_OUTPUT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutputStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_INPUT_OUTPUT_STATIC

#endif // TCRE_USE_MSVC  

#endif // INPUT_OUTPUT_LIB_H