///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/11 18:38)

#ifndef SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_DETAIL_H
#define SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_DETAIL_H

#include "SockOptionTesting.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptionTesting::SetAndGetSockOptionTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    DoSetAndGetSockOptionTest<LevelOption, RetrievedOption, Option>(socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptionTesting::GetSockOptionTest()
{
    const auto socketHandle = CreateTcpSocket();
    ASSERT_TRUE_FAILURE_THROW(IsSocketValid(socketHandle), "创建Tcp Socket失败。");

    DoGetSockOptionTest<LevelOption, RetrievedOption, Option>(socketHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseSocketTest, socketHandle);
}

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptionTesting::DoSetAndGetSockOptionTest(WinSocket socketHandle)
{
    Option option{};
    int optionLength{ sizeof(Option) };

    ASSERT_TRUE(GetSockOption(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<char*>(&option), &optionLength));

    ASSERT_TRUE(SetSockOption(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<const char*>(&option), sizeof(Option)));
}

template <System::SocketLevelOption LevelOption, System::SocketRetrievedOption RetrievedOption, typename Option>
void System::SockOptionTesting::DoGetSockOptionTest(WinSocket socketHandle)
{
    Option option{};
    int optionLength{ sizeof(Option) };

    ASSERT_TRUE(GetSockOption(socketHandle, LevelOption, RetrievedOption, reinterpret_cast<char*>(&option), &optionLength));
}

#endif  // SYSTEM_NETWORK_SUITE_SOCK_OPTION_TESTING_DETAIL_H