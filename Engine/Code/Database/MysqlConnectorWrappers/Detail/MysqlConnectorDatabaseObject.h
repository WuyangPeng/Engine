// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:47)

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
        ~MysqlConnectorDatabaseObject();

        MysqlConnectorDatabaseObject(const MysqlConnectorDatabaseObject&) = default;
        MysqlConnectorDatabaseObject& operator=(const MysqlConnectorDatabaseObject&) = default;
        MysqlConnectorDatabaseObject(MysqlConnectorDatabaseObject&&) = default;
        MysqlConnectorDatabaseObject& operator=(MysqlConnectorDatabaseObject&&) = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        MysqlxSessionPtr GetMysqlxSessionPtr() override;

    private:
        using MysqlxClientPtr = std::unique_ptr<MysqlxClient>;

    private:
        MysqlxClientPtr m_MysqlxClient;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_DATABASE_OBJECT_H
