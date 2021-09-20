//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:53)

#ifndef DATABASE_SQL_INTERFACE_SESSION_IMPL_H
#define DATABASE_SQL_INTERFACE_SESSION_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Schema.h"

namespace Database
{
    class SessionFactory;
    class DATABASE_HIDDEN_DECLARE SessionImpl
    {
    public:
        using ClassType = SessionImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using MysqlxSchemaPtr = std::unique_ptr<MysqlxSchema>;
        using SchemaPtr = std::unique_ptr<Schema>;
        using SchemaContainer = std::vector<SchemaPtr>;
        using ResultPtr = std::shared_ptr<Result>;
         using FactoryType = SessionFactory;
    public:
        explicit SessionImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~SessionImpl() noexcept = 0;
        SessionImpl(const SessionImpl& rhs) = default;
        SessionImpl& operator=(const SessionImpl& rhs) = default;
        SessionImpl(SessionImpl&& rhs) noexcept = default;
        SessionImpl& operator=(SessionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] virtual MysqlxSchemaPtr GetMysqlxSchemaPtr();
        [[nodiscard]] virtual MysqlxSchemaPtr GetMysqlxSchemaPtr(int dbIndex);
        [[nodiscard]] virtual SchemaContainer GetSchemaContainer();

        [[nodiscard]] virtual ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement);
        [[nodiscard]] virtual ResultPtr ExecuteResult(const std::string& findStatement);
        [[nodiscard]] virtual ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
        virtual void Execute(const std::string& findStatement, int bindStatement);
        virtual void Execute(const std::string& findStatement, const std::string& bindStatement);
        virtual void Execute(const std::string& findStatement);

    private:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_IMPL_H
