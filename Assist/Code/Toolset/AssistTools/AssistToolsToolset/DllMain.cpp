///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:37)

#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/AssistTools/AssistToolsToolset/AssistToolsToolsetFwd.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

DLL_MAIN_FUNCTION(AssistTools);

#else  // !BUILDING_ASSIST_TOOLS_STATIC

CORE_TOOLS_MUTEX_INIT(AssistTools);

#endif  // !BUILDING_ASSIST_TOOLS_STATIC
