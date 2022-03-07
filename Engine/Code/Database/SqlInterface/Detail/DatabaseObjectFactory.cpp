///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:56)

#include "Database/DatabaseExport.h"

#include "DatabaseObjectFactory.h"
#include "DatabaseObjectImpl.h"
#include "NullDatabaseObject.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorDatabaseObject.h"

using std::make_shared;

Database::DatabaseObjectFactory::DatabaseObjectFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObjectFactory)

Database::DatabaseObjectFactory::ImplTypeSharedPtr Database::DatabaseObjectFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorDatabaseObject>(configurationStrategy);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        default:
            return make_shared<NullDatabaseObject>(configurationStrategy);
    }
}
