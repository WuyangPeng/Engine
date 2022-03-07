///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:46)

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

    public:
        explicit MysqlConnectorSchema(const Session& session);
        MysqlConnectorSchema(const Session& session, int dbIndex);
        MysqlConnectorSchema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD MysqlxCollectionUniquePtr GetCollection(const std::string& collectionName) const override;
        NODISCARD MysqlxTableUniquePtr GetTable(const std::string& tableonName) const override;

    private:
        using MysqlxSchemaUniquePtr = std::unique_ptr<MysqlxSchema>;

    private:
        MysqlxSchemaUniquePtr mysqlxSchema;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SCHEMA_H
