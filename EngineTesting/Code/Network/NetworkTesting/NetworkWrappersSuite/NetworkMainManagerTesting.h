///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 09:17)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_BASE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_BASE_MAIN_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class NetworkMainManagerTesting final : public SingletonTesting
    {
    public:
        using ClassType = NetworkMainManagerTesting;
        using ParentType = SingletonTesting;

    public:
        explicit NetworkMainManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void SingletonTest();

        void RunTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_BASE_MAIN_MANAGER_TESTING_H