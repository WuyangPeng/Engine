// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/16 12:50)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorResult.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorResult
	::MysqlConnectorResult(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
	: ParentType{ configurationStrategy }, m_MysqlxRowResult{ mysqlxRowResult }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorResult
	::~MysqlConnectorResult()
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorResult
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxRowResult)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Database::ResultImpl::ResultRowPtr Database::MysqlConnectorResult
	::FetchOne()
{
	DATABASE_CLASS_IS_VALID_1;

	auto result = m_MysqlxRowResult->fetchOne();

	return make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxRow>(result));
}

Database::ResultImpl::ResultRowContainer Database::MysqlConnectorResult
	::FetchAll()
{
	DATABASE_CLASS_IS_VALID_1;

	ResultRowContainer container;

	auto result = m_MysqlxRowResult->fetchAll();

	for (const auto& value : result)
	{
		container.emplace_back(make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxRow>(value)));
	}

	return container;
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR