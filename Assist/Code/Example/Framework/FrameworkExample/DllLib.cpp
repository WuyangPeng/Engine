///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/12 11:51)

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
