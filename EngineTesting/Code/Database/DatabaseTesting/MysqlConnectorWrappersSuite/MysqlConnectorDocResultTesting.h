///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:18)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_DOC_RESULT_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_DOC_RESULT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
    class MysqlConnectorDocResultTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MysqlConnectorDocResultTesting);

    private:
        void MainTest();

        void ResultTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_DOC_RESULT_TESTING_H