///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/26 09:17)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_ENTITY_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_ENTITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class DatabaseEntityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseEntityTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseEntityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;

        void FieldNameContainerTest();
        void SelectTest();
        void DeleteTest();
        void ChangeTypeTest();
        void ModifyTest();
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_ENTITY_TESTING_H