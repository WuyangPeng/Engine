///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:16)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_TABLE_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_TABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class TableTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TableTesting;
        using ParentType = UnitTest;

    public:
        explicit TableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void NullTableTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_TABLE_TESTING_H