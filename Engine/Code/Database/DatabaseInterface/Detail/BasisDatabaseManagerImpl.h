///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:19)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_IMPL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE BasisDatabaseManagerImpl
    {
    public:
        using ClassType = BasisDatabaseManagerImpl;

        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        BasisDatabaseManagerImpl(WrappersStrategy wrappersStrategy,
                                 const std::string_view& databaseName,
                                 ChangeType changeType,
                                 BasisDatabaseContainer key);

        BasisDatabaseManagerImpl(WrappersStrategy wrappersStrategy,
                                 const std::string_view& databaseName,
                                 ChangeType changeType,
                                 BasisDatabaseContainer key,
                                 BasisDatabaseContainer database) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;
        NODISCARD std::string_view GetDatabaseName() const noexcept;
        NODISCARD ChangeType GetChangeType() const noexcept;
        NODISCARD BasisDatabaseContainer GetKey() const noexcept;
        NODISCARD BasisDatabaseContainer GetDatabase() const noexcept;

        void Modify(const BasisDatabase& basisDatabase);
        void Set(const BasisDatabaseContainer& aDatabase) noexcept;

        void Clear();

        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

        NODISCARD bool IsModify() const;

    private:
        WrappersStrategy wrappersStrategy;
        BasisDatabaseContainer database;
        std::string_view databaseName;
        ChangeType changeType;
        BasisDatabaseContainer key;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_MANAGER_IMPL_H