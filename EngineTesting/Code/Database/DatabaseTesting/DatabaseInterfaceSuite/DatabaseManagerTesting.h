///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:29)

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