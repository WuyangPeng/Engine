///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:20)

#include "MysqlConnectorDocResultTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorDocResultTesting)

void Database::MysqlConnectorDocResultTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

void Database::MysqlConnectorDocResultTesting::ResultTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "tcretest", "root", "TCRE" };

    Session session{ configurationStrategy };

    Schema schema{ session };

    Collection collection{ schema, "my_collection" };

    Collection::BindStatementType bindStatementType{ { "param", "S%" } };
    auto result = collection.ExecuteDoc("name like :param", bindStatementType, 1);
}
