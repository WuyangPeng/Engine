///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 14:50)

#include "Example/InputOutput/InputOutputExample/InputOutputExampleExport.h"

#include "Example/InputOutput/InputOutputExample/InputOutputExample.h"

#ifndef BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC

namespace InputOutputExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INPUT_OUTPUT_EXAMPLE_STATIC
