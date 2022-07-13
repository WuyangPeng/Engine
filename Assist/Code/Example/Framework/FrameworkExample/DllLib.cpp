///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 11:51)

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
