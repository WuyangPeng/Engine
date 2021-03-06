//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:41)

#include "Database/DatabaseExport.h"

#include "NullSession.h"
#include "SessionFactory.h"
#include "SessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorSession.h"
#include "Database/SqlInterface/DatabaseObject.h"

using std::make_shared;

Database::SessionFactory::SessionFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SessionFactory)

Database::SessionFactory::ImplTypePtr Database::SessionFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorSession>(configurationStrategy);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::Null:
        case Database::WrappersStrategy::Mysql:
        case Database::WrappersStrategy::SQLite:
        case Database::WrappersStrategy::SqlServer:
        case Database::WrappersStrategy::FlatFile:
        default:
            return make_shared<NullSession>(configurationStrategy);
    }
}

Database::SessionFactory::ImplTypePtr Database::SessionFactory::Create(const DatabaseObject& databaseObject)
{
    const auto configurationStrategy = databaseObject.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorSession>(databaseObject);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::Null:
        case Database::WrappersStrategy::Mysql:
        case Database::WrappersStrategy::SQLite:
        case Database::WrappersStrategy::SqlServer:
        case Database::WrappersStrategy::FlatFile:
        default:
            return make_shared<NullSession>(configurationStrategy);
    }
}
