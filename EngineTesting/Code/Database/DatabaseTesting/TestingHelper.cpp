///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:13)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Database::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "数据库"s }
{
    InitSuite();

    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, TestingHelper)

void Database::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddConfigurationSuite();
    AddSqlInterfaceSuite();
    AddStatementSuite();
    AddMysqlWrappersSuite();
    AddMysqlConnectorWrappersSuite();
    AddSqlServerWrappersSuite();
    AddSQLiteWrappersSuite();
    AddPostgreSQLSuite();
    AddOracleSuite();
    AddFlatFileWrappersSuite();
}

void Database::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("帮助");

    ADD_TEST(helperSuite, UserMacroTesting);

    AddSuite(helperSuite);
}

void Database::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("配置");

    ADD_TEST(configurationSuite, ConfigurationStrategyTesting);
    ADD_TEST(configurationSuite, AnalysisDatabaseConfigurationTesting);

    AddSuite(configurationSuite);
}

void Database::TestingHelper::AddSqlInterfaceSuite()
{
    auto sqlInterfaceSuite = GenerateSuite("Sql接口");

    ADD_TEST(sqlInterfaceSuite, DatabaseObjectTesting);
    ADD_TEST(sqlInterfaceSuite, SessionTesting);
    ADD_TEST(sqlInterfaceSuite, SchemaTesting);
    ADD_TEST(sqlInterfaceSuite, CollectionTesting);
    ADD_TEST(sqlInterfaceSuite, TableTesting);
    ADD_TEST(sqlInterfaceSuite, ResultTesting);
    ADD_TEST(sqlInterfaceSuite, ResultRowTesting);

    AddSuite(sqlInterfaceSuite);
}

void Database::TestingHelper::AddStatementSuite()
{
    auto statementSuite = GenerateSuite("语句");

    AddSuite(statementSuite);
}

void Database::TestingHelper::AddMysqlWrappersSuite()
{
    auto mysqlWrappersSuite = GenerateSuite("Mysql 包装器");

    AddSuite(mysqlWrappersSuite);
}

void Database::TestingHelper::AddMysqlConnectorWrappersSuite()
{
    auto mysqlConnectorWrappersSuite = GenerateSuite("Mysql Connector 包装器");

    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDatabaseObjectTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorSessionTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorSchemaTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorCollectionTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDocResultTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDocResultRowTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorTableTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorResultTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorResultRowTesting);

    AddSuite(mysqlConnectorWrappersSuite);
}

void Database::TestingHelper::AddSqlServerWrappersSuite()
{
    auto sqlServerWrappersSuite = GenerateSuite("Sql Server 包装器");

    AddSuite(sqlServerWrappersSuite);
}

void Database::TestingHelper::AddSQLiteWrappersSuite()
{
    auto sQLiteWrappersSuite = GenerateSuite("SQLite 包装器");

    AddSuite(sQLiteWrappersSuite);
}

void Database::TestingHelper::AddPostgreSQLSuite()
{
    auto postgreSQLSuite = GenerateSuite("PostgreSQL 包装器");

    AddSuite(postgreSQLSuite);
}

void Database::TestingHelper::AddOracleSuite()
{
    auto oracleSuite = GenerateSuite("Oracle 包装器");

    AddSuite(oracleSuite);
}

void Database::TestingHelper::AddFlatFileWrappersSuite()
{
    auto flatFileWrappersSuite = GenerateSuite("平面文件包装器");

    AddSuite(flatFileWrappersSuite);
}
