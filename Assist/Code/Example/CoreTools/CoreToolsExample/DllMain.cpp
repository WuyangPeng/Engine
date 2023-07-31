///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:53)

#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/CoreTools/CoreToolsExample/CoreToolsExampleFwd.h"

#ifndef BUILDING_CORE_TOOLS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(CoreToolsExample);

#else  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(CoreToolsExample);

#endif  // !BUILDING_CORE_TOOLS_EXAMPLE_STATIC
