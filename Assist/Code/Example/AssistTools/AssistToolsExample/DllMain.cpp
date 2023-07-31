///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 13:55)

#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/AssistTools/AssistToolsExample/AssistToolsExampleFwd.h"

#ifndef BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(AssistToolsExample);

#else  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(AssistToolsExample);

#endif  // !BUILDING_ASSIST_TOOLS_EXAMPLE_STATIC
