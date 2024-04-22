/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 22:40)

#ifndef CORE_TOOLS_FILE_MANAGER_CHECK_ITEM_SIZE_H
#define CORE_TOOLS_FILE_MANAGER_CHECK_ITEM_SIZE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/Tools.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"

namespace CoreTools
{
    template <typename T>
    constexpr void CheckItemSize(T itemSize) noexcept requires(gAssert < 2 && gCoreToolsAssert < 2)
    {
        System::UnusedFunction(itemSize);
    }

    template <typename T>
    void CheckItemSize(T itemSize) requires(2 <= gAssert || 2 <= gCoreToolsAssert)
    {
        CORE_TOOLS_ASSERTION_2(itemSize == 1 || itemSize == 2 || itemSize == 4 || itemSize == 8, "大小必须为1，2，4或8\n");
    }
}

#endif  // CORE_TOOLS_FILE_MANAGER_CHECK_ITEM_SIZE_H
