// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/21 21:00)

#ifndef LEVEL_EDITOR_LIB_H
#define LEVEL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_LEVEL_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"LevelEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LevelEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_LEVEL_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"LevelEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"LevelEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_LEVEL_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // LEVEL_EDITOR_LIB_H
