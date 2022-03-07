///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:06)

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

Database::ResultFactory::ImplTypeSharedPtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            THROW_EXCEPTION(SYSTEM_TEXT("�޷����޲���������´���MysqlConnectorResult��"s));

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        default:
            return make_shared<NullResult>(configurationStrategy);
    }
}

Database::ResultFactory::ImplTypeSharedPtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorDocResult>(configurationStrategy, mysqlxDocResult);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���Result��"s));
}

Database::ResultFactory::ImplTypeSharedPtr Database::ResultFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorResult>(configurationStrategy, mysqlxRowResult);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���Result��"s));
}
