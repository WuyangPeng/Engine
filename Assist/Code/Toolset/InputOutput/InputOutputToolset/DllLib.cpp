///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:43)

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolsetExport.h"

#include "Toolset/InputOutput/InputOutputToolset/InputOutputToolset.h"

#ifndef BUILDING_INPUT_OUTPUT_STATIC

    #include "DllLib.h"

#else  // BUILDING_INPUT_OUTPUT_STATIC

namespace InputOutputToolset
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_INPUT_OUTPUT_STATIC
