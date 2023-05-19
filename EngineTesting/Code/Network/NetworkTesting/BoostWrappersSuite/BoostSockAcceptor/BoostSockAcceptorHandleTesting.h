///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 13:33)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockAcceptorTesting.h"

namespace Network
{
    class BoostSockAcceptorHandleTesting : public BoostSockAcceptorTesting
    {
    public:
        using ClassType = BoostSockAcceptorHandleTesting;
        using ParentType = BoostSockAcceptorTesting;

    public:
        explicit BoostSockAcceptorHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void AcceptorTest();

        void AcceptorInformationTest();
        void ACEHandleExceptionTest();
        void WinSocketExceptionTest();

    private:
        int increase;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_ACCEPTOR_HANDLE_TESTING_H