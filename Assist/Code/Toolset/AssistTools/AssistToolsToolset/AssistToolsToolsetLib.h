// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/10 23:28)

#ifndef ASSIST_TOOLS_TOOLSET_LIB_H
#define ASSIST_TOOLS_TOOLSET_LIB_H

#include "AssistTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ASSIST_TOOLS_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistToolsToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_ASSIST_TOOLS_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "AssistTools/AssistToolsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"AssistToolsToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AssistToolsToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ASSIST_TOOLS_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ASSIST_TOOLS_TOOLSET_LIB_H
