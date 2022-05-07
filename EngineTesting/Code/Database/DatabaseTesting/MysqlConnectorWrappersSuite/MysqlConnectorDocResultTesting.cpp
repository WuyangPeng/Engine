// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.5 (2020/03/16 18:55)

#include "MysqlConnectorDocResultTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorDocResultTesting)

void Database::MysqlConnectorDocResultTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ResultTest);
}

void Database::MysqlConnectorDocResultTesting
	::ResultTest()
{
	ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",33060,"tcretest","root","TCRE" };

	Session session{ configurationStrategy };

	Schema schema{ session };

	Collection collection{ schema ,"my_collection" };

	Collection::BindStatementType bindStatementType{ {"param", "S%"} };
	auto result = collection.ExecuteDoc("name like :param", bindStatementType, 1);
}
