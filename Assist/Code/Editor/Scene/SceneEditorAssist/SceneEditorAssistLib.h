// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/15 21:43)

#ifndef SCENE_EDITOR_LIB_H
#define SCENE_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SCENE_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SceneEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SceneEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_SCENE_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"SceneEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SceneEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SCENE_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SCENE_EDITOR_LIB_H
