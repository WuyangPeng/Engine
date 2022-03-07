///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 17:19)

#include "Database/DatabaseExport.h"

#include "NullSchema.h"
#include "SchemaFactory.h"
#include "SchemaImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorSchema.h"
#include "Database/SqlInterface/Session.h"

using std::make_shared;

Database::SchemaFactory::SchemaFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SchemaFactory)

Database::SchemaFactory::ImplTypeSharedPtr Database::SchemaFactory::Create(const Session& session)
{
    const auto configurationStrategy = session.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorSchema>(session);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        default:
            return make_shared<NullSchema>(configurationStrategy);
    }
}

Database::SchemaFactory::ImplTypeSharedPtr Database::SchemaFactory::Create(const Session& session, int dbIndex)
{
    const auto configurationStrategy = session.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorSchema>(session, dbIndex);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        default:
            return make_shared<NullSchema>(configurationStrategy);
    }
}

Database::SchemaFactory::ImplTypeSharedPtr Database::SchemaFactory::Create(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
{
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    if (wrappersStrategy == Database::WrappersStrategy::MysqlConnector)
    {
        return std::make_shared<MysqlConnectorSchema>(configurationStrategy, mysqlxSchema);
    }

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

    THROW_EXCEPTION(SYSTEM_TEXT("�޷��ڷ�MysqlConnector�����´���Schema��"s));
}
