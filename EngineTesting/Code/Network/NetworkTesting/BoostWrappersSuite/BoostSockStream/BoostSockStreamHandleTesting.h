///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 14:29)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H

#include "Network/NetworkTesting/BoostWrappersSuite/BoostSockStreamTesting.h"

namespace Network
{
    class BoostSockStreamHandleTesting final : public BoostSockStreamTesting
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

        void ClientConnectTest(const TestingTypeSharedPtr& sockStream);
        void ServerAcceptor(TestingType& sockStream);

        void ACESockStreamExceptionTest();
        void NetworkSockStreamExceptionTest();

        void ACEHandleExceptionTest();
        void SetACEHandleExceptionTest();
        void SetNetworkHandleExceptionTest();
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_STREAM_HANDLE_TESTING_H