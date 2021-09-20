// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:26)

#include "BoostSockAcceptorNonBlockingTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

using std::make_shared;
using std::thread;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockAcceptorNonBlockingTesting)

void Network::BoostSockAcceptorNonBlockingTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::BoostSockAcceptorNonBlockingTesting ::AcceptorTest()
{
    thread serverThread{ &ClassType::BoostServerThread, this };

    const auto loopCount = GetTestLoopCount();
    for (auto loop = 0; loop < loopCount; ++loop)
    {
        ASSERT_NOT_THROW_EXCEPTION_0(NonBlockingTest);
        ASSERT_NOT_THROW_EXCEPTION_0(ClearOffset);
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    serverThread.join();
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlockingTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking5Test);
    ASSERT_NOT_THROW_EXCEPTION_0(NonBlocking6Test);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking1Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking2Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking3Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptNoUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking4Test()
{
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking5Test()
{
    const auto hostName = GetHostName();
    const auto port = GetRealPort();

    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlocking6Test()
{
    TestingTypeSharedPtr sockAcceptor{ make_shared<TestingType>(GetBoostServerConfigurationStrategy(GetRealOffset())) };
    ASSERT_NOT_THROW_EXCEPTION_2(NonBlockingAccept, sockAcceptor, &ClassType::NonBlockingAcceptUseAddress);
    ASSERT_NOT_THROW_EXCEPTION_0(AddOffset);
}

void Network::BoostSockAcceptorNonBlockingTesting ::NonBlockingAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction)
{
    [[maybe_unused]] auto value = sockAcceptor->EnableNonBlock();

    thread clientThread{ &ClassType::ClientThread, this };

    constexpr auto acceptTime = GetSynchronizeAcceptTime();
    for (auto i = 0; i < acceptTime; ++i)
    {
        if ((this->*acceptFunction)(sockAcceptor))
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }

    clientThread.join();
}

bool Network::BoostSockAcceptorNonBlockingTesting ::NonBlockingAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };

    return sockAcceptor->Accept(sockStream);
}

bool Network::BoostSockAcceptorNonBlockingTesting ::NonBlockingAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor)
{
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy) };

    return sockAcceptor->Accept(sockStream, sockAddress);
}
