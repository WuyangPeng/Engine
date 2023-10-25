///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:33)

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