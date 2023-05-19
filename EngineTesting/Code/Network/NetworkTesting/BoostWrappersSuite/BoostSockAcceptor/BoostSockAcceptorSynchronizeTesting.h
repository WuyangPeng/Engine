///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 13:34)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
    class BoostSockAcceptorSynchronizeTesting : public BoostSockAcceptorTesting
    {
    public:
        using ClassType = BoostSockAcceptorSynchronizeTesting;
        using ParentType = BoostSockAcceptorTesting;

    public:
        explicit BoostSockAcceptorSynchronizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using AcceptFunction = bool (ClassType::*)(TestingType& sockAcceptor);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void SynchronizeAcceptTest();

        void SynchronizeAccept0Test();
        void SynchronizeAccept1Test();
        void SynchronizeAccept2Test();
        void SynchronizeAccept3Test();
        void SynchronizeAccept4Test();
        void SynchronizeAccept5Test();

        void SynchronizeAccept(TestingType& sockAcceptor, AcceptFunction acceptFunction);

        NODISCARD bool SynchronizeAcceptNoUseAddress(TestingType& sockAcceptor);
        NODISCARD bool SynchronizeAcceptUseAddress(TestingType& sockAcceptor);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H