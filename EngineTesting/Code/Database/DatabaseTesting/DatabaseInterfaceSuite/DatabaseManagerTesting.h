///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/26 13:41)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_MANAGER_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Database/DatabaseInterface/DatabaseManager.h"

namespace Database
{
    class DatabaseManagerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DatabaseManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit DatabaseManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SelectOneTest();
        void DeleteTest();
        void SelectAllTest();
        void DeleteAllTest();
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_DATABASE_MANAGER_TESTING_H