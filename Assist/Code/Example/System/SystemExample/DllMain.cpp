///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.0 (2021/07/17 11:37)

#include "Example/System/SystemExample/SystemExampleExport.h"

#include "Example/System/SystemExample/SystemExampleFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_SYSTEM_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(SystemExample);

#else  // !BUILDING_SYSTEM_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(SystemExample);

#endif  // !BUILDING_SYSTEM_EXAMPLE_STATIC
