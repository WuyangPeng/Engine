///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 14:50)

#include "Example/InputOutput/InputOutputExample/InputOutputExampleExport.h"

#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Example/InputOutput/InputOutputExample/InputOutputExampleFwd.h"

#ifndef BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

DLL_MAIN_FUNCTION(InputOutputExample);

#else  // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

CORE_TOOLS_MUTEX_INIT(InputOutputExample);

#endif  // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC
