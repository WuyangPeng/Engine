///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:21)

#include "AssistTools/AssistToolsExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "AssistTools/AssistToolsFwd.h"

#ifndef BUILDING_ASSIST_TOOLS_STATIC

DLL_MAIN_FUNCTION(AssistTools);

#else  // !BUILDING_ASSIST_TOOLS_STATIC

CORE_TOOLS_MUTEX_INIT(AssistTools);

#endif  // !BUILDING_ASSIST_TOOLS_STATIC