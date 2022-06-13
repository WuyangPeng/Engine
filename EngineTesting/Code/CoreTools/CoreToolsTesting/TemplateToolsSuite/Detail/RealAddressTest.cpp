///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 18:55)

#include "RealAddressTest.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

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