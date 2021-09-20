// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/16 0:07)

#ifndef EFFECT_EDITOR_LIB_H
#define EFFECT_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_EFFECT_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"EffectEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"EffectEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_EFFECT_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"EffectEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"EffectEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_EFFECT_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // EFFECT_EDITOR_LIB_H
