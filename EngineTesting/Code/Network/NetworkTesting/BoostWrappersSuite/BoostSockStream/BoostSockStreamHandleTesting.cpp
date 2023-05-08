///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 13:48)

#include "BoostSockStreamHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <thread>

using std::make_shared;
using std::thread;
using std::to_string;

Network::BoostSockStreamHandleTesting::BoostSockStreamHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockStreamHandleTesting)

void Network::BoostSockStreamHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockStreamHandleTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::BoostSockStreamHandleTesting::StreamTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(StreamInformationTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    ASSERT_THROW_EXCEPTION_0(ACESockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkSockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(SetNetworkHandleExceptionTest);

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockStreamHandleTesting::StreamInformationTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
}

void Network::BoostSockStreamHandleTesting::ClientTest()
{
    thread serverThread{ &ClassType::ServerNoReceiveThread, this };

    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ClientConnect1, sockStream);

    serverThread.join();

    ASSERT_TRUE(sockStream->CloseHandle());

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockStreamHandleTesting::ClientConnect1(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    constexpr auto aConnectTime = GetSynchronizeConnectTime();
    for (auto i = 0; i < aConnectTime; ++i)
    {
        SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

        SockConnector sockConnector{ configurationStrategy };

        if (sockConnector.Connect(sockStream, sockAddress))
        {
            MAYBE_UNUSED const auto value = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aConnectTime, "连接服务器失败。");
    }

    ASSERT_EQUAL(configurationStrategy.GetHost() + ":" + to_string(configurationStrategy.GetPort()), sockStream->GetRemoteAddress());
    ASSERT_EQUAL(configurationStrategy.GetPort(), sockStream->GetRemotePort());

    const auto& nativeHandle = sockStream->GetBoostSockStream();
    ASSERT_TRUE(nativeHandle.is_open());
}

void Network::BoostSockStreamHandleTesting::ServerTest()
{
    thread clientThread{ &ClassType::ClientNoSendThread, this };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerAcceptor, sockStream);

    clientThread.join();

    ASSERT_TRUE(sockStream->CloseHandle());

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockStreamHandleTesting::ServerAcceptor(const TestingTypeSharedPtr& sockStream)
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    SockAcceptorSharedPtr sockAcceptor{ make_shared<SockAcceptor>(configurationStrategy) };

#include STSTEM_WARNING_POP

    constexpr auto aAcceptTime = GetSynchronizeAcceptTime();
    for (auto i = 0; i < aAcceptTime; ++i)
    {
        if (sockAcceptor->Accept(*sockStream))
        {
            MAYBE_UNUSED const auto value = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, aAcceptTime, "等待客户端连接失败。");
    }

    ASSERT_EQUAL(configurationStrategy.GetHost() + ":" + to_string(sockStream->GetRemotePort()), sockStream->GetRemoteAddress());
    ASSERT_UNEQUAL(configurationStrategy.GetPort(), sockStream->GetRemotePort());

    const auto& nativeHandle = sockStream->GetBoostSockStream();
    ASSERT_TRUE(nativeHandle.is_open());
}

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

void Network::BoostSockStreamHandleTesting::ACESockStreamExceptionTest()
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    MAYBE_UNUSED auto value = sockStream->GetACESockStream();
}

void Network::BoostSockStreamHandleTesting::NetworkSockStreamExceptionTest()
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    MAYBE_UNUSED const auto value = sockStream->GetNetworkSockStream();
}

void Network::BoostSockStreamHandleTesting::ACEHandleExceptionTest()
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    MAYBE_UNUSED auto value = sockStream->GetACEHandle();
}

void Network::BoostSockStreamHandleTesting::SetACEHandleExceptionTest()
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    sockStream->SetACEHandle(0);
}

void Network::BoostSockStreamHandleTesting::SetNetworkHandleExceptionTest()
{
    auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingTypeSharedPtr sockStream{ make_shared<TestingType>(configurationStrategy) };

    sockStream->SetNetworkHandle(0);
}

#include STSTEM_WARNING_POP
