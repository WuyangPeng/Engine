// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/13 23:43)

#ifndef SHADER_EDITOR_LIB_H
#define SHADER_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SHADER_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ShaderEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ShaderEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_SHADER_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ShaderEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ShaderEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SHADER_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SHADER_EDITOR_LIB_H
