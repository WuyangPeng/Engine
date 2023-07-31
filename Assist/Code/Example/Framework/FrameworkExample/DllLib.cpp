///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 13:46)

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
