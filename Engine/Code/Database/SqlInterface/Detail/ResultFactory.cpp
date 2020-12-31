//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:39)

#include "Database/DatabaseExport.h"

#include "NullResult.h"
#include "ResultFactory.h"
#include "ResultImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDocResult.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorResult.h"

using std::make_shared;

Database::ResultFactory::ResultFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultFactory)

Database::ResultFactory::ImplTypePtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            THROW_EXCEPTION(SYSTEM_TEXT("无法在无参数的情况下创建MysqlConnectorResult。"s));

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::Null:
        case Database::WrappersStrategy::Mysql:
        case Database::WrappersStrategy::SQLite:
        case Database::WrappersStrategy::SqlServer:
        case Database::WrappersStrategy::FlatFile:
        default:
            return make_shared<NullResult>(configurationStrategy);
    }
}

Database::ResultFactory::ImplTypePtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorDocResult>(configurationStrategy, mysqlxDocResult);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("无法在非MysqlConnector环境下创建Result。"s));
}

Database::ResultFactory::ImplTypePtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorResult>(configurationStrategy, mysqlxRowResult);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("无法在非MysqlConnector环境下创建Result。"s));
}
