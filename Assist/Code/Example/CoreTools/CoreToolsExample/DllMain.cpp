/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:43)

#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleFwd.h"

#ifndef BUILDING_CORE_TOOLS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(CoreToolsExample);

#else  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(CoreToolsExample);

#endif  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC
