///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:13)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"

using namespace std::literals;

Database::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���ݿ�"s }
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
    auto helperSuite = GenerateSuite("����");

    ADD_TEST(helperSuite, UserMacroTesting);

    AddSuite(helperSuite);
}

void Database::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("����");

    ADD_TEST(configurationSuite, ConfigurationStrategyTesting);
    ADD_TEST(configurationSuite, AnalysisDatabaseConfigurationTesting);

    AddSuite(configurationSuite);
}

void Database::TestingHelper::AddSqlInterfaceSuite()
{
    auto sqlInterfaceSuite = GenerateSuite("Sql�ӿ�");

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
    auto statementSuite = GenerateSuite("���");

    AddSuite(statementSuite);
}

void Database::TestingHelper::AddMysqlWrappersSuite()
{
    auto mysqlWrappersSuite = GenerateSuite("Mysql ��װ��");

    AddSuite(mysqlWrappersSuite);
}

void Database::TestingHelper::AddMysqlConnectorWrappersSuite()
{
    auto mysqlConnectorWrappersSuite = GenerateSuite("Mysql Connector ��װ��");

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
    auto sqlServerWrappersSuite = GenerateSuite("Sql Server ��װ��");

    AddSuite(sqlServerWrappersSuite);
}

void Database::TestingHelper::AddSQLiteWrappersSuite()
{
    auto sQLiteWrappersSuite = GenerateSuite("SQLite ��װ��");

    AddSuite(sQLiteWrappersSuite);
}

void Database::TestingHelper::AddPostgreSQLSuite()
{
    auto postgreSQLSuite = GenerateSuite("PostgreSQL ��װ��");

    AddSuite(postgreSQLSuite);
}

void Database::TestingHelper::AddOracleSuite()
{
    auto oracleSuite = GenerateSuite("Oracle ��װ��");

    AddSuite(oracleSuite);
}

void Database::TestingHelper::AddFlatFileWrappersSuite()
{
    auto flatFileWrappersSuite = GenerateSuite("ƽ���ļ���װ��");

    AddSuite(flatFileWrappersSuite);
}
