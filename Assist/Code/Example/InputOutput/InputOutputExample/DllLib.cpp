///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 11:31)

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
