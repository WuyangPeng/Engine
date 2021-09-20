// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 1:24)

#ifndef EDITOR_TOOLSET_LIB_H
#define EDITOR_TOOLSET_LIB_H

#include "Macro/Macro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"EditorToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"EditorToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"EditorToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"EditorToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // EDITOR_TOOLSET_LIB_H
