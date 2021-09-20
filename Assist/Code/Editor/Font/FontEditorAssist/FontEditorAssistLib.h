// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/19 23:52)

#ifndef FONT_EDITOR_LIB_H
#define FONT_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_FONT_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"FontEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FontEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_FONT_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"FontEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"FontEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_FONT_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // FONT_EDITOR_LIB_H
