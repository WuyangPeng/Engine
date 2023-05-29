///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/26 15:36)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_BASIS_DATABASE_MANAGER_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_BASIS_DATABASE_MANAGER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class BasisDatabaseManagerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BasisDatabaseManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit BasisDatabaseManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void BasisTest();
        void GetAnyValueTest();
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_BASIS_DATABASE_MANAGER_TESTING_H