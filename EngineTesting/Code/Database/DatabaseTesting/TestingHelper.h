///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/25 14:04)

#ifndef DATABASE_TESTING_TESTING_HELPER_H
#define DATABASE_TESTING_TESTING_HELPER_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Database
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddHelperSuite();
        void AddConfigurationSuite();
        void AddDatabaseInterfaceSuite();
        void AddDatabaseGenerateSuite();
        void AddStatementSuite();
        void AddMysqlWrappersSuite();
        void AddMysqlConnectorWrappersSuite();
        void AddMysqlBoostWrappersSuite();
        void AddSqlServerWrappersSuite();
        void AddSQLiteWrappersSuite();
        void AddPostgreSQLSuite();
        void AddOracleSuite();
        void AddFlatFileWrappersSuite();
        void AddMariaDBWrappersSuite();
        void AddMongoWrappersSuite();
        void AddRedisWrappersSuite();
    };
}

#endif  // DATABASE_TESTING_TESTING_HELPER_H