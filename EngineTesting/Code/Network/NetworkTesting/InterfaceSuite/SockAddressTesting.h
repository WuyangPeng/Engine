///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 09:53)

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