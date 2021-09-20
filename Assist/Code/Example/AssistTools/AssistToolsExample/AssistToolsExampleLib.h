// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.2 (2020/01/27 14:59)

#ifndef ASSIST_TOOLS_EXAMPLE_LIB_H
#define ASSIST_TOOLS_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistToolsExample.lib")
		#endif // _DEBUG

	#else // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistToolsExampleStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ASSIST_TOOLS_EXAMPLE_LIB_H
