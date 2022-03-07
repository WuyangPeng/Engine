///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 14:09)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
#define DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"
#include "Database/SqlInterface/SqlInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE SchemaImpl
    {
    public:
        using ClassType = SchemaImpl;
        using FactoryType = SchemaFactory;
        using MysqlxCollectionUniquePtr = std::unique_ptr<MysqlxCollection>;
        using MysqlxTableUniquePtr = std::unique_ptr<MysqlxTable>;

    public:
        explicit SchemaImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~SchemaImpl() noexcept = 0;
        SchemaImpl(const SchemaImpl& rhs) = default;
        SchemaImpl& operator=(const SchemaImpl& rhs) = default;
        SchemaImpl(SchemaImpl&& rhs) noexcept = default;
        SchemaImpl& operator=(SchemaImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual MysqlxCollectionUniquePtr GetCollection(const std::string& collectionName) const;
        NODISCARD virtual MysqlxTableUniquePtr GetTable(const std::string& tableonName) const;

    public:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
