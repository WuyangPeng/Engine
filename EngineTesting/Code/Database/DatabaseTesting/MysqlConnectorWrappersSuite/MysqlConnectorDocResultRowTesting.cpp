// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.5 (2020/03/16 18:55)

#include "MysqlConnectorDocResultRowTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorDocResultRowTesting)

void Database::MysqlConnectorDocResultRowTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ResultRowTest);
}

void Database::MysqlConnectorDocResultRowTesting
	::ResultRowTest()
{
	ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",33060,"tcretest","root","TCRE" };

	Session session{ configurationStrategy };

	Schema schema{ session };

	Collection collection{ schema ,"my_collection" };

	Collection::BindStatementType bindStatementType{ {"param", "S%"} };
	auto result = collection.ExecuteDoc("name like :param", bindStatementType, 1);

	auto one = result->FetchOne();

	cout << *one << endl;
}

