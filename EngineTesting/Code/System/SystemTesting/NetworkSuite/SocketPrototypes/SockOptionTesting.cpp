///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 11:03)

#include "SockOptionTestingDetail.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/Using/WindowsSockExUsing.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SockOptionTesting::SockOptionTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SockOptionTesting)

void System::SockOptionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::SockOptionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SockOptionTest);
}

void System::SockOptionTesting::SockOptionTest()
{
    GetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::AcceptConn, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::ConditionalAccept, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::Debug, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::DontLinger, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::DontRoute, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::Error, int>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::ExclusiveAddrUse, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::KeepAlive, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::Linger, SocketLinger>();
    GetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::MaxMsgSize, unsigned int>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::OobinLine, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::PortScalability, WindowsBool>();
    GetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::ProtocolInfo, SocketProtocolInfo>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::RcvBuf, int>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::ReuseAddr, WindowsBool>();
    SetAndGetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::SndBuf, int>();
    GetSockOptionTest<SocketLevelOption::Socket, SocketRetrievedOption::Type, int>();
    SetAndGetSockOptionTest<SocketLevelOption::IpProtoTcp, SocketRetrievedOption::TcpNoDelay, WindowsBool>();
}
