// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/07 22:19)

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetExport.h"

#include "Toolset/Rendering/RenderingToolset/RenderingToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RENDERING_STATIC

	DLL_MAIN_FUNCTION(Rendering);

#else // !BUILDING_RENDERING_STATIC

	CORE_TOOLS_MUTEX_INIT(Rendering);

#endif // !BUILDING_RENDERING_STATIC
