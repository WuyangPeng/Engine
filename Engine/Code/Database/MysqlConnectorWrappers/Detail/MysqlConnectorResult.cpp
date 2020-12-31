//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:44)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorResult.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorResult::MysqlConnectorResult(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult) noexcept
    : ParentType{ configurationStrategy }, m_MysqlxRowResult{ mysqlxRowResult }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorResult::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxRowResult)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::ResultImpl::ResultRowPtr Database::MysqlConnectorResult::FetchOne()
{
    DATABASE_CLASS_IS_VALID_1;

    auto result = m_MysqlxRowResult->fetchOne();

    return make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxRow>(result));
}

Database::ResultImpl::ResultRowContainer Database::MysqlConnectorResult::FetchAll()
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

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR