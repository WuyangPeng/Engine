//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:40)

#include "Database/DatabaseExport.h"

#include "NullResultRow.h"
#include "ResultRowFactory.h"
#include "ResultRowImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDocResultRow.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorResultRow.h"

using std::make_shared;

Database::ResultRowFactory::ResultRowFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRowFactory)

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            THROW_EXCEPTION(SYSTEM_TEXT("�޷����޲���������´���MysqlConnectorResultRow��"s));

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::Null:
        case Database::WrappersStrategy::Mysql:
        case Database::WrappersStrategy::SQLite:
        case Database::WrappersStrategy::SqlServer:
        case Database::WrappersStrategy::FlatFile:
        default:
            return make_shared<NullResultRow>(configurationStrategy);
    }
}

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorDocResultRow>(configurationStrategy, mysqlxDbDoc);
    }
#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���ResultRow��"s));
}

Database::ResultRowFactory::ImplTypePtr Database::ResultRowFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorResultRow>(configurationStrategy, mysqlxRow);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���ResultRow��"s));
}
