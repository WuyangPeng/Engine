///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:37)

#include "NetworkUniqueIDManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkUniqueIDManagerTesting)

void Network::NetworkUniqueIDManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetNextUniqueIDTest);
}

void Network::NetworkUniqueIDManagerTesting::GetNextUniqueIDTest() noexcept
{
}
