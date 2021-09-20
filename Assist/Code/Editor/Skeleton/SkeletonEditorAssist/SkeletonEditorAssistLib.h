// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/20 22:47)

#ifndef SKELETON_EDITOR_LIB_H
#define SKELETON_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_SKELETON_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"SkeletonEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SkeletonEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_SKELETON_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"SkeletonEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"SkeletonEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_SKELETON_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // SKELETON_EDITOR_LIB_H
