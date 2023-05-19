///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:32)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"

namespace Network
{
    class BoostSockAcceptorAsynchronousTesting final : public BoostSockAcceptorTesting
    {
    public:
        using ClassType = BoostSockAcceptorAsynchronousTesting;
        using ParentType = BoostSockAcceptorTesting;

    public:
        explicit BoostSockAcceptorAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using AcceptFunction = void (ClassType::*)(TestingType& sockAcceptor, const TestSocketEventSharedPtr& testSocketManager);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void AsynchronousAcceptTest();

        void AsynchronousAccept0Test();
        void AsynchronousAccept1Test();
        void AsynchronousAccept2Test();
        void AsynchronousAccept3Test();
        void AsynchronousAccept4Test();
        void AsynchronousAccept5Test();

        void AsynchronousAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction);

        void AsynchronousAcceptNoUseAddress(TestingType& sockAcceptor, const TestSocketEventSharedPtr& testSocketManager);
        void AsynchronousAcceptUseAddress(TestingType& sockAcceptor, const TestSocketEventSharedPtr& testSocketManager);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H