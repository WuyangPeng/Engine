///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 16:29)

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