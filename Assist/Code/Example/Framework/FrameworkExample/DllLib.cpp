///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 14:56)

#include "Example/Framework/FrameworkExample/FrameworkExampleExport.h"

#include "Example/Framework/FrameworkExample/FrameworkExample.h"

#ifndef BUILDING_FRAMEWORK_EXAMPLE_STATIC

    #include "DllLib.h"

#else  // BUILDING_FRAMEWORK_EXAMPLE_STATIC

namespace FrameworkExample
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_FRAMEWORK_EXAMPLE_STATIC
