//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:39)

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
        ~MysqlConnectorSession() noexcept;

        MysqlConnectorSession(const MysqlConnectorSession& rhs) = default;
        MysqlConnectorSession& operator=(const MysqlConnectorSession& rhs) = default;
        MysqlConnectorSession(MysqlConnectorSession&& rhs) noexcept = default;
        MysqlConnectorSession& operator=(MysqlConnectorSession&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] MysqlxSchemaPtr GetMysqlxSchemaPtr() override;
        [[nodiscard]] MysqlxSchemaPtr GetMysqlxSchemaPtr(int dbIndex) override;
        [[nodiscard]] SchemaContainer GetSchemaContainer() override;

        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement) override;
        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement) override;
        [[nodiscard]] ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement) override;
        void Execute(const std::string& findStatement, int bindStatement) override;
        void Execute(const std::string& findStatement) override;
        void Execute(const std::string& findStatement, const std::string& bindStatement) override;

    private:
        using MysqlxSessionPtr = std::unique_ptr<MysqlxSession>;

    private:
        [[nodiscard]] static MysqlxSessionPtr GetMysqlxSessionPtr(const DatabaseObject& databaseObject);

    private:
        MysqlxSessionPtr m_MysqlxSession;
    };
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR

#endif  // DATABASE_SQL_INTERFACE_MYSQL_CONNECTOR_SESSION_H
