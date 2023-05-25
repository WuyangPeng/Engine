///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:25)

#include "AnalysisDatabaseConfigurationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::string;
using std::vector;

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
    AnalysisDatabaseConfiguration analysisDatabaseConfiguration{ "Configuration/DatabaseTest.json" };

    ASSERT_EQUAL(2, analysisDatabaseConfiguration.GetSize());

    auto gameServer = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameServerDB"));

    ASSERT_ENUM_EQUAL(gameServer.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
    ASSERT_EQUAL(gameServer.GetIp(), "127.0.0.1");
    ASSERT_EQUAL(gameServer.GetPort(), 8010);
    ASSERT_EQUAL(gameServer.GetDBHostName(), "DBName");
    ASSERT_EQUAL(gameServer.GetDBUserName(), "root");
    ASSERT_EQUAL(gameServer.GetDBPassword(), "password");
    vector<string> clentFlags{ "CLIENT_COMPRESS", "CLIENT_IGNORE_SIGPIPE", "CLIENT_LOCAL_FILES" };
    ASSERT_EQUAL(gameServer.GetFlagsOption(), clentFlags);

    auto gameClient = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameClientDB"));

    ASSERT_ENUM_EQUAL(gameClient.GetWrappersStrategy(), WrappersStrategy::SQLite);
    ASSERT_EQUAL(gameClient.GetIp(), "127.0.0.1");
    ASSERT_EQUAL(gameClient.GetPort(), 8011);
    ASSERT_EQUAL(gameClient.GetDBHostName(), "dbName");
    ASSERT_EQUAL(gameClient.GetDBUserName(), "Account");
    ASSERT_EQUAL(gameClient.GetDBPassword(), "Password");
    ASSERT_EQUAL(gameClient.GetFlagsOption(), vector<string>{});
}
