///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:25)

#include "ConfigurationStrategyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h"
using std::string;
using std::vector;

Database::ConfigurationStrategyTesting::ConfigurationStrategyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, ConfigurationStrategyTesting)

void Database::ConfigurationStrategyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::ConfigurationStrategyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConfigurationTest);
}

void Database::ConfigurationStrategyTesting::ConfigurationTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 8010u, "Server", "root", "password" };

    ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
    ASSERT_EQUAL(configurationStrategy.GetIp(), "127.0.0.1");
    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);
    ASSERT_EQUAL(configurationStrategy.GetDBHostName(), "Server");
    ASSERT_EQUAL(configurationStrategy.GetDBUserName(), "root");
    ASSERT_EQUAL(configurationStrategy.GetDBPassword(), "password");
}

void Database::ConfigurationStrategyTesting::FlagsOptionTest()
{
    ConfigurationStrategy::FlagsOption flagsOption{ "CLIENT_COMPRESS",
                                                    "CLIENT_FOUND_ROWS",
                                                    "CLIENT_IGNORE_SIGPIPE",
                                                    "CLIENT_IGNORE_SPACE",
                                                    "CLIENT_INTERACTIVE",
                                                    "CLIENT_LOCAL_FILES",
                                                    "CLIENT_MULTI_STATEMENTS",
                                                    "CLIENT_NO_SCHEMA" };
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 8010u, "Server", "root", "password", false, 10, 100, 1000, 1, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping };

    ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::MysqlConnector);
    ASSERT_EQUAL(configurationStrategy.GetIp(), "127.0.0.1");
    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);
    ASSERT_EQUAL(configurationStrategy.GetDBHostName(), "Server");
    ASSERT_EQUAL(configurationStrategy.GetDBUserName(), "root");
    ASSERT_EQUAL(configurationStrategy.GetDBPassword(), "password");
    ASSERT_FALSE(configurationStrategy.GetPooling());
    ASSERT_EQUAL(configurationStrategy.GetPoolMaxSize(), 10);
    ASSERT_EQUAL(configurationStrategy.GetPoolQueueTimeout(), 100);
    ASSERT_EQUAL(configurationStrategy.GetPoolMaxIdleTime(), 1000);
    ASSERT_EQUAL(configurationStrategy.GetFlagsOption(), flagsOption);
    ASSERT_EQUAL(configurationStrategy.GetStringOptions(), stringOption);
    ASSERT_EQUAL(configurationStrategy.GetBooleanOptions(), booleanOption);
    ASSERT_EQUAL(configurationStrategy.GetIntOptions(), intOption);
    ASSERT_EQUAL(configurationStrategy.GetSSLOptions(), sslOption);
    ASSERT_EQUAL(configurationStrategy.GetDBMapping(), dbMapping);
    ASSERT_FALSE(configurationStrategy.IsUseSSL());
}
