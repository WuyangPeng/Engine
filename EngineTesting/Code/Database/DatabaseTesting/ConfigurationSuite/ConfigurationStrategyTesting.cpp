// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:43)

#include "ConfigurationStrategyTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Database, ConfigurationStrategy)

void Database::ConfigurationStrategyTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConfigurationTest);
}

void Database::ConfigurationStrategyTesting
	::ConfigurationTest()
{
	TestingType configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",8010u,"Server","root","password" };

	ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
	ASSERT_EQUAL(configurationStrategy.GetIP(), "127.0.0.1");
	ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);
	ASSERT_EQUAL(configurationStrategy.GetDBHostName(), "Server");
	ASSERT_EQUAL(configurationStrategy.GetDBUserName(), "root");
	ASSERT_EQUAL(configurationStrategy.GetDBPassword(), "password");
}

void Database::ConfigurationStrategyTesting
	::FlagsOptionTest()
{
	TestingType::FlagsOption flagsOption{ "CLIENT_COMPRESS","CLIENT_FOUND_ROWS", "CLIENT_IGNORE_SIGPIPE",	"CLIENT_IGNORE_SPACE",
										  "CLIENT_INTERACTIVE","CLIENT_LOCAL_FILES","CLIENT_MULTI_STATEMENTS","CLIENT_NO_SCHEMA" };
	TestingType::StringOption stringOption;
	TestingType::BooleanOption booleanOption;
	TestingType::IntOption intOption;
	TestingType::SSLOption sslOption;
	TestingType::DBMapping dbMapping;

	TestingType configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",8010u,"Server","root","password",false,10,100,1000,flagsOption,stringOption,booleanOption,intOption,sslOption,dbMapping };

	ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
	ASSERT_EQUAL(configurationStrategy.GetIP(), "127.0.0.1");
	ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);
	ASSERT_EQUAL(configurationStrategy.GetDBHostName(), "Server");
	ASSERT_EQUAL(configurationStrategy.GetDBUserName(), "root");
	ASSERT_EQUAL(configurationStrategy.GetDBPassword(), "password");
	ASSERT_FALSE(configurationStrategy.GetPooling());
	ASSERT_EQUAL(configurationStrategy.GetPoolMaxSize(), 10);
	ASSERT_EQUAL(configurationStrategy.GetPoolQueueTimeout(), 100);
	ASSERT_EQUAL(configurationStrategy.GetPoolMaxIdleTime(), 1000);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetFlagsOption(), flagsOption);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetStringOptions(), stringOption);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetBooleanOptions(), booleanOption);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetIntOptions(), intOption);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetSSLOptions(), sslOption);
	ASSERT_EQUAL_DO_NOT_USE_MESSAGE(configurationStrategy.GetDBMapping(), dbMapping);
	ASSERT_FALSE(configurationStrategy.IsUseSSL());
}

