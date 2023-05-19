///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:31)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INTERNET_ADDRESS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INTERNET_ADDRESS_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BoostSockInternetAddressTesting final : public SingletonTesting
    {
    public:
        using ClassType = BoostSockInternetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostSockInternetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using TestingType = SockAddress;
        using TestingTypeSharedPtr = std::shared_ptr<SockAddress>;

    private:
        void MainTest();

        void AddressTest();

        void Address0Test();
        void Address1Test();
        void Address2Test();

        void ACEAddressExceptionTest();
        void WinSocketAddressExceptionTest();

        void CopyConstructorTest(const SockAddress& sockAddress);
        void CopyOperatorTest(const SockAddress& sockAddress);

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INTERNET_ADDRESS_TESTING_H