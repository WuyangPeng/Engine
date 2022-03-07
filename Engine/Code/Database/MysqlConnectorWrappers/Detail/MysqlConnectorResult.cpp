///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:51)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorResult.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::make_unique;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorResult::MysqlConnectorResult(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult) noexcept
    : ParentType{ configurationStrategy }, mysqlxRowResult{ mysqlxRowResult }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorResult::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxRowResult)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::ResultImpl::ResultRowUniquePtr Database::MysqlConnectorResult::FetchOne()
{
    DATABASE_CLASS_IS_VALID_1;

    auto result = mysqlxRowResult->fetchOne();

    return make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxRow>(result));
}

Database::ResultImpl::ResultRowContainer Database::MysqlConnectorResult::FetchAll()
{
    DATABASE_CLASS_IS_VALID_1;

    ResultRowContainer container{};

    auto result = mysqlxRowResult->fetchAll();

    for (const auto& value : result)
    {
        container.emplace_back(make_unique<ResultRow>(GetConfigurationStrategy(), make_shared<MysqlxRow>(value)));
    }

    return container;
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR