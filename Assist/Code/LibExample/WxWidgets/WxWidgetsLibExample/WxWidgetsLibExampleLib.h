// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 15:02)

#ifndef WX_WIDGETS_LIB_EXAMPLE_LIB_H
#define WX_WIDGETS_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef  BUILDING_WX_WIDGETS_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"WxWidgetsLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WxWidgetsLibExample.lib")
		#endif // _DEBUG

	#else // !WX_WIDGETS_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"WxWidgetsLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"WxWidgetsLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // WX_WIDGETS_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // WX_WIDGETS_LIB_EXAMPLE_LIB_H
