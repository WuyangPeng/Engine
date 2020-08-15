// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:48)

#ifndef DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H
#define DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H

#include "Database/DatabaseDll.h"

#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Detail/SessionImpl.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

namespace Database
{
    class DATABASE_HIDDEN_DECLARE MysqlConnectorSession : public SessionImpl
    {
    public:
        using ClassType = MysqlConnectorSession;
        using ParentType = SessionImpl;

    public:
        explicit MysqlConnectorSession(const ConfigurationStrategy& configurationStrategy);
        explicit MysqlConnectorSession(const DatabaseObject& databaseObject);
        ~MysqlConnectorSession();

        MysqlConnectorSession(const MysqlConnectorSession&) = default;
        MysqlConnectorSession& operator=(const MysqlConnectorSession&) = default;
        MysqlConnectorSession(MysqlConnectorSession&&) = default;
        MysqlConnectorSession& operator=(MysqlConnectorSession&&) = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        MysqlxSchemaPtr GetMysqlxSchemaPtr() override;
        MysqlxSchemaPtr GetMysqlxSchemaPtr(int dbIndex) override;
        SchemaContainer GetSchemaContainer() override;

        ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement) override;
        ResultPtr ExecuteResult(const std::string& findStatement) override;
        ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement) override;
        void Execute(const std::string& findStatement, int bindStatement) override;
        void Execute(const std::string& findStatement) override;
        void Execute(const std::string& findStatement, const std::string& bindStatement) override;

    private:
        using MysqlxSessionPtr = std::unique_ptr<MysqlxSession>;

    private:
        static MysqlxSessionPtr GetMysqlxSessionPtr(const DatabaseObject& databaseObject);

    private:
        MysqlxSessionPtr m_MysqlxSession;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H
