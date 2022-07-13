///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 17:11)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/System/SystemToolset/SystemToolsetFwd.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

DLL_MAIN_FUNCTION(SystemToolset);

#else  // BUILDING_SYSTEM_TOOLSET_STATIC

CORE_TOOLS_MUTEX_INIT(SystemToolset);

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
