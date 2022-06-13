///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:58)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_SOCK_CONNECTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkSockConnectorTesting : public SingletonTesting
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