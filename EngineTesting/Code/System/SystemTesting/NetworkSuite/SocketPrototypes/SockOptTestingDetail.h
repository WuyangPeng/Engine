///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 16:39)

#ifndef SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_DETAIL_H
#define SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_DETAIL_H

#include "SockOptTesting.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptTesting::SetAndGetSockOptTest()
{
    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    Option optVal{};
    int optLen{ sizeof(Option) };

    ASSERT_TRUE(GetSockOpt(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<char*>(&optVal), &optLen));

    ASSERT_TRUE(SetSockOpt(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<const char*>(&optVal), sizeof(Option)));

    ASSERT_TRUE(CloseSocket(socketHandle));
}

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptTesting::GetSockOptTest()
{
    const auto socketHandle = GetSocket(ProtocolFamilies::Inet, SocketTypes::Stream, SocketProtocols::Tcp);
    ASSERT_TRUE(IsSocketValid(socketHandle));

    Option optVal{};
    int optLen{ sizeof(Option) };

    ASSERT_TRUE(GetSockOpt(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<char*>(&optVal), &optLen));

    ASSERT_TRUE(CloseSocket(socketHandle));
}

#endif  // SYSTEM_SECURITY_SUITE_SOCK_OPT_TESTING_DETAIL_H