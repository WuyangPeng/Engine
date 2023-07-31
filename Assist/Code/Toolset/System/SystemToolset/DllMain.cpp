///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:18)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/System/SystemToolset/SystemToolsetFwd.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

DLL_MAIN_FUNCTION(SystemToolset);

#else  // !BUILDING_SYSTEM_TOOLSET_STATIC

CORE_TOOLS_MUTEX_INIT(SystemToolset);

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
