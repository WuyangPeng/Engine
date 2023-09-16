///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:58)

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
    constexpr uint16_t oldHostShort{ 1250 };
    const auto oldNetShort = GetHostToNetShort(oldHostShort);

    const auto newHostShort = GetNetToHostShort(oldNetShort);

    ASSERT_EQUAL(oldHostShort, newHostShort);

    const auto newNetShort = GetHostToNetShort(newHostShort);

    ASSERT_EQUAL(oldNetShort, newNetShort);
}

void System::HostNetConversionTesting::LongTest()
{
    constexpr unsigned long oldHostLong{ 12500000 };
    const auto oldNetLong = GetHostToNetLong(oldHostLong);

    const auto newHostLong = GetNetToHostLong(oldNetLong);

    ASSERT_EQUAL(oldHostLong, newHostLong);

    const auto newNetLong = GetHostToNetLong(newHostLong);

    ASSERT_EQUAL(oldNetLong, newNetLong);
}
