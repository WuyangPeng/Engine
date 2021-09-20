// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 11:49)

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetExport.h"

#include "Toolset/Database/DatabaseToolset/DatabaseToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_DATABASE_STATIC

	DLL_MAIN_FUNCTION(Database);

#else // !BUILDING_DATABASE_STATIC

	CORE_TOOLS_MUTEX_INIT(Database);

#endif // !BUILDING_DATABASE_STATIC
