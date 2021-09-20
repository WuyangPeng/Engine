// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/18 20:50)

#ifndef MODEL_EDITOR_LIB_H
#define MODEL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MODEL_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"ModelEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ModelEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_MODEL_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"ModelEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"ModelEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MODEL_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MODEL_EDITOR_LIB_H
