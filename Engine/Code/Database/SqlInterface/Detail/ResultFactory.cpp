// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/16 12:29)

#include "Database/DatabaseExport.h"

#include "ResultFactory.h"
#include "ResultImpl.h"
#include "NullResult.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorResult.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDocResult.h"

using std::make_shared;

Database::ResultFactory
	::ResultFactory()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultFactory)

Database::ResultFactory::ImplTypePtr Database::ResultFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		THROW_EXCEPTION(SYSTEM_TEXT("无法在无参数的情况下创建MysqlConnectorResult。"));

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullResult>(configurationStrategy);
	}
}

Database::ResultFactory::ImplTypePtr Database::ResultFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
	{
		return std::make_shared<MysqlConnectorDocResult>(configurationStrategy, mysqlxDocResult);
	}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	THROW_EXCEPTION(SYSTEM_TEXT("无法在非MysqlConnector环境下创建Result。"));
}

Database::ResultFactory::ImplTypePtr Database::ResultFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

	if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
	{
		return std::make_shared<MysqlConnectorResult>(configurationStrategy, mysqlxRowResult);
	}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	THROW_EXCEPTION(SYSTEM_TEXT("无法在非MysqlConnector环境下创建Result。"));
}

