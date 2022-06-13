///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 16:19)

#include "MysqlConnectorDocResultRowTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Session.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorDocResultRowTesting)

void Database::MysqlConnectorDocResultRowTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResultRowTest);
}

void Database::MysqlConnectorDocResultRowTesting::ResultRowTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "tcretest", "root", "TCRE" };

    Session session{ configurationStrategy };

    Schema schema{ session };

    Collection collection{ schema, "my_collection" };

    Collection::BindStatementType bindStatementType{ { "param", "S%" } };
    auto result = collection.ExecuteDoc("name like :param", bindStatementType, 1);

    auto one = result->FetchOne();

    cout << *one << endl;
}
