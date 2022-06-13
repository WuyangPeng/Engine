///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:59)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
    class SockAddressTesting : public SingletonTesting
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

        void ACEGetACEInetAddressTest();
        void ACEGetBoostInetAddressExceptionTest();
        void ACEGetNetworkInetAddressExceptionTest();

        void BoostGetACEInetAddressExceptionTest();
        void BoostGetBoostInetAddressTest();
        void BoostGetNetworkInetAddressExceptionTest();

        void NetworkGetACEInetAddressExceptionTest();
        void NetworkGetBoostInetAddressExceptionTest();
        void NetworkGetNetworkInetAddressTest();

        void NullGetACEInetAddressExceptionTest();
        void NullGetBoostInetAddressExceptionTest();
        void NullGetNetworkInetAddressExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ADDRESS_TESTING_H