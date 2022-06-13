///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:41)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H

#include "System/Helper/UserMacro.h"

namespace CoreTools
{
    struct RealAddressTestAddress;

    struct RealAddressTest
    {
        NODISCARD RealAddressTestAddress* operator&() noexcept;
        NODISCARD const RealAddressTestAddress* operator&() const noexcept;
        NODISCARD volatile RealAddressTestAddress* operator&() volatile noexcept;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H
