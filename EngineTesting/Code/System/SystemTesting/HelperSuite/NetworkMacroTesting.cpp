///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 09:53)

#include "NetworkMacroTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define BUILDING_SYSTEM_EXPORT

#include "System/Helper/NetworkMacro.h"

System::NetworkMacroTesting::NetworkMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, NetworkMacroTesting)

void System::NetworkMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::NetworkMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StartUp);

    ASSERT_NOT_THROW_EXCEPTION_0(FdTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::NetworkMacroTesting::FdTest()
{
    const auto socketHandle = CreateWinSocket();

    ASSERT_NOT_THROW_EXCEPTION_1(FdSetTest, socketHandle);

    ASSERT_TRUE(CloseSocket(socketHandle));
}

void System::NetworkMacroTesting::StartUp()
{
    WinSockData wsaData{};
    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::NetworkMacroTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}

System::WinSocket System::NetworkMacroTesting::CreateWinSocket()
{
    constexpr uint16_t port{ 5300 };

    WinSockInternetAddress address{};
    address.sin_family = System::EnumCastUnderlying<uint16_t>(AddressFamilies::Internet);
    address.sin_port = GetHostToNetShort(port);
    address.sin_addr.s_addr = GetHostToNetLong(internetAddrAny);

    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "socketHandle 是无效的。");

    return socketHandle;
}

void System::NetworkMacroTesting::FdSetTest(WinSocket winSocket)
{
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    WinSockFdSet winSockFdSet{};

    SYSTEM_FD_SET(winSocket, &winSockFdSet);
    ASSERT_EQUAL(winSockFdSet.fd_count, 1u);
    ASSERT_UNEQUAL(SYSTEM_FD_IS_SET(winSocket, &winSockFdSet), 0);

    SYSTEM_FD_CLEAR(winSocket, &winSockFdSet);
    ASSERT_EQUAL(winSockFdSet.fd_count, 0u);
    ASSERT_EQUAL(SYSTEM_FD_IS_SET(winSocket, &winSockFdSet), 0);

    SYSTEM_FD_SET(winSocket, &winSockFdSet);
    ASSERT_EQUAL(winSockFdSet.fd_count, 1u);

    SYSTEM_FD_ZERO(&winSockFdSet);
    ASSERT_EQUAL(winSockFdSet.fd_count, 0u);

#include SYSTEM_WARNING_POP
}
