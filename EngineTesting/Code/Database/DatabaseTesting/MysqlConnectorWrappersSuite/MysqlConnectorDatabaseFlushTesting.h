///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 16:28)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_DATABASE_FLUSH_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_DATABASE_FLUSH_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class MysqlConnectorDatabaseFlushTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MysqlConnectorDatabaseFlushTesting;
        using ParentType = UnitTest;

    public:
        explicit MysqlConnectorDatabaseFlushTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ChangeDatabaseTest();
        void DeleteDatabaseTest();
        void SelectOneTest();
        void SelectAllTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_DATABASE_FLUSH_TESTING_H