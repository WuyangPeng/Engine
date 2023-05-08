///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 14:16)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INET_ADDRESS_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INET_ADDRESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACESockInetAddressTesting : public SingletonTesting
    {
    public:
        using ClassType = ACESockInetAddressTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACESockInetAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void AddressTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_INET_ADDRESS_TESTING_H