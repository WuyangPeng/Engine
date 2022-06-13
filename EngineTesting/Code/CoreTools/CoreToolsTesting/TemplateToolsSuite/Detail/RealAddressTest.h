///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 18:41)

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
