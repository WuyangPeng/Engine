// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 21:16)

#ifndef TERRAIN_EDITOR_LIB_H
#define TERRAIN_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_TERRAIN_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"TerrainEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"TerrainEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_TERRAIN_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"TerrainEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"TerrainEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_TERRAIN_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // TERRAIN_EDITOR_LIB_H
