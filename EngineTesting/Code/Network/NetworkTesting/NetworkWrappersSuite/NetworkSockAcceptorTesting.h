///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:58)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkSockAcceptorTesting : public SingletonTesting
    {
    public:
        using ClassType = NetworkSockAcceptorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit NetworkSockAcceptorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest() noexcept;

        void AcceptorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_ACCEPTOR_TESTING_H