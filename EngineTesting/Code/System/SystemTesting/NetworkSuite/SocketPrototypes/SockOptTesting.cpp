///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:45)

#include "SockOptTestingDetail.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/Using/WindowsSockExUsing.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SockOptTesting::SockOptTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SockOptTesting)

void System::SockOptTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Init);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(Cleanup);
}

void System::SockOptTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SockOptTest);
}

void System::SockOptTesting::SockOptTest()
{
    GetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::AcceptConn, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::ConditionalAccept, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::Debug, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::DontLinger, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::DontRoute, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::Error, int>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::Exclusiveaddruse, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::KeepAlive, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::Linger, SocketLinger>();
    GetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::MaxMsgSize, unsigned int>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::OobinLine, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::PortScalability, WindowsBool>();
    GetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::ProtocolInfo, SocketProtocolInfo>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::RcvBuf, int>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::ReuseAddr, WindowsBool>();
    SetAndGetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::SndBuf, int>();
    GetSockOptTest<SocketLevelOption::Socket, SocketRetrievedOption::Type, int>();
    SetAndGetSockOptTest<SocketLevelOption::IpprotoTcp, SocketRetrievedOption::TcpNodelay, WindowsBool>();
}

void System::SockOptTesting::Init()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);
}

void System::SockOptTesting::Cleanup()
{
    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}
