///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 16:00)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

namespace Network
{
    class BoostSockAcceptorAsynchronousTesting : public BoostSockAcceptorTesting
    {
    public:
        using ClassType = BoostSockAcceptorAsynchronousTesting;
        using ParentType = BoostSockAcceptorTesting;

    public:
        explicit BoostSockAcceptorAsynchronousTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using AcceptFunction = void (ClassType::*)(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void AsynchronousAcceptTest();

        void AsynchronousAccept1Test();
        void AsynchronousAccept2Test();
        void AsynchronousAccept3Test();
        void AsynchronousAccept4Test();
        void AsynchronousAccept5Test();
        void AsynchronousAccept6Test();

        void AsynchronousAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

        void AsynchronousAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);
        void AsynchronousAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor, const TestSocketManagerSharedPtr& testSocketManager);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_ASYNCHRONOUS_TESTING_H