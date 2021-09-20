// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/05 19:04)

#ifndef INPUT_OUTPUT_TOOLSET_LIB_H
#define INPUT_OUTPUT_TOOLSET_LIB_H

#include "InputOutput/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_INPUT_OUTPUT_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutputToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_INPUT_OUTPUT_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "InputOutput/InputOutputLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"InputOutputToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"InputOutputToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_INPUT_OUTPUT_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // INPUT_OUTPUT_TOOLSET_LIB_H
