/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/14 21:00)

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