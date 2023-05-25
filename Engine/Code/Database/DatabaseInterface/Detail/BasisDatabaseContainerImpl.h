///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:36)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/BasisDatabase.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE BasisDatabaseContainerImpl
    {
    public:
        using ClassType = BasisDatabaseContainerImpl;
        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        BasisDatabaseContainerImpl(WrappersStrategy wrappersStrategy, std::string databaseName, ChangeType changeType, ObjectContainer key) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;
        NODISCARD std::string GetDatabaseName() const;
        NODISCARD ChangeType GetChangeType() const noexcept;
        NODISCARD ObjectContainer GetKey() const;
        NODISCARD ObjectContainer GetContainer() const;

        void Modify(const BasisDatabase& basisDatabase);

        void Clear() noexcept;

        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

    private:
        WrappersStrategy wrappersStrategy;
        ObjectContainer container;
        std::string databaseName;
        ChangeType changeType;
        ObjectContainer key;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H