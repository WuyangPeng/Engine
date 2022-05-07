///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 11:16)

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