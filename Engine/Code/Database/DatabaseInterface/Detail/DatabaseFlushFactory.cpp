///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:23)

#include "Database/DatabaseExport.h"

#include "DatabaseFlushFactory.h"
#include "NullDatabaseFlush.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/MongoWrappers/Detail/MongoDatabaseFlush.h"
#include "Database/MysqlBoostWrappers/Detail/MysqlBoostDatabaseFlush.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDatabaseFlush.h"
#include "Database/RedisWrappers/Detail/RedisDatabaseFlush.h"

#include <memory>

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseFlushFactory)

Database::DatabaseFlushFactory::DatabaseFlushSharedPtr Database::DatabaseFlushFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (configurationStrategy.GetWrappersStrategy())
    {
        case WrappersStrategy::MysqlBoost:
            return std::make_shared<MysqlBoostDatabaseFlush>(configurationStrategy);

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case WrappersStrategy::MysqlConnector:
            return std::make_shared<MysqlConnectorDatabaseFlush>(configurationStrategy);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#ifdef DATABASE_USE_MONGO

        case WrappersStrategy::Mongo:
            return std::make_shared<MongoDatabaseFlush>(configurationStrategy);

#endif  // DATABASE_USE_MONGO

#ifdef DATABASE_USE_REDIS

        case WrappersStrategy::Redis:
            return std::make_shared<RedisDatabaseFlush>(configurationStrategy);

#endif  // DATABASE_USE_REDIS

        default:
            return std::make_shared<NullDatabaseFlush>(configurationStrategy);
    }
}
