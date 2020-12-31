//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:37)

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

        [[nodiscard]] MysqlxSessionPtr GetMysqlxSessionPtr() override;

    private:
        using MysqlxClientPtr = std::unique_ptr<MysqlxClient>;

    private:
        MysqlxClientPtr m_MysqlxClient;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
