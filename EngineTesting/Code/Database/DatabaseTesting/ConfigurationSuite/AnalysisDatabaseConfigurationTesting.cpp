///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.10 (2023/05/25 14:54)

#include "AnalysisDatabaseConfigurationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"

Database::AnalysisDatabaseConfigurationTesting::AnalysisDatabaseConfigurationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, AnalysisDatabaseConfigurationTesting)

void Database::AnalysisDatabaseConfigurationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::AnalysisDatabaseConfigurationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConfigurationTest);
}

void Database::AnalysisDatabaseConfigurationTesting::ConfigurationTest()
{
    const AnalysisDatabaseConfiguration analysisDatabaseConfiguration{ "Configuration/DatabaseTest.json" };

    ASSERT_EQUAL(2, analysisDatabaseConfiguration.GetSize());

    const auto gameServer = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameServerDB"));

    ASSERT_ENUM_EQUAL(gameServer.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
    ASSERT_EQUAL(gameServer.GetIp(), "43.139.123.106");
    ASSERT_EQUAL(gameServer.GetPort(), 33060);
    ASSERT_EQUAL(gameServer.GetDBHostName(), "tcretest");
    ASSERT_EQUAL(gameServer.GetDBUserName(), "root");
    ASSERT_EQUAL(gameServer.GetDBPassword(), "TCRE");
    const std::vector<std::string> clientFlags{ "CLIENT_COMPRESS", "CLIENT_IGNORE_SIGPIPE", "CLIENT_LOCAL_FILES" };
    ASSERT_EQUAL(gameServer.GetFlagsOption(), clientFlags);

    const auto gameClient = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameClientDB"));

    ASSERT_ENUM_EQUAL(gameClient.GetWrappersStrategy(), WrappersStrategy::SQLite);
    ASSERT_EQUAL(gameClient.GetIp(), "127.0.0.1");
    ASSERT_EQUAL(gameClient.GetPort(), 8011);
    ASSERT_EQUAL(gameClient.GetDBHostName(), "dbName");
    ASSERT_EQUAL(gameClient.GetDBUserName(), "Account");
    ASSERT_EQUAL(gameClient.GetDBPassword(), "Password");
    ASSERT_EQUAL(gameClient.GetFlagsOption(), std::vector<std::string>{});
}
