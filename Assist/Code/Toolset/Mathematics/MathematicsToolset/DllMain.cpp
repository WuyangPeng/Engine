// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú°æ±¾£º0.0.2.0 (2020/01/05 17:36)

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetExport.h"

#include "Toolset/Mathematics/MathematicsToolset/MathematicsToolsetFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_MATHEMATICS_STATIC

	DLL_MAIN_FUNCTION(Mathematics);

#else // !BUILDING_MATHEMATICS_STATIC

	CORE_TOOLS_MUTEX_INIT(Mathematics);

#endif // !BUILDING_MATHEMATICS_STATIC