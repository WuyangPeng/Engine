///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 11:18)

#include "WinSocketHostNetConversionTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsSockEx.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WinSocketHostNetConversionTesting::WinSocketHostNetConversionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WinSocketHostNetConversionTesting)

void System::WinSocketHostNetConversionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WinSocketHostNetConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShortTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LongTest);
}

void System::WinSocketHostNetConversionTesting::ShortTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoShortTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketHostNetConversionTesting::LongTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoLongTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::WinSocketHostNetConversionTesting::DoShortTest(WinSocket socketHandle)
{
    constexpr uint16_t oldHostShort{ 1250 };
    uint16_t oldNetShort{ 0 };
    ASSERT_TRUE(WinSocketHostToNetShort(socketHandle, oldHostShort, &oldNetShort));

    uint16_t newHostShort{ 0 };
    ASSERT_TRUE(WinSocketNetToHostShort(socketHandle, oldNetShort, &newHostShort));

    ASSERT_EQUAL(oldHostShort, newHostShort);

    uint16_t newNetShort{ 0 };
    ASSERT_TRUE(WinSocketHostToNetShort(socketHandle, newHostShort, &newNetShort));

    ASSERT_EQUAL(oldNetShort, newNetShort);
}

void System::WinSocketHostNetConversionTesting::DoLongTest(WinSocket socketHandle)
{
    constexpr unsigned long oldHostLong{ 12500000 };
    unsigned long oldNetLong{ 0 };
    ASSERT_TRUE(WinSocketHostToNetLong(socketHandle, oldHostLong, &oldNetLong));

    unsigned long newHostLong{ 0 };
    ASSERT_TRUE(WinSocketNetToHostLong(socketHandle, oldNetLong, &newHostLong));

    ASSERT_EQUAL(oldHostLong, newHostLong);

    unsigned long newNetLong{ 0 };
    ASSERT_TRUE(WinSocketHostToNetLong(socketHandle, newHostLong, &newNetLong));

    ASSERT_EQUAL(oldNetLong, newNetLong);
}
