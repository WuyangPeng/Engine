// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// Copyright (c) 2011-2017
//
// “˝«Ê∞Ê±æ£∫1.0.0.0 (2017/11/13 22:48)

#ifndef ASSIST_TOOLS_LIB_H
#define ASSIST_TOOLS_LIB_H

#include "Macro/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ASSIST_TOOLS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistTools.lib")
		#endif // _DEBUG

	#else // !BUILDING_ASSIST_TOOLS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistToolsStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ASSIST_TOOLS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ASSIST_TOOLS_LIB_H