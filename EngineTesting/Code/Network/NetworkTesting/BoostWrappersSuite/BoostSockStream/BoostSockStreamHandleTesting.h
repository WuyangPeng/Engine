///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:23)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSockStreamHandleTesting : public BoostSockStreamTesting
    {
    public:
        using ClassType = BoostSockStreamHandleTesting;
        using ParentType = BoostSockStreamTesting;

    public:
        explicit BoostSockStreamHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;

        void MainTest() noexcept;

        void StreamTest();

        void StreamInformationTest();

        void ClientTest();
        void ServerTest();

        void ClientConnect1(const TestingTypeSharedPtr& sockStream);
        void ServerAcceptor(const TestingTypeSharedPtr& sockStream);

        void ACESockStreamExceptionTest();
        void NetworkSockStreamExceptionTest();

        void ACEHandleExceptionTest();
        void SetACEHandleExceptionTest();
        void SetNetworkHandleExceptionTest();
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H