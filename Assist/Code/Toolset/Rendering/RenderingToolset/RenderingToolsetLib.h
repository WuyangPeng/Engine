// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.2.0 (2020/01/07 22:19)

#ifndef RENDERING_TOOLSET_LIB_H
#define RENDERING_TOOLSET_LIB_H

#include "Rendering/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC) 

	#ifndef BUILDING_RENDERING_STATIC

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingToolsetD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RenderingToolset.lib")
		#endif // _DEBUG

	#else // !BUILDING_RENDERING_STATIC

		#include "DllLib.h"
		#include "System/SystemLib.h"
		#include "CoreTools/CoreToolsLib.h"
		#include "Rendering/RenderingLib.h"

		#ifdef _DEBUG 
			#pragma comment(lib,"RenderingToolsetStaticD.lib")
		#else // !_DEBUG
			#pragma comment(lib,"RenderingToolsetStatic.lib")
		#endif // _DEBUG

	#endif // BUILDING_RENDERING_STATIC

#endif // TCRE_USE_MSVC  
 
#endif // RENDERING_TOOLSET_LIB_H
