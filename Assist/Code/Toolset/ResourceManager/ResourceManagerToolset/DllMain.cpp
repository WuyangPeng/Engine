// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 19:30)

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetExport.h"

#include "Toolset/ResourceManager/ResourceManagerToolset/ResourceManagerToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_RESOURCE_MANAGER_STATIC

	DLL_MAIN_FUNCTION(ResourceManager);

#else // !BUILDING_RESOURCE_MANAGER_STATIC

	CORE_TOOLS_MUTEX_INIT(ResourceManager);

#endif // !BUILDING_RESOURCE_MANAGER_STATIC
