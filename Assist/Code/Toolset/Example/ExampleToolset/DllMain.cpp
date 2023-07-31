///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:38)

#include "Toolset/Example/ExampleToolset/ExampleToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Example/ExampleToolset/ExampleToolsetFwd.h"

#ifndef BUILDING_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(Example);

#else  // !BUILDING_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(Example);

#endif  // !BUILDING_EXAMPLE_STATIC
