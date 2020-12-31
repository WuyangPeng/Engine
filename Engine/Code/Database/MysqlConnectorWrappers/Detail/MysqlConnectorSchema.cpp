//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:45)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorSchema.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/SqlInterface/Detail/SessionImpl.h"

using std::make_shared;
using std::make_unique;
using std::string;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorSchema::MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr)
    : ParentType{ GetConfigurationStrategy(sessionWeakPtr) }, m_MysqlxSchema{ GetMysqlxSchemaPtr(sessionWeakPtr) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSchema::MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr, int dbIndex)
    : ParentType{ GetConfigurationStrategy(sessionWeakPtr) }, m_MysqlxSchema{ GetMysqlxSchemaPtr(sessionWeakPtr, dbIndex) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorSchema::MysqlConnectorSchema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
    : ParentType{ configurationStrategy }, m_MysqlxSchema{ make_unique<MysqlxSchema>(mysqlxSchema) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::ConfigurationStrategy Database::MysqlConnectorSchema::GetConfigurationStrategy(const SessionWeakPtr& sessionWeakPtr)
{
    auto session = sessionWeakPtr.lock();
    if (session)
    {
        return session->GetConfigurationStrategy();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Session 已无效。"s));
    }
}

Database::MysqlConnectorSchema::MysqlxSchemaPtr Database::MysqlConnectorSchema::GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr)
{
    auto session = sessionWeakPtr.lock();
    if (session)
    {
        return session->GetMysqlxSchemaPtr();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Session 已无效。"s));
    }
}

Database::MysqlConnectorSchema::MysqlxSchemaPtr Database::MysqlConnectorSchema::GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr, int dbIndex)
{
    auto session = sessionWeakPtr.lock();
    if (session)
    {
        return session->GetMysqlxSchemaPtr(dbIndex);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Session 已无效。"s));
    }
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorSchema::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxSchema)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

Database::SchemaImpl::MysqlxCollectionPtr Database::MysqlConnectorSchema::GetCollection(const string& collectionName)
{
    DATABASE_CLASS_IS_VALID_1;

    auto configurationStrategy = ParentType::GetConfigurationStrategy();

    return make_unique<MysqlxCollection>(m_MysqlxSchema->getCollection(collectionName));
}

Database::SchemaImpl::MysqlxTablePtr Database::MysqlConnectorSchema::GetTable(const string& tableonName)
{
    DATABASE_CLASS_IS_VALID_1;

    auto configurationStrategy = ParentType::GetConfigurationStrategy();

    return make_unique<MysqlxTable>(m_MysqlxSchema->getTable(tableonName));
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR