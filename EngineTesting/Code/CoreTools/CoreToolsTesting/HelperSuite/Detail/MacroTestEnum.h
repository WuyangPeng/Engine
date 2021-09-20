///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/07/30 16:00)

#ifndef CORE_TOOLS_HELPER_SUITE_MACRO_TEST_ENUM_H
#define CORE_TOOLS_HELPER_SUITE_MACRO_TEST_ENUM_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
    enum class MacroTestEnum : uint32_t
    {
        One = 1,
        Two,
    };

    enum class MacroTestSignedEnum
    {
        NegativeOne = -1,
        Zero = 0,
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_MACRO_TEST_ENUM_H