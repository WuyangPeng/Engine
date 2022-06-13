///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:19)

#include "MysqlConnectorDatabaseObjectTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorDatabaseObjectTesting)

void Database::MysqlConnectorDatabaseObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseObjectTest);
}

void Database::MysqlConnectorDatabaseObjectTesting::DatabaseObjectTest()
{
    ConfigurationStrategy::FlagsOption flagsOption;
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,
                                                 "127.0.0.1",
                                                 33060,
                                                 "tcretest",
                                                 "root",
                                                 "TCRE",
                                                 true,
                                                 10,
                                                 100,
                                                 1000,
                                                 flagsOption,
                                                 stringOption,
                                                 booleanOption,
                                                 intOption,
                                                 sslOption,
                                                 dbMapping };

    DatabaseObject databaseObject{ configurationStrategy };

    Session session{ databaseObject };
}