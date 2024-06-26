﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:47)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Database/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <any>
#include <memory>
#include <vector>

DATABASE_COPY_UNSHARED_EXPORT_IMPL(DatabaseEntity, DatabaseEntityImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseEntity
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DatabaseEntity);

        using ObjectContainer = std::vector<BasisDatabase>;
        using DatabaseFieldContainer = std::vector<DatabaseField>;

    public:
        DatabaseEntity(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, const BasisDatabaseContainer& key);
        explicit DatabaseEntity(const BasisDatabaseManager& entity);
        virtual ~DatabaseEntity() noexcept = default;
        DatabaseEntity(const DatabaseEntity& rhs) = default;
        DatabaseEntity& operator=(const DatabaseEntity& rhs) = default;
        DatabaseEntity(DatabaseEntity&& rhs) noexcept = default;
        DatabaseEntity& operator=(DatabaseEntity&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD BasisDatabaseManager GetModify() const noexcept;
        NODISCARD BasisDatabaseManager GetDelete() const;

        void ClearModify();

        NODISCARD bool IsModify() const;

    protected:
        void AddModify(const BasisDatabase& basisDatabase);

        template <typename T>
        void AddModify(const std::string_view& fieldName, T value);

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H