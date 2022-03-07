///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:49)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorCollection.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/SqlInterface/Detail/SchemaImpl.h"
#include "Database/SqlInterface/Schema.h"

using std::make_shared;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorCollection::MysqlConnectorCollection(const Schema& schema, const string& collectionName)
    : ParentType{ schema.GetConfigurationStrategy() }, mysqlxCollection{ schema.GetCollection(collectionName) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorCollection::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxCollection)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::MysqlConnectorCollection::ResultSharedPtr Database::MysqlConnectorCollection::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    auto statement = mysqlxCollection->find(findStatement);

    if (0 < limitStatement)
    {
        statement = statement.limit(limitStatement);
    }

    for (const auto& value : bindStatement)
    {
        statement = statement.bind(value.first, value.second);
    }

    auto mysqlxDocResult = make_shared<MysqlxDocResult>(statement.execute());

    return make_shared<Result>(GetConfigurationStrategy(), mysqlxDocResult);
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR