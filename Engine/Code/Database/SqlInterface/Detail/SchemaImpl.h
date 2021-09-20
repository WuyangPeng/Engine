//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 9:52)

#ifndef DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
#define DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/MysqlConnectorWrappers/Using/MysqlConnectorUsing.h"

namespace Database
{
    class SchemaFactory;
    class DATABASE_HIDDEN_DECLARE SchemaImpl
    {
    public:
        using ClassType = SchemaImpl;
        using ImplTypePtr = std::shared_ptr<ClassType>;
        using MysqlxCollectionPtr = std::unique_ptr<MysqlxCollection>;
        using MysqlxTablePtr = std::unique_ptr<MysqlxTable>;
        using FactoryType = SchemaFactory;

    public:
        explicit SchemaImpl(const ConfigurationStrategy& configurationStrategy) noexcept;
        virtual ~SchemaImpl() noexcept = 0;
        SchemaImpl(const SchemaImpl& rhs) = default;
        SchemaImpl& operator=(const SchemaImpl& rhs) = default;
        SchemaImpl(SchemaImpl&& rhs) noexcept = default;
        SchemaImpl& operator=(SchemaImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        [[nodiscard]] virtual MysqlxCollectionPtr GetCollection(const std::string& collectionName);
        [[nodiscard]] virtual MysqlxTablePtr GetTable(const std::string& tableonName);

    public:
        ConfigurationStrategy m_ConfigurationStrategy;
    };
}

#endif  // DATABASE_SQL_INTERFACE_SCHEMA_IMPL_H
