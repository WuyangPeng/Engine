///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 16:03)

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
        using AcceptFunction = bool (ClassType::*)(const TestingTypeSharedPtr& sockAcceptor);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void NonBlockingTest();

        void NonBlocking1Test();
        void NonBlocking2Test();
        void NonBlocking3Test();
        void NonBlocking4Test();
        void NonBlocking5Test();
        void NonBlocking6Test();

        void NonBlockingAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

        NODISCARD bool NonBlockingAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor);
        NODISCARD bool NonBlockingAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_NON_BLOCKING_TESTING_H