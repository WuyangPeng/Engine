// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/16 12:30)

#include "Database/DatabaseExport.h"

#include "SchemaFactory.h"
#include "SchemaImpl.h"
#include "NullSchema.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/Session.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorSchema.h"

using std::make_shared;

Database::SchemaFactory
	::SchemaFactory() noexcept
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SchemaFactory)

Database::SchemaFactory::ImplTypePtr Database::SchemaFactory
	::Create(const Session& session)
{
    const auto configurationStrategy = session.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorSchema>(session.GetImplType());

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullSchema>(configurationStrategy);
	}
}

Database::SchemaFactory::ImplTypePtr Database::SchemaFactory
	::Create(const Session& session, int dbIndex)
{
    const auto configurationStrategy = session.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorSchema>(session.GetImplType(), dbIndex);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullSchema>(configurationStrategy);
	}
}

Database::SchemaFactory::ImplTypePtr Database::SchemaFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
	{
		return std::make_shared<MysqlConnectorSchema>(configurationStrategy, mysqlxSchema);
	}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	THROW_EXCEPTION(SYSTEM_TEXT("无法在非MysqlConnector环境下创建Schema。"s));
}

