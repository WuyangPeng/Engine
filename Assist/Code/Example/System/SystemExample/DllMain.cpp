/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 19:10)

#include "Example/System/SystemExample/SystemExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/System/SystemExample/SystemExampleFwd.h"

#ifndef BUILDING_SYSTEM_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(SystemExample);

#else  // !BUILDING_SYSTEM_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(SystemExample);

#endif  // !BUILDING_SYSTEM_EXAMPLE_STATIC
