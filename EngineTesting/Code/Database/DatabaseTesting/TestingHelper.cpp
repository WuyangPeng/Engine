///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/25 14:04)

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

void Database::TestingHelper::AddDatabaseInterfaceSuite()
{
    auto databaseInterfaceSuite = GenerateSuite("数据库接口");

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
    auto databaseGenerateSuite = GenerateSuite("数据库生成");

    AddSuite(databaseGenerateSuite);
}

void Database::TestingHelper::AddStatementSuite()
{
    auto statementSuite = GenerateSuite("语句");

    ADD_TEST(statementSuite, RedisStatementTesting);
    ADD_TEST(statementSuite, SqlStatementTesting);

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

    ADD_TEST(mysqlConnectorWrappersSuite, MysqlConnectorDatabaseFlushTesting);

    AddSuite(mysqlConnectorWrappersSuite);
}

void Database::TestingHelper::AddMysqlBoostWrappersSuite()
{
    auto mysqlBoostWrappersSuite = GenerateSuite("mysql boost 包装器");

    ADD_TEST(mysqlBoostWrappersSuite, MysqlBoostDatabaseFlushTesting);

    AddSuite(mysqlBoostWrappersSuite);
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

void Database::TestingHelper::AddMariaDBWrappersSuite()
{
    auto mariaDBWrappersSuite = GenerateSuite("mariaDB 包装器");

    AddSuite(mariaDBWrappersSuite);
}

void Database::TestingHelper::AddMongoWrappersSuite()
{
    auto mongoWrappersSuite = GenerateSuite("mongo 包装器");

    ADD_TEST(mongoWrappersSuite, MongoEnvironmentTesting);
    ADD_TEST(mongoWrappersSuite, MongoDatabaseFlushTesting);

    AddSuite(mongoWrappersSuite);
}

void Database::TestingHelper::AddRedisWrappersSuite()
{
    auto redisWrappersSuite = GenerateSuite("redis 包装器");

    ADD_TEST(redisWrappersSuite, RedisDatabaseFlushTesting);

    AddSuite(redisWrappersSuite);
}

void Database::TestingHelper::AddDatabaseEntityCodeGenerationSuite()
{
    auto databaseEntityCodeGenerationSuite = GenerateSuite("数据库实体代码生成");

    ADD_TEST(databaseEntityCodeGenerationSuite, CodeHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, CodeFwdHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, EntityHeaderFileGenerationTesting);
    ADD_TEST(databaseEntityCodeGenerationSuite, EntitySourceFileGenerationTesting);
    
    AddSuite(databaseEntityCodeGenerationSuite);
}
