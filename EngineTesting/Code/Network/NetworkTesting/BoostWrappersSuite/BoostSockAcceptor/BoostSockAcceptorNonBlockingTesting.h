///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:34)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
    class BoostSockAcceptorNonBlockingTesting : public BoostSockAcceptorTesting
    {
    public:
        using ClassType = BoostSockAcceptorNonBlockingTesting;
        using ParentType = BoostSockAcceptorTesting;

    public:
        explicit BoostSockAcceptorNonBlockingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using AcceptFunction = bool (ClassType::*)(TestingType& sockAcceptor);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void NonBlockingTest();

        void NonBlocking0Test();
        void NonBlocking1Test();
        void NonBlocking2Test();
        void NonBlocking3Test();
        void NonBlocking4Test();
        void NonBlocking5Test();

        void NonBlockingAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction);

        NODISCARD bool NonBlockingAcceptNoUseAddress(TestingType& sockAcceptor);
        NODISCARD bool NonBlockingAcceptUseAddress(TestingType& sockAcceptor);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H