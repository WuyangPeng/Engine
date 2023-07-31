///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:51)

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetFwd.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

DLL_MAIN_FUNCTION(CoreTools);

#else  // !BUILDING_CORE_TOOLS_STATIC

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !BUILDING_CORE_TOOLS_STATIC
