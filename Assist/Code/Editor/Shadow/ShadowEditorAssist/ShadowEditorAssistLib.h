// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/14 23:32)

#ifndef SHADOW_EDITOR_LIB_H
#define SHADOW_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SHADOW_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ShadowEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ShadowEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_SHADOW_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ShadowEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ShadowEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SHADOW_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SHADOW_EDITOR_LIB_H
