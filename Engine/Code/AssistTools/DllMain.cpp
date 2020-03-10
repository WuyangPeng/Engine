// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/07/31 10:49)

#include "AssistTools/AssistToolsExport.h"

#include "AssistTools/AssistToolsFwd.h" 

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

	DLL_MAIN_FUNCTION(AssistTools);

#else // !BUILDING_ASSIST_TOOLS_STATIC

	CORE_TOOLS_MUTEX_INIT(AssistTools);

#endif // !BUILDING_ASSIST_TOOLS_STATIC