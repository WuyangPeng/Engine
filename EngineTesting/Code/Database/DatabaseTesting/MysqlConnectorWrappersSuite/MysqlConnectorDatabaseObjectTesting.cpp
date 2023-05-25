///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:19)

#include "MysqlConnectorDatabaseObjectTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Database/Configuration/ConfigurationStrategy.h" 
using std::string;
using std::vector;

Database::MysqlConnectorDatabaseObjectTesting::MysqlConnectorDatabaseObjectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, MysqlConnectorDatabaseObjectTesting)

void Database::MysqlConnectorDatabaseObjectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
                                                 "43.139.123.106",
                                                 33060,
                                                 "tcretest",
                                                 "root",
                                                 "TCRE",
                                                 true,
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