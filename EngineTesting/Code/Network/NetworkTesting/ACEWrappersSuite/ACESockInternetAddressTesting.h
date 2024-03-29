///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:56)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INTERNET_ADDRESS_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INTERNET_ADDRESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACESockInternetAddressTesting final : public SingletonTesting
    {
    public:
        using ClassType = ACESockInternetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACESockInternetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void AddressTest();
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INTERNET_ADDRESS_TESTING_H