///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:21)

#include "MysqlConnectorTableTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
using std::string;
using std::to_string;
using std::vector;

Database::MysqlConnectorTableTesting::MysqlConnectorTableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorTableTesting)

void Database::MysqlConnectorTableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Database::MysqlConnectorTableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TableTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SelectTest);
}

void Database::MysqlConnectorTableTesting::TableTest()
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

void Database::MysqlConnectorTableTesting::SelectTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "43.139.123.106", 33060, "tcretest", "root", "TCRE" };

   
}
