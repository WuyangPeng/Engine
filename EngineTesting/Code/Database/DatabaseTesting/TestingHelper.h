// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 15:58)

#ifndef DATABASE_TESTING_TESTING_HELPER_H
#define DATABASE_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace Database
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
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
        void AddSqlInterfaceSuite();
        void AddStatementSuite();
        void AddMysqlWrappersSuite();
        void AddMysqlConnectorWrappersSuite();
        void AddSqlServerWrappersSuite();
        void AddSQLiteWrappersSuite();
        void AddPostgreSQLSuite();
        void AddOracleSuite();
        void AddFlatFileWrappersSuite();
    };
}

#endif  // DATABASE_TESTING_TESTING_HELPER_H