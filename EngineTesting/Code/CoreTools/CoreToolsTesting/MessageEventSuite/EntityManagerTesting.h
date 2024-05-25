/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 13:00)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H

#include "Detail/Entity.h"
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
        using EntitySharedPtr = Entity::EntitySharedPtr;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ManagerTest();
        void ManagerExceptionalTest(int64_t entityId);

        void GetEntityTest(const EntitySharedPtr& entity);
        void UnRegisterTest(const Entity& entity);
        void GetValueTest(const EntitySharedPtr& entity);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_ENTITY_MANAGER_TESTING_H