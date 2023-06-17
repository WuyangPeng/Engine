///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:27)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetFwd.h"

#include "CoreTools/Helper/MainFunctionMacro.h"

#ifndef BUILDING_FRAMEWORK_STATIC

DLL_MAIN_FUNCTION(FrameworkToolset);

#else  // !BUILDING_FRAMEWORK_STATIC

CORE_TOOLS_MUTEX_INIT(FrameworkToolset);

#endif  // !BUILDING_FRAMEWORK_STATIC
