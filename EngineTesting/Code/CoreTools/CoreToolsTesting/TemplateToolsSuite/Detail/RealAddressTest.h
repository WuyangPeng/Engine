// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 15:36)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H

namespace CoreTools
{
    struct RealAddressTestAddress;

    struct RealAddressTest
    {
        RealAddressTestAddress* operator&() noexcept;
        const RealAddressTestAddress* operator&() const noexcept;
        volatile RealAddressTestAddress* operator&() volatile noexcept;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_REAL_ADDRESS_TEST_H
