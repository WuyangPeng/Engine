///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 13:54)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_UNIQUE_ID_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_UNIQUE_ID_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class NetworkUniqueIDManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = NetworkUniqueIDManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit NetworkUniqueIDManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GetNextUniqueIDTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_NETWORK_UNIQUE_ID_MANAGER_TESTING_H