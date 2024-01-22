/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:46)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_IMPL_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"
#include "Database/DatabaseInterface/DatabaseInterfaceInternalFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseFlushImpl
    {
    public:
        using ClassType = DatabaseFlushImpl;
        using FactoryType = DatabaseFlushFactory;

        using DatabaseFlushSharedPtr = std::shared_ptr<ClassType>;
        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit DatabaseFlushImpl(ConfigurationStrategy configurationStrategy) noexcept;
        virtual ~DatabaseFlushImpl() noexcept = default;
        DatabaseFlushImpl(const DatabaseFlushImpl& rhs) = default;
        DatabaseFlushImpl& operator=(const DatabaseFlushImpl& rhs) = default;
        DatabaseFlushImpl(DatabaseFlushImpl&& rhs) noexcept = default;
        DatabaseFlushImpl& operator=(DatabaseFlushImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer) = 0;

        NODISCARD ConfigurationStrategy GetConfigurationStrategy() const noexcept;

        NODISCARD virtual BasisDatabaseManager SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const = 0;
        NODISCARD virtual ResultContainer SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const = 0;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;

        virtual void Wait() = 0;

    private:
        ConfigurationStrategy configurationStrategy;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_IMPL_H