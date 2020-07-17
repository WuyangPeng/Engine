// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/17 10:55)

#ifndef RENDERING_LIB_H
#define RENDERING_LIB_H

#include "Helper/UserMacro.h" 

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RENDERING_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"Rendering.lib")
		#endif // _DEBUG

	#else // !BUILDING_RENDERING_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Mathematics/MathematicsLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RenderingStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RENDERING_STATIC

#endif // TCRE_USE_MSVC   

#endif // RENDERING_LIB_H