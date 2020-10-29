//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:04)

#include "Database/DatabaseExport.h"

#include "CollectionFactory.h"
#include "CollectionImpl.h"
#include "NullCollection.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorCollection.h"
#include "Database/SqlInterface/Schema.h"

using std::make_shared;
using std::string;

Database::CollectionFactory::CollectionFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionFactory)

Database::CollectionFactory::ImplTypePtr Database::CollectionFactory::Create(const Schema& schema, const string& collectionName)
{
    const auto configurationStrategy = schema.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorCollection>(schema, collectionName);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::Null:
        case Database::WrappersStrategy::Mysql:
        case Database::WrappersStrategy::SQLite:
        case Database::WrappersStrategy::SqlServer:
        case Database::WrappersStrategy::FlatFile:
        default:
            return make_shared<NullCollection>(configurationStrategy);
    }
}
