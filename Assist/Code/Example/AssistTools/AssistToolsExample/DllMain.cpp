///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/11 19:05)

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleFwd.h"

#ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(AssistToolsExample);

#else  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(AssistToolsExample);

#endif  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC
