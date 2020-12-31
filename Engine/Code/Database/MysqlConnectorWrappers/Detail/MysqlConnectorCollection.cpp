//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:41)

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
    : ParentType{ schema.GetConfigurationStrategy() }, m_MysqlxCollection{ GetMysqlxCollectionPtr(schema, collectionName) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorCollection::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxCollection)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::MysqlConnectorCollection::MysqlxCollectionPtr Database::MysqlConnectorCollection::GetMysqlxCollectionPtr(const Schema& schema, const string& collectionName)
{
    auto implPtr = schema.GetImplType().lock();

    if (implPtr)
    {
        return implPtr->GetCollection(collectionName);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取schema失败。"s));
    }
}

Database::MysqlConnectorCollection::ResultPtr Database::MysqlConnectorCollection::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    using MysqlxDocResultPtr = std::shared_ptr<MysqlxDocResult>;

    auto statement = m_MysqlxCollection->find(findStatement);

    if (0 < limitStatement)
    {
        statement = statement.limit(limitStatement);
    }

    for (const auto& value : bindStatement)
    {
        statement = statement.bind(value.first, value.second);
    }

    MysqlxDocResultPtr mysqlxDocResult{ make_shared<MysqlxDocResult>(statement.execute()) };

    return make_shared<Result>(GetConfigurationStrategy(), mysqlxDocResult);
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR