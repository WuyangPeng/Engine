///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 17:11)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/System/SystemToolset/SystemToolsetFwd.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

DLL_MAIN_FUNCTION(SystemToolset);

#else  // BUILDING_SYSTEM_TOOLSET_STATIC

CORE_TOOLS_MUTEX_INIT(SystemToolset);

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
