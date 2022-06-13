///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 16:33)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BoostSockInetAddressTesting : public SingletonTesting
    {
    public:
        using ClassType = BoostSockInetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BoostSockInetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        using TestingType = SockAddress;
        using TestingTypeSharedPtr = std::shared_ptr<SockAddress>;

    private:
        void MainTest();

        void AddressTest();

        void Address1Test();
        void Address2Test();
        void Address3Test();

        void ACEAddressExceptionTest();
        void WinSocketAddressExceptionTest();

        void CopyConstructorTest(const SockAddressSharedPtr& sockAddress);
        void CopyOperatorTest(const SockAddressSharedPtr& sockAddress);

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H