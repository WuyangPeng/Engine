///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:16)

#include "DatabaseObjectTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, DatabaseObjectTesting)

void Database::DatabaseObjectTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullDatabaseObjectTest);
}

void Database::DatabaseObjectTesting::NullDatabaseObjectTest()
{
    ConfigurationStrategy::FlagsOption flagsOption;
    ConfigurationStrategy::StringOption stringOption;
    ConfigurationStrategy::BooleanOption booleanOption;
    ConfigurationStrategy::IntOption intOption;
    ConfigurationStrategy::SSLOption sslOption;
    ConfigurationStrategy::DBMapping dbMapping;

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                 "127.0.0.1",
                                                 3306,
                                                 "tcretest",
                                                 "root",
                                                 "123456",
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
