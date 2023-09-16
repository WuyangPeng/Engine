///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:18)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INTERNET_ADDRESS_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INTERNET_ADDRESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkSockInternetAddressTesting final : public SingletonTesting
    {
    public:
        using ClassType = NetworkSockInternetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit NetworkSockInternetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void AddressTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INTERNET_ADDRESS_TESTING_H