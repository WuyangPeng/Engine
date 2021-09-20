// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.1 (2020/01/12 21:16)

#ifndef USER_INTERFACE_EDITOR_LIB_H
#define USER_INTERFACE_EDITOR_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_USER_INTERFACE_EDITOR_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceEditorAssistD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceEditorAssist.lib")
		#endif // _DEBUG

	#else // !BUILDING_USER_INTERFACE_EDITOR_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"UserInterfaceEditorAssistStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"UserInterfaceEditorAssistStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_USER_INTERFACE_EDITOR_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // USER_INTERFACE_EDITOR_LIB_H
