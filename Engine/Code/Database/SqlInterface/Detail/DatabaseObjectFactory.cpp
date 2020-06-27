// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:26)

#include "Database/DatabaseExport.h"

#include "DatabaseObjectFactory.h"
#include "DatabaseObjectImpl.h"
#include "NullDatabaseObject.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDatabaseObject.h"

using std::make_shared;

Database::DatabaseObjectFactory
	::DatabaseObjectFactory()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObjectFactory)

Database::DatabaseObjectFactory::ImplTypePtr Database::DatabaseObjectFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorDatabaseObject>(configurationStrategy);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullDatabaseObject>(configurationStrategy);
	}
}


