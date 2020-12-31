//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:43)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDocResult.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDocResult::MysqlConnectorDocResult(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult) noexcept
    : ParentType{ configurationStrategy }, m_MysqlxDocResult{ mysqlxDocResult }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDocResult ::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxDocResult)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::ResultImpl::ResultRowPtr Database::MysqlConnectorDocResult::FetchOne()
{
    DATABASE_CLASS_IS_VALID_1;

    auto result = m_MysqlxDocResult->fetchOne();

    return make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxDbDoc>(result));
}

Database::ResultImpl::ResultRowContainer Database::MysqlConnectorDocResult::FetchAll()
{
    DATABASE_CLASS_IS_VALID_1;

    ResultRowContainer container{};

    auto result = m_MysqlxDocResult->fetchAll();

    for (const auto& value : result)
    {
        container.emplace_back(make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxDbDoc>(value)));
    }

    return container;
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR