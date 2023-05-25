///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:41)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Database/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <any>
#include <memory>
#include <string>
#include <vector>

DATABASE_COPY_UNSHARED_EXPORT_IMPL(DatabaseEntity, DatabaseEntityImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseEntity
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DatabaseEntity);
        using ObjectContainer = std::vector<BasisDatabase>;
        using FieldNameContainer = std::vector<FieldName>;

    public:
        DatabaseEntity(WrappersStrategy wrappersStrategy, const std::string& databaseName, const ObjectContainer& key);
        explicit DatabaseEntity(const BasisDatabaseContainer& entity);
        virtual ~DatabaseEntity() noexcept = default;
        DatabaseEntity(const DatabaseEntity& rhs) = default;
        DatabaseEntity& operator=(const DatabaseEntity& rhs) = default;
        DatabaseEntity(DatabaseEntity&& rhs) noexcept = default;
        DatabaseEntity& operator=(DatabaseEntity&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD BasisDatabaseContainer GetModify() const noexcept;

        NODISCARD virtual FieldNameContainer GetFieldNameContainer() const = 0;

    protected:
        void AddModify(const BasisDatabase& basisDatabase);

        template <typename T>
        void AddModify(const std::string_view& fieldName, T value);

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_H