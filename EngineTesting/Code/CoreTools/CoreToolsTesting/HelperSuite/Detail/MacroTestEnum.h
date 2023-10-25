///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 15:34)

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