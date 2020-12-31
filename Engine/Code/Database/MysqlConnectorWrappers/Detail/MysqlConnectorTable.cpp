//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:47)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorTable.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/SqlInterface/Detail/SchemaImpl.h"
#include "Database/SqlInterface/Schema.h"

using std::initializer_list;
using std::make_shared;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR
   
Database::MysqlConnectorTable::MysqlConnectorTable(const Schema& schema, const string& tableName)
    : ParentType{ schema.GetConfigurationStrategy() }, m_MysqlxTable{ GetMysqlxTablePtr(schema, tableName) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorTable::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxTable)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::MysqlConnectorTable::MysqlxTablePtr Database::MysqlConnectorTable::GetMysqlxTablePtr(const Schema& schema, const string& tableName)
{
    auto implPtr = schema.GetImplType().lock();

    if (implPtr)
    {
        return implPtr->GetTable(tableName);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取schema失败。"s));
    }
}

Database::MysqlConnectorTable::ResultPtr Database::MysqlConnectorTable::Select(initializer_list<string> selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

    auto statement = m_MysqlxTable->select(selectStatement);

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