///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 16:50)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_CONNECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkSockConnectorTesting final : public SingletonTesting
    {
    public:
        using ClassType = NetworkSockConnectorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit NetworkSockConnectorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void ConnectorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_CONNECTOR_TESTING_H