// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/07 22:19)

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetExport.h"

#include "Toolset/Rendering/RenderingToolset/RenderingToolset.h"

#include "CoreTools/CoreToolsLib.h"
#include "Rendering/RenderingLib.h"

#ifndef BUILDING_RENDERING_STATIC

	#include "DllLib.h"

#else // BUILDING_RENDERING_STATIC

	namespace RenderingToolset
	{
		void StaticDllLib()
		{
			
		}
	}

#endif // !BUILDING_RENDERING_STATIC
