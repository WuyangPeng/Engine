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
        CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper);

        virtual int DoRun() override;

    private:
        void AddSuites();

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

    private:
        CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
    };
}

#endif  // DATABASE_TESTING_TESTING_HELPER_H