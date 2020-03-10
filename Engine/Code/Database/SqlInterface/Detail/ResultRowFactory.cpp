// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 10:04)

#include "Database/DatabaseExport.h"

#include "ResultRowFactory.h"
#include "ResultRowImpl.h"
#include "NullResultRow.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDocResultRow.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorResultRow.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;
 
Database::ResultRowFactory
	::ResultRowFactory()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRowFactory)

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory
	::Create(const ConfigurationStrategy& configurationStrategy)
{
	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{	
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		THROW_EXCEPTION(SYSTEM_TEXT("�޷����޲���������´���MysqlConnectorResultRow��"));

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullResultRow>(configurationStrategy);
	}
}

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 
	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

	if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
	{
		return std::make_shared<MysqlConnectorDocResultRow>(configurationStrategy, mysqlxDbDoc);
	}
#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���ResultRow��"));
}

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory
	::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow)
{	
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

	auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

	if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
	{
		return std::make_shared<MysqlConnectorResultRow>(configurationStrategy, mysqlxRow);
	}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���ResultRow��"));
}

