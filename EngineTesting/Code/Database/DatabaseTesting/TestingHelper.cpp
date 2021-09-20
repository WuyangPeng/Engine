// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.5 (2020/03/16 15:58)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

CMAIN_FUNCTION_HELPER_SUBCLASS_COMPLETE_DEFINE(Database, TestingHelper, "���ݿ�")

// private
void Database::TestingHelper ::AddSuites()
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

void Database::TestingHelper ::AddHelperSuite()
{
    ADD_TEST_BEGIN(helperSuite, "����");

    ADD_TEST(helperSuite, UserMacroTesting);

    ADD_TEST_END(helperSuite);
}

void Database::TestingHelper ::AddConfigurationSuite()
{
    ADD_TEST_BEGIN(configurationSuite, "����");

    ADD_TEST(configurationSuite, ConfigurationStrategyTesting);
    ADD_TEST(configurationSuite, AnalysisDatabaseConfigurationTesting);

    ADD_TEST_END(configurationSuite);
}

void Database::TestingHelper ::AddSqlInterfaceSuite()
{
    ADD_TEST_BEGIN(sqlInterfaceSuite, "Sql�ӿ�");

    ADD_TEST(sqlInterfaceSuite, DatabaseObjectTesting);
    ADD_TEST(sqlInterfaceSuite, SessionTesting);
    ADD_TEST(sqlInterfaceSuite, SchemaTesting);
    ADD_TEST(sqlInterfaceSuite, CollectionTesting);
    ADD_TEST(sqlInterfaceSuite, TableTesting);
    ADD_TEST(sqlInterfaceSuite, ResultTesting);
    ADD_TEST(sqlInterfaceSuite, ResultRowTesting);

    ADD_TEST_END(sqlInterfaceSuite);
}

void Database::TestingHelper ::AddStatementSuite()
{
    ADD_TEST_BEGIN(statementSuite, "���");

    ADD_TEST_END(statementSuite);
}

void Database::TestingHelper ::AddMysqlWrappersSuite()
{
    ADD_TEST_BEGIN(mysqlWrappersSuite, "Mysql ��װ��");

    ADD_TEST_END(mysqlWrappersSuite);
}

void Database::TestingHelper ::AddMysqlConnectorWrappersSuite()
{
    ADD_TEST_BEGIN(mysqlConnectorWrappersSuite, "Mysql Connector ��װ��");

    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDatabaseObjectTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorSessionTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorSchemaTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorCollectionTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDocResultTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDocResultRowTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorTableTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorResultTesting);
    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorResultRowTesting);

    ADD_TEST_END(mysqlConnectorWrappersSuite);
}

void Database::TestingHelper ::AddSqlServerWrappersSuite()
{
    ADD_TEST_BEGIN(sqlServerWrappersSuite, "Sql Server ��װ��");

    ADD_TEST_END(sqlServerWrappersSuite);
}

void Database::TestingHelper ::AddSQLiteWrappersSuite()
{
    ADD_TEST_BEGIN(sQLiteWrappersSuite, "SQLite ��װ��");

    ADD_TEST_END(sQLiteWrappersSuite);
}

void Database::TestingHelper ::AddPostgreSQLSuite()
{
    ADD_TEST_BEGIN(postgreSQLSuite, "PostgreSQL ��װ��");

    ADD_TEST_END(postgreSQLSuite);
}

void Database::TestingHelper ::AddOracleSuite()
{
    ADD_TEST_BEGIN(oracleSuite, "Oracle ��װ��");

    ADD_TEST_END(oracleSuite);
}

void Database::TestingHelper ::AddFlatFileWrappersSuite()
{
    ADD_TEST_BEGIN(flatFileWrappersSuite, "ƽ���ļ���װ��");

    ADD_TEST_END(flatFileWrappersSuite);
}
