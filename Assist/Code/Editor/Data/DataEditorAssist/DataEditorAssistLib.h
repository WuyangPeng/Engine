// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/16 21:10)

#ifndef DATA_EDITOR_LIB_H
#define DATA_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_DATA_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"DataEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DataEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_DATA_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"DataEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"DataEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_DATA_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // DATA_EDITOR_LIB_H
