///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/03 22:14)

#include "WinSocketHostNetConversionTesting.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::WinSocketHostNetConversionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShortTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LongTest);
}

void System::WinSocketHostNetConversionTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::WinSocketHostNetConversionTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

void System::WinSocketHostNetConversionTesting::ShortTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    constexpr uint16_t hostShort{ 1250 };
    uint16_t netShort{ 0 };
    ASSERT_TRUE(WinSocketHtons(socketHandle, hostShort, &netShort));

    uint16_t newHostShort{ 0 };
    ASSERT_TRUE(WinSocketNtohs(socketHandle, netShort, &newHostShort));

    ASSERT_EQUAL(hostShort, newHostShort);

    uint16_t newNetShort{ 0 };
    ASSERT_TRUE(WinSocketHtons(socketHandle, newHostShort, &newNetShort));

    ASSERT_EQUAL(netShort, newNetShort);
}

void System::WinSocketHostNetConversionTesting::LongTest()
{
    const auto socketHandle = GetWinSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp, nullptr, 0, 0);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    constexpr unsigned long hostLong{ 12500000 };
    unsigned long netLong{ 0 };
    ASSERT_TRUE(WinSocketHtonl(socketHandle, hostLong, &netLong));

    unsigned long newHostLong{ 0 };
    ASSERT_TRUE(WinSocketNtohl(socketHandle, netLong, &newHostLong));

    ASSERT_EQUAL(hostLong, newHostLong);

    unsigned long newNetLong{ 0 };
    ASSERT_TRUE(WinSocketHtonl(socketHandle, newHostLong, &newNetLong));

    ASSERT_EQUAL(netLong, newNetLong);
}
