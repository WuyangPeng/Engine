// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.3 (2019/10/02 14:28)

#ifndef VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_LIB_H
#define VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"VisualLeakDetectorLibExampleD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"VisualLeakDetectorLibExample.lib")
		#endif // _DEBUG

	#else // !VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h" 

		#ifdef _DEBUG 
			#pragma comment(lib,"VisualLeakDetectorLibExampleStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"VisualLeakDetectorLibExampleStatic.lib")
		#endif // _DEBUG

	#endif // VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // VISUAL_LEAK_DETECTOR_LIB_EXAMPLE_LIB_H
