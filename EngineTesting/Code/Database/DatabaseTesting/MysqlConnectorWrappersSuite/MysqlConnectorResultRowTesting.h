///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:18)

#ifndef DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_ROW_TESTING_H
#define DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_ROW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Database
{
    class MysqlConnectorResultRowTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MysqlConnectorResultRowTesting;
        using ParentType = UnitTest;

    public:
        explicit MysqlConnectorResultRowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void ResultRowTest();

        void DoRunUnitTest() override;
    };
}

#endif  // DATABASE_TESTING_DATABASE_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_ROW_TESTING_H