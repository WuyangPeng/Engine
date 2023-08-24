///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/14 16:26)

#ifndef DATABASE_TESTING_TESTING_HELPER_H
#define DATABASE_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

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
        void AddStatementSuite();
        void AddMysqlWrappersSuite();
        void AddMysqlConnectorWrappersSuite();
        void AddMysqlBoostWrappersSuite();
        void AddSqlServerWrappersSuite();
        void AddSQLiteWrappersSuite();
        void AddPostgreSQLSuite();
        void AddOracleSuite();
        void AddFlatFileWrappersSuite();
        void AddMariaDbWrappersSuite();
        void AddMongoWrappersSuite();
        void AddRedisWrappersSuite();
        void AddDatabaseEntityCodeGenerationSuite();
    };
}

#endif  // DATABASE_TESTING_TESTING_HELPER_H