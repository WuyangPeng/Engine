///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/02 13:39)

#include "InputOutput/InputOutputExport.h"

#include "InputOutput/InputOutput.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

    #include "DllLib.h"

#else  // BUILDING_INPUT_OUTPUT_STATIC

namespace InputOutput
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INPUT_OUTPUT_STATIC