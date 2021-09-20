// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 1:20)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "Toolset/Network/NetworkToolset/NetworkToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_NETWORK_STATIC

	DLL_MAIN_FUNCTION(Network);

#else // !BUILDING_NETWORK_STATIC

	CORE_TOOLS_MUTEX_INIT(Network);

#endif // !BUILDING_NETWORK_STATIC
