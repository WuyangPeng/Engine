// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:43)

#include "AnalysisDatabaseConfigurationTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/AnalysisDatabaseConfiguration.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Database, AnalysisDatabaseConfiguration)

void Database::AnalysisDatabaseConfigurationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConfigurationTest);
}

void Database::AnalysisDatabaseConfigurationTesting
	::ConfigurationTest()
{
	TestingType analysisDatabaseConfiguration{ "Configuration/DatabaseTest.json" };

	ASSERT_EQUAL(2, analysisDatabaseConfiguration.GetSize());

	auto gameServer = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameServerDB"));

	ASSERT_ENUM_EQUAL(gameServer.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
	ASSERT_EQUAL(gameServer.GetIP(), "127.0.0.1");
	ASSERT_EQUAL(gameServer.GetPort(), 8010);
	ASSERT_EQUAL(gameServer.GetDBHostName(), "DBName");
	ASSERT_EQUAL(gameServer.GetDBUserName(), "root");
	ASSERT_EQUAL(gameServer.GetDBPassword(), "password");
	vector<string> clentFlags{ "CLIENT_COMPRESS", "CLIENT_IGNORE_SIGPIPE", "CLIENT_LOCAL_FILES" };
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(gameServer.GetFlagsOption(), clentFlags);

	auto gameClient = analysisDatabaseConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameClientDB"));

	ASSERT_ENUM_EQUAL(gameClient.GetWrappersStrategy(), WrappersStrategy::SQLite);
	ASSERT_EQUAL(gameClient.GetIP(), "127.0.0.1");
	ASSERT_EQUAL(gameClient.GetPort(), 8011);
	ASSERT_EQUAL(gameClient.GetDBHostName(), "dbName");
	ASSERT_EQUAL(gameClient.GetDBUserName(), "Account");
	ASSERT_EQUAL(gameClient.GetDBPassword(), "Password");
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(gameClient.GetFlagsOption(), vector<string>{});
}

