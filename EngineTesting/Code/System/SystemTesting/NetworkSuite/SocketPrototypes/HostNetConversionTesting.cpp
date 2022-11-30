///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 22:17)

#include "HostNetConversionTesting.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::HostNetConversionTesting::HostNetConversionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, HostNetConversionTesting)

void System::HostNetConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::HostNetConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShortTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LongTest);
}

void System::HostNetConversionTesting::ShortTest()
{
    constexpr uint16_t hostShort{ 1250 };
    const auto netShort = GetHostToNetShort(hostShort);

    const auto newHostShort = GetNetToHostShort(netShort);

    ASSERT_EQUAL(hostShort, newHostShort);

    const auto newNetShort = GetHostToNetShort(newHostShort);

    ASSERT_EQUAL(netShort, newNetShort);
}

void System::HostNetConversionTesting::LongTest()
{
    constexpr unsigned long hostLong{ 12500000 };
    const auto netLong = GetHostToNetLong(hostLong);

    const auto newHostLong = GetNetToHostLong(netLong);

    ASSERT_EQUAL(hostLong, newHostLong);

    const auto newNetLong = GetHostToNetLong(newHostLong);

    ASSERT_EQUAL(netLong, newNetLong);
}
