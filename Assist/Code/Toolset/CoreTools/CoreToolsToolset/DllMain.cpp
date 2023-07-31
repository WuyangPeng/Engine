///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:51)

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetFwd.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

DLL_MAIN_FUNCTION(CoreTools);

#else  // !BUILDING_CORE_TOOLS_STATIC

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !BUILDING_CORE_TOOLS_STATIC
