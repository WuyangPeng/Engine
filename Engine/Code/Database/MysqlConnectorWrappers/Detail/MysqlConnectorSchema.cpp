///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:52)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorSchema.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/SqlInterface/Detail/SessionImpl.h"
#include "Database/SqlInterface/Session.h"

using std::make_shared;
using std::make_unique;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorSchema::MysqlConnectorSchema(const Session& session)
    : ParentType{ session.GetConfigurationStrategy() }, mysqlxSchema{ session.GetMysqlxSchema() }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSchema::MysqlConnectorSchema(const Session& session, int dbIndex)
    : ParentType{ session.GetConfigurationStrategy() }, mysqlxSchema{ session.GetMysqlxSchema(dbIndex) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSchema::MysqlConnectorSchema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
    : ParentType{ configurationStrategy }, mysqlxSchema{ make_unique<MysqlxSchema>(mysqlxSchema) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorSchema::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxSchema)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

Database::SchemaImpl::MysqlxCollectionUniquePtr Database::MysqlConnectorSchema::GetCollection(const string& collectionName) const
{
    DATABASE_CLASS_IS_VALID_1;

    return make_unique<MysqlxCollection>(mysqlxSchema->getCollection(collectionName));
}

Database::SchemaImpl::MysqlxTableUniquePtr Database::MysqlConnectorSchema::GetTable(const string& tableonName) const
{
    DATABASE_CLASS_IS_VALID_1;

    return make_unique<MysqlxTable>(mysqlxSchema->getTable(tableonName));
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR