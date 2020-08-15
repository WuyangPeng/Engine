// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/16 12:49)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDocResult.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDocResult ::MysqlConnectorDocResult(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult) noexcept
    : ParentType{ configurationStrategy }, m_MysqlxDocResult{ mysqlxDocResult }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

 

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDocResult
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxDocResult)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Database::ResultImpl::ResultRowPtr Database::MysqlConnectorDocResult
	::FetchOne()
{
	DATABASE_CLASS_IS_VALID_1;

	auto result = m_MysqlxDocResult->fetchOne();

	return make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxDbDoc>(result));
}

Database::ResultImpl::ResultRowContainer Database::MysqlConnectorDocResult
	::FetchAll()
{
	DATABASE_CLASS_IS_VALID_1;

	ResultRowContainer container;

	auto result = m_MysqlxDocResult->fetchAll();

	for (const auto& value : result)
	{
		container.push_back(make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxDbDoc>(value)));
	}

	return container;
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR