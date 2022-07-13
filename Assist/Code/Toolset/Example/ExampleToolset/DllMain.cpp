///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/04 11:43)

#include "Toolset/Example/ExampleToolset/ExampleToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/Example/ExampleToolset/ExampleToolsetFwd.h"

#ifndef BUILDING_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(Example);

#else  // !BUILDING_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(Example);

#endif  // !BUILDING_EXAMPLE_STATIC
