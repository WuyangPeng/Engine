///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:21)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/DatabaseObjectImpl.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorDatabaseObject : public DatabaseObjectImpl
    {
    public:
        using ClassType = MysqlConnectorDatabaseObject;
        using ParentType = DatabaseObjectImpl;

    public:
        explicit MysqlConnectorDatabaseObject(const ConfigurationStrategy& configurationStrategy);
        ~MysqlConnectorDatabaseObject() noexcept;

        MysqlConnectorDatabaseObject(const MysqlConnectorDatabaseObject& rhs) = default;
        MysqlConnectorDatabaseObject& operator=(const MysqlConnectorDatabaseObject& rhs) = default;
        MysqlConnectorDatabaseObject(MysqlConnectorDatabaseObject&& rhs) noexcept = default;
        MysqlConnectorDatabaseObject& operator=(MysqlConnectorDatabaseObject&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD MysqlxSessionUniquePtr GetMysqlxSession() const override;

    private:
        using MysqlxClientUniquePtr = std::unique_ptr<MysqlxClient>;

    private:
        MysqlxClientUniquePtr mysqlxClient;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
