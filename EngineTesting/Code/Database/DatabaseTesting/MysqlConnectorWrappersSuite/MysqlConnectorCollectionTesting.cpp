///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 16:19)

#include "MysqlConnectorCollectionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/Session.h"

using std::string;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorCollectionTesting)

void Database::MysqlConnectorCollectionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CollectionTest);
}

void Database::MysqlConnectorCollectionTesting::CollectionTest()
{
    ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector, "127.0.0.1", 33060, "tcretest", "root", "TCRE" };

    Session session{ configurationStrategy };

    Schema schema{ session };

    Collection collection{ schema, "my_collection" };
}
