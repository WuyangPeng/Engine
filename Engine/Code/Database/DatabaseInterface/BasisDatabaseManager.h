/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:46)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_H

#include "Database/DatabaseDll.h"

#include "System/Helper/PragmaWarning/CallTraits.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <any>

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(BasisDatabaseManager, BasisDatabaseManagerImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE BasisDatabaseManager
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(BasisDatabaseManager);
        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        BasisDatabaseManager(WrappersStrategy wrappersStrategy,
                             const std::string_view& databaseName,
                             ChangeType changeType,
                             const BasisDatabaseContainer& key);

        BasisDatabaseManager(WrappersStrategy wrappersStrategy,
                             const std::string_view& databaseName,
                             ChangeType changeType,
                             const BasisDatabaseContainer& key,
                             const BasisDatabaseContainer& database);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;
        NODISCARD std::string_view GetDatabaseName() const noexcept;
        NODISCARD ChangeType GetChangeType() const noexcept;
        NODISCARD BasisDatabaseContainer GetKey() const noexcept;
        NODISCARD BasisDatabaseContainer GetDatabase() const noexcept;

        void Modify(const BasisDatabase& basisDatabase);
        void Set(const BasisDatabaseContainer& database);

        void Clear();

        template <DataType Type>
        NODISCARD typename DataTypeTraits<Type>::Type GetValue(const std::string_view& fieldName, typename boost::call_traits<typename DataTypeTraits<Type>::Type>::param_type defaultValue = typename DataTypeTraits<Type>::Type{}) const;

        NODISCARD bool IsModify() const;

    private:
        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

    private:
        PackageType impl;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_H