///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 11:44)

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
