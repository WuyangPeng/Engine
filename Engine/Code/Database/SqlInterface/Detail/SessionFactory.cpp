// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:31)

#include "Database/DatabaseExport.h"

#include "SessionFactory.h"
#include "SessionImpl.h"
#include "NullSession.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorSession.h"

using std::make_shared;

Database::SessionFactory
	::SessionFactory() noexcept
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SessionFactory)

Database::SessionFactory::ImplTypePtr Database::SessionFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorSession>(configurationStrategy);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullSession>(configurationStrategy);
	}
}

Database::SessionFactory::ImplTypePtr Database::SessionFactory
	::Create(const DatabaseObject& databaseObject)
{
    const auto configurationStrategy = databaseObject.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorSession>(databaseObject);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullSession>(configurationStrategy);
	}
}

