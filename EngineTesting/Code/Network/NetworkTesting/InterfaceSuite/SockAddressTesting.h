///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:55)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H

#include "SingletonTesting.h"

namespace Network
{
    class SockAddressTesting final : public SingletonTesting
    {
    public:
        using ClassType = SockAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit SockAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void ACETest();
        void BoostTest();
        void NetworkTest();
        void NullTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
        void NullConstructionTest();

        void ACEGetACEInternetAddressTest();
        void ACEGetBoostInternetAddressExceptionTest();
        void ACEGetNetworkInternetAddressExceptionTest();

        void BoostGetACEInternetAddressExceptionTest();
        void BoostGetBoostInternetAddressTest();
        void BoostGetNetworkInternetAddressExceptionTest();

        void NetworkGetACEInternetAddressExceptionTest();
        void NetworkGetBoostInternetAddressExceptionTest();
        void NetworkGetNetworkInternetAddressTest();

        void NullGetACEInternetAddressExceptionTest();
        void NullGetBoostInternetAddressExceptionTest();
        void NullGetNetworkInternetAddressExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H