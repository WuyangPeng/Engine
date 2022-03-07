///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:12)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_H
#define DATABASE_SQL_INTERFACE_SCHEMA_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Fwd/MysqlConnectorFwd.h"
#include "Database/SqlInterface/SqlInterfaceFwd.h"

DATABASE_NON_COPY_EXPORT_IMPL(SchemaImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE Schema final
    {
    public:
        NON_COPY_TYPE_DECLARE(Schema);
        using MysqlxCollectionUniquePtr = std::unique_ptr<MysqlxCollection>;
        using MysqlxTableUniquePtr = std::unique_ptr<MysqlxTable>;

    public:
        explicit Schema(const Session& session);
        Schema(const Session& session, int dbIndex);
        Schema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;
        NODISCARD MysqlxCollectionUniquePtr GetCollection(const std::string& collectionName) const;
        NODISCARD MysqlxTableUniquePtr GetTable(const std::string& tableonName) const;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_H
