// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/17 0:04)

#ifndef ANIMATION_EDITOR_LIB_H
#define ANIMATION_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_ANIMATION_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_ANIMATION_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"AnimationEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"AnimationEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_ANIMATION_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // ANIMATION_EDITOR_LIB_H
