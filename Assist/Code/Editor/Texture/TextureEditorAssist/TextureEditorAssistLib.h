// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.1 (2020/01/18 23:43)

#ifndef TEXTURE_EDITOR_LIB_H
#define TEXTURE_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_TEXTURE_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"TextureEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"TextureEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_TEXTURE_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"TextureEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"TextureEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_TEXTURE_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // TEXTURE_EDITOR_LIB_H
