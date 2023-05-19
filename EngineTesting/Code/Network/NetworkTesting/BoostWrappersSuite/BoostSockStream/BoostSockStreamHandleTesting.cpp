///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 16:40)

#include "BoostSockStreamHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

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
    std::thread serverThread{ &ClassType::BoostServerThread, this };

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
    std::thread serverThread{ &ClassType::ServerNoReceiveThread, this };

    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    const auto sockStream = std::make_shared<TestingType>(configurationStrategy);

    ASSERT_NOT_THROW_EXCEPTION_1(ClientConnectTest, sockStream);

    serverThread.join();

    ASSERT_TRUE(sockStream->CloseHandle());

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockStreamHandleTesting::ClientConnectTest(const TestingTypeSharedPtr& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    constexpr auto connectCount = GetSynchronizeConnectTime();
    for (auto i = 0; i < connectCount; ++i)
    {
        const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

        if (SockConnector sockConnector{ configurationStrategy };
            sockConnector.Connect(sockStream, sockAddress))
        {
            MAYBE_UNUSED const auto result = sockStream->EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectCount, "连接服务器失败。");
    }

    ASSERT_EQUAL(configurationStrategy.GetHost() + ":" + std::to_string(configurationStrategy.GetPort()), sockStream->GetRemoteAddress());
    ASSERT_EQUAL(configurationStrategy.GetPort(), sockStream->GetRemotePort());

    const auto& nativeHandle = sockStream->GetBoostSockStream();
    ASSERT_TRUE(nativeHandle.is_open());
}

void Network::BoostSockStreamHandleTesting::ServerTest()
{
    std::thread clientThread{ &ClassType::ClientNoSendThread, this };

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    ASSERT_NOT_THROW_EXCEPTION_1(ServerAcceptor, sockStream);

    clientThread.join();

    ASSERT_TRUE(sockStream.CloseHandle());

    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockStreamHandleTesting::ServerAcceptor(TestingType& sockStream)
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockAcceptor sockAcceptor{ configurationStrategy };

    constexpr auto acceptCount = GetSynchronizeAcceptTime();
    for (auto i = 0; i < acceptCount; ++i)
    {
        if (sockAcceptor.Accept(sockStream))
        {
            MAYBE_UNUSED const auto result = sockStream.EnableNonBlock();
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, acceptCount, "等待客户端连接失败。");
    }

    ASSERT_EQUAL(configurationStrategy.GetHost() + ":" + std::to_string(sockStream.GetRemotePort()), sockStream.GetRemoteAddress());
    ASSERT_UNEQUAL(configurationStrategy.GetPort(), sockStream.GetRemotePort());

    const auto& nativeHandle = sockStream.GetBoostSockStream();
    ASSERT_TRUE(nativeHandle.is_open());
}

void Network::BoostSockStreamHandleTesting::ACESockStreamExceptionTest()
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    MAYBE_UNUSED const auto result = sockStream.GetACESockStream();
}

void Network::BoostSockStreamHandleTesting::NetworkSockStreamExceptionTest()
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    MAYBE_UNUSED const auto result = sockStream.GetNetworkSockStream();
}

void Network::BoostSockStreamHandleTesting::ACEHandleExceptionTest()
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    MAYBE_UNUSED const auto result = sockStream.GetACEHandle();
}

void Network::BoostSockStreamHandleTesting::SetACEHandleExceptionTest()
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    sockStream.SetACEHandle(nullptr);
}

void Network::BoostSockStreamHandleTesting::SetNetworkHandleExceptionTest()
{
    const auto configurationStrategy = GetBoostFixedClientConfigurationStrategy(GetRealOffset());
    TestingType sockStream{ configurationStrategy };

    sockStream.SetNetworkHandle(0);
}
