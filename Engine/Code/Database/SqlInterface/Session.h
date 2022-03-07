///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:18)

#ifndef DATABASE_SQL_INTERFACE_SESSION_H
#define DATABASE_SQL_INTERFACE_SESSION_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Result.h"
#include "Schema.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

DATABASE_NON_COPY_EXPORT_IMPL(SessionImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Session final
    {
    public:
        NON_COPY_TYPE_DECLARE(Session);
        using MysqlxSchemaUniquePtr = std::unique_ptr<MysqlxSchema>;
        using SchemaUniquePtr = std::unique_ptr<Schema>;
        using SchemaContainer = std::vector<SchemaUniquePtr>;
        using ResultPtr = std::shared_ptr<Result>;

    public:
        explicit Session(const ConfigurationStrategy& configurationStrategy);
        explicit Session(const DatabaseObject& databaseObject);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD SchemaContainer GetSchemaContainer();

        NODISCARD ResultPtr ExecuteResult(const std::string& findStatement, int bindStatement);
        NODISCARD ResultPtr ExecuteResult(const std::string& findStatement, const std::string& bindStatement);
        NODISCARD ResultPtr ExecuteResult(const std::string& findStatement);
        void Execute(const std::string& findStatement, int bindStatement);
        void Execute(const std::string& findStatement, const std::string& bindStatement);
        void Execute(const std::string& findStatement);

        NODISCARD MysqlxSchemaUniquePtr GetMysqlxSchema() const;
        NODISCARD MysqlxSchemaUniquePtr GetMysqlxSchema(int dbIndex) const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SESSION_H
