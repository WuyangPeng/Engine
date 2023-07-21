///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.10 (2023/05/25 14:04)

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
    AddDatabaseInterfaceSuite();
    AddDatabaseGenerateSuite();
    AddStatementSuite();
    AddMysqlWrappersSuite();
    AddMysqlConnectorWrappersSuite();
    AddMysqlBoostWrappersSuite();
    AddSqlServerWrappersSuite();
    AddSQLiteWrappersSuite();
    AddPostgreSQLSuite();
    AddOracleSuite();
    AddFlatFileWrappersSuite();
    AddMariaDBWrappersSuite();
    AddMongoWrappersSuite();
    AddRedisWrappersSuite();
    AddDatabaseEntityCodeGenerationSuite();
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

void Database::TestingHelper::AddDatabaseInterfaceSuite()
{
    auto databaseInterfaceSuite = GenerateSuite("���ݿ�ӿ�");

    ADD_TEST(databaseInterfaceSuite, BasisDatabaseTesting);
    ADD_TEST(databaseInterfaceSuite, BasisDatabaseContainerTesting);
    ADD_TEST(databaseInterfaceSuite, BasisDatabaseManagerTesting);
    ADD_TEST(databaseInterfaceSuite, DatabaseEntityTesting);
    ADD_TEST(databaseInterfaceSuite, EntityTesting);
    ADD_TEST(databaseInterfaceSuite, DatabaseManagerTesting);
    ADD_TEST(databaseInterfaceSuite, DatabaseFieldTesting);
    ADD_TEST(databaseInterfaceSuite, DatabaseEnvironmentTesting);
    ADD_TEST(databaseInterfaceSuite, DatabaseFlushTesting);

    AddSuite(databaseInterfaceSuite);
}

void Database::TestingHelper::AddDatabaseGenerateSuite()
{
    auto databaseGenerateSuite = GenerateSuite("���ݿ�����");

    AddSuite(databaseGenerateSuite);
}

void Database::TestingHelper::AddStatementSuite()
{
    auto statementSuite = GenerateSuite("���");

    ADD_TEST(statementSuite, RedisStatementTesting);
    ADD_TEST(statementSuite, SqlStatementTesting);

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

    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDatabaseFlushTesting);

    AddSuite(mysqlConnectorWrappersSuite);
}

void Database::TestingHelper::AddMysqlBoostWrappersSuite()
{
    auto mysqlBoostWrappersSuite = GenerateSuite("mysql boost ��װ��");

    ADD_TEST(mysqlBoostWrappersSuite, MysqlBoostDatabaseFlushTesting);

    AddSuite(mysqlBoostWrappersSuite);
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

void Database::TestingHelper::AddMariaDBWrappersSuite()
{
    auto mariaDBWrappersSuite = GenerateSuite("mariaDB ��װ��");

    AddSuite(mariaDBWrappersSuite);
}

void Database::TestingHelper::AddMongoWrappersSuite()
{
    auto mongoWrappersSuite = GenerateSuite("mongo ��װ��");

    ADD_TEST(mongoWrappersSuite, MongoEnvironmentTesting);
    ADD_TEST(mongoWrappersSuite, MongoDatabaseFlushTesting);

    AddSuite(mongoWrappersSuite);
}

void Database::TestingHelper::AddRedisWrappersSuite()
{
    auto redisWrappersSuite = GenerateSuite("redis ��װ��");

    ADD_TEST(redisWrappersSuite, RedisDatabaseFlushTesting);

    AddSuite(redisWrappersSuite);
}

void Database::TestingHelper::AddDatabaseEntityCodeGenerationSuite()
{
    auto databaseEntityCodeGenerationSuite = GenerateSuite("���ݿ�ʵ���������");

    ADD_TEST(databaseEntityCodeGenerationSuite, CodeHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, CodeFwdHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, EntityHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, EntitySourceFileGenerationTesting);
    
    AddSuite(databaseEntityCodeGenerationSuite);
}
