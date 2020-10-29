//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:38)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/SchemaImpl.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorSchema : public SchemaImpl
    {
    public:
        using ClassType = MysqlConnectorSchema;
        using ParentType = SchemaImpl;
        using SessionWeakPtr = std::weak_ptr<SessionImpl>;

    public:
        explicit MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr);
        MysqlConnectorSchema(const SessionWeakPtr& sessionWeakPtr, int dbIndex);
        MysqlConnectorSchema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] MysqlxCollectionPtr GetCollection(const std::string& collectionName) override;
        [[nodiscard]] MysqlxTablePtr GetTable(const std::string& tableonName) override;

    private:
        using MysqlxSchemaPtr = std::unique_ptr<MysqlxSchema>;

    private:
        [[nodiscard]] static ConfigurationStrategy GetConfigurationStrategy(const SessionWeakPtr& sessionWeakPtr);
        [[nodiscard]] static MysqlxSchemaPtr GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr);
        [[nodiscard]] static MysqlxSchemaPtr GetMysqlxSchemaPtr(const SessionWeakPtr& sessionWeakPtr, int dbIndex);

    private:
        MysqlxSchemaPtr m_MysqlxSchema;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H
