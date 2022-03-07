///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:54)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorTable.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/SqlInterface/Detail/SchemaImpl.h"
#include "Database/SqlInterface/Schema.h"

using std::make_shared;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorTable::MysqlConnectorTable(const Schema& schema, const string& tableName)
    : ParentType{ schema.GetConfigurationStrategy() }, mysqlxTable{ schema.GetTable(tableName) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorTable::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxTable)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::MysqlConnectorTable::ResultSharedPtr Database::MysqlConnectorTable::Select(StatementType selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    auto statement = mysqlxTable->select(selectStatement);

    if (!whereStatement.empty())
    {
        statement = statement.where(whereStatement);
    }

    if (!orderByStatement.empty())
    {
        statement = statement.orderBy(orderByStatement);
    }

    for (const auto& value : bindStatement)
    {
        statement = statement.bind(value.first, value.second);
    }

    return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(statement.execute()));
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR