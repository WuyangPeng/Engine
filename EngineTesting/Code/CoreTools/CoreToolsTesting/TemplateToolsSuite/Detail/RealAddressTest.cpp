///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:33)

#include "RealAddressTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest::operator&() noexcept
{
    return nullptr;
}

const CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest::operator&() const noexcept
{
    return nullptr;
}

volatile CoreTools::RealAddressTestAddress* CoreTools::RealAddressTest::operator&() volatile noexcept
{
    return nullptr;
}