// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:26)

#include "Database/DatabaseExport.h"

#include "CollectionFactory.h"
#include "CollectionImpl.h"
#include "NullCollection.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/Schema.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorCollection.h"

using std::make_shared;
using std::string;

Database::CollectionFactory
	::CollectionFactory() noexcept
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionFactory)

Database::CollectionFactory::ImplTypePtr Database::CollectionFactory
	::Create(const Schema& schema, const string& collectionName)
{
    const auto configurationStrategy = schema.GetConfigurationStrategy();
	const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorCollection>(schema, collectionName);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullCollection>(configurationStrategy);
	}
}


