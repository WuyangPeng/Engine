///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:03)

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
        using AcceptFunction = bool (ClassType::*)(const TestingTypeSharedPtr& sockAcceptor);

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void SynchronizeAcceptTest();

        void SynchronizeAccept1Test();
        void SynchronizeAccept2Test();
        void SynchronizeAccept3Test();
        void SynchronizeAccept4Test();
        void SynchronizeAccept5Test();
        void SynchronizeAccept6Test();

        void SynchronizeAccept(const TestingTypeSharedPtr& sockAcceptor, AcceptFunction acceptFunction);

        NODISCARD bool SynchronizeAcceptNoUseAddress(const TestingTypeSharedPtr& sockAcceptor);
        NODISCARD bool SynchronizeAcceptUseAddress(const TestingTypeSharedPtr& sockAcceptor);
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_SYNCHRONIZE_TESTING_H