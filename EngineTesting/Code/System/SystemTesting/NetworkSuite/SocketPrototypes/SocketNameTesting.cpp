/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:14)

#include "SocketNameTesting.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SocketNameTesting::SocketNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SocketNameTesting)

void System::SocketNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::SocketNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SocketNameTest);
}

void System::SocketNameTesting::SocketNameTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "获取socket失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoSocketNameTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

void System::SocketNameTesting::DoSocketNameTest(WinSocket socketHandle)
{
    const auto address = GetAddress(defaultHttpPort, GetConnectHostname());
    ASSERT_TRUE(Connect(socketHandle, &address));

    const auto peerName = GetPeerNameTest(socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(GetSockNameTest, socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(InetNToATest, peerName);

    ASSERT_NOT_THROW_EXCEPTION_2(WinSockInternetAddressTest, address, peerName);
}

void System::SocketNameTesting::InetNToATest(const WinSockInternetAddress& peerName)
{
    const auto address = InetNToA(peerName.sin_addr);
    ASSERT_EQUAL(GetConnectHostname(), address);
}

void System::SocketNameTesting::WinSockInternetAddressTest(const WinSockInternetAddress& address, const WinSockInternetAddress& peerName)
{
    ASSERT_EQUAL(address.sin_family, peerName.sin_family);
    ASSERT_EQUAL(address.sin_port, peerName.sin_port);
    ASSERT_EQUAL(address.sin_addr.s_addr, peerName.sin_addr.s_addr);
}

System::WinSockInternetAddress System::SocketNameTesting::GetPeerNameTest(WinSocket socketHandle)
{
    WinSockInternetAddress peerName{};
    int peerNameSize{ sizeof(WinSockInternetAddress) };

    ASSERT_TRUE(GetPeerName(socketHandle, &peerName, &peerNameSize));

    return peerName;
}

void System::SocketNameTesting::GetSockNameTest(WinSocket socketHandle)
{
    WinSockInternetAddress sockName{};
    int sockNameSize{ sizeof(WinSockInternetAddress) };

    ASSERT_TRUE(GetSockName(socketHandle, &sockName, &sockNameSize));
}
