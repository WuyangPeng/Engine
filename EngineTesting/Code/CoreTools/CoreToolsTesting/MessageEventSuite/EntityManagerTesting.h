///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/18 11:35)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EntityManagerTesting final : public UnitTest
    {
    public:
        using ClassType = EntityManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit EntityManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ManagerTest();
        void ManagerExceptionalTest(int64_t entityId);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H