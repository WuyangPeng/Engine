// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/21 21:31)

#ifndef SCRIPT_EDITOR_LIB_H
#define SCRIPT_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCRIPT_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCRIPT_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ScriptEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ScriptEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCRIPT_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SCRIPT_EDITOR_LIB_H
