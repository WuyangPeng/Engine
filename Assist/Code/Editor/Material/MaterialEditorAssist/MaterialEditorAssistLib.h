// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/19 22:19)

#ifndef MATERIAL_EDITOR_LIB_H
#define MATERIAL_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_MATERIAL_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"MaterialEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MaterialEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_MATERIAL_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"MaterialEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"MaterialEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_MATERIAL_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // MATERIAL_EDITOR_LIB_H
