// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 19:05)

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetExport.h"

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

	DLL_MAIN_FUNCTION(InputOutput);

#else // !BUILDING_INPUT_OUTPUT_STATIC

	CORE_TOOLS_MUTEX_INIT(InputOutput);

#endif // !BUILDING_INPUT_OUTPUT_STATIC
