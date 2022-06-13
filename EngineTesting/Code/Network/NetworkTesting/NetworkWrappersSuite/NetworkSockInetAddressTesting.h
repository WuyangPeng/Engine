///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:58)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkSockInetAddressTesting : public SingletonTesting
    {
    public:
        using ClassType = NetworkSockInetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit NetworkSockInetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void AddressTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H