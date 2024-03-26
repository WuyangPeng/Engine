/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:21)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Toolset/System/SystemToolset/SystemToolsetFwd.h"

#ifndef BUILDING_SYSTEM_TOOLSET_STATIC

DLL_MAIN_FUNCTION(SystemToolset);

#else  // !BUILDING_SYSTEM_TOOLSET_STATIC

CORE_TOOLS_MUTEX_INIT(SystemToolset);

#endif  // !BUILDING_SYSTEM_TOOLSET_STATIC
