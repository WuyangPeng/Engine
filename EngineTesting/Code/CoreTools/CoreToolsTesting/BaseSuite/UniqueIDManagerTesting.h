///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/10 18:20)

#ifndef CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H
#define CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class UniqueIdManagerTesting final : public UnitTest
    {
    public:
        using ClassType = UniqueIdManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit UniqueIdManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void UniqueIdManagerTest();
        void SetUniqueIdTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_UNIQUE_ID_MANAGER_TESTING_H