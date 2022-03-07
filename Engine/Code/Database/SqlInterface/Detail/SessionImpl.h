///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:13)

#ifndef DATABASE_SQL_INTERFACE_SESSION_IMPL_H
#define DATABASE_SQL_INTERFACE_SESSION_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/Result.h"
#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SessionImpl
    {
    public:
        using ClassType = SessionImpl;
        using FactoryType = SessionFactory;
        using MysqlxSchemaUniquePtr = std::unique_ptr<MysqlxSchema>;
        using SchemaUniquePtr = std::unique_ptr<Schema>;
        using SchemaContainer = std::vector<SchemaUniquePtr>;
        using ResultUniquePtr = std::shared_ptr<Result>;

    public:
        explicit SessionImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~SessionImpl() noexcept = 0;
        SessionImpl(const SessionImpl& rhs) noexcept = default;
        SessionImpl& operator=(const SessionImpl& rhs) noexcept = default;
        SessionImpl(SessionImpl&& rhs) noexcept = default;
        SessionImpl& operator=(SessionImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual MysqlxSchemaUniquePtr GetMysqlxSchema() const;
        NODISCARD virtual MysqlxSchemaUniquePtr GetMysqlxSchema(int dbIndex) const;
        NODISCARD virtual SchemaContainer GetSchemaContainer();

        NODISCARD virtual ResultUniquePtr ExecuteResult(const std::string& findStatement, int bindStatement);
        NODISCARD virtual ResultUniquePtr ExecuteResult(const std::string& findStatement);
        NODISCARD virtual ResultUniquePtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
        virtual void Execute(const std::string& findStatement, int bindStatement);
        virtual void Execute(const std::string& findStatement, const std::string& bindStatement);
        virtual void Execute(const std::string& findStatement);

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_IMPL_H
