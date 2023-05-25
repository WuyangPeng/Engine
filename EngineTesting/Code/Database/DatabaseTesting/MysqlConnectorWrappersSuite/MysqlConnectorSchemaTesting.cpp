///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:20)

#include "MysqlConnectorSchemaTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
using std::string;
using std::vector;

Database::MysqlConnectorSchemaTesting::MysqlConnectorSchemaTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorSchemaTesting)

void Database::MysqlConnectorSchemaTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlConnectorSchemaTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SchemaTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SchemaContainerTest);
}

void Database::MysqlConnectorSchemaTesting::SchemaTest()
{
    ConfigurationStrategy::FlagsOption flagsOption;
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    dbMapping.insert({ 1, "dbtest" });

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,
                                                 "43.139.123.106",
                                                 33060,
                                                 "tcretest",
                                                 "root",
                                                 "TCRE",
                                                 false,
                                                 10,
                                                 100,
                                                 1000,
                                                 1,
                                                 flagsOption,
                                                 stringOption,
                                                 booleanOption,
                                                 intOption,
                                                 sslOption,
                                                 dbMapping };

   
}

void Database::MysqlConnectorSchemaTesting::SchemaContainerTest()
{
    ConfigurationStrategy::FlagsOption flagsOption;
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    dbMapping.insert({ 1, "dbtest" });

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,
                                                 "43.139.123.106",
                                                 33060,
                                                 "tcretest",
                                                 "root",
                                                 "TCRE",
                                                 false,
                                                 10,
                                                 100,
                                                 1000,
                                                 1,
                                                 flagsOption,
                                                 stringOption,
                                                 booleanOption,
                                                 intOption,
                                                 sslOption,
                                                 dbMapping };

    
}
