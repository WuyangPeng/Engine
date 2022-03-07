///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:20)

#include "Database/DatabaseExport.h"

#include "NullTable.h"
#include "TableFactory.h"
#include "TableImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorTable.h"
#include "Database/SqlInterface/Schema.h"

using std::make_shared;
using std::string;

Database::TableFactory::TableFactory() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, TableFactory)

Database::TableFactory::ImplTypeSharedPtr Database::TableFactory::Create(const Schema& schema, const string& tableName)
{
    const auto configurationStrategy = schema.GetConfigurationStrategy();
    const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
    switch (wrappersStrategy)
    {
#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

        case Database::WrappersStrategy::MysqlConnector:
            return make_shared<MysqlConnectorTable>(schema, tableName);

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

        default:
            return make_shared<NullTable>(configurationStrategy);
    }
}
