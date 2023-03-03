///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.3 (2023/03/02 11:25)

#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/CoreTools/CoreToolsToolset/CoreToolsToolsetFwd.h"

#ifndef BUILDING_CORE_TOOLS_STATIC

DLL_MAIN_FUNCTION(CoreTools);

#else  // !BUILDING_CORE_TOOLS_STATIC

CORE_TOOLS_MUTEX_INIT(CoreTools);

#endif  // !BUILDING_CORE_TOOLS_STATIC
