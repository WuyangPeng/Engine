///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 11:11)

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