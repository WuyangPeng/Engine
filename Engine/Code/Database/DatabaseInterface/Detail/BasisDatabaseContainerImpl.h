///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:19)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/BasisDatabase.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE BasisDatabaseContainerImpl
    {
    public:
        using ClassType = BasisDatabaseContainerImpl;

        using ObjectContainer = std::vector<BasisDatabase>;
        using ObjectContainerConstIter = ObjectContainer::const_iterator;

    public:
        BasisDatabaseContainerImpl() noexcept;
        explicit BasisDatabaseContainerImpl(ObjectContainer container) noexcept;
        explicit BasisDatabaseContainerImpl(const BasisDatabase& basisDatabase);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ObjectContainer GetContainer() const;

        void Modify(const BasisDatabase& basisDatabase);

        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

        NODISCARD ObjectContainerConstIter begin() const noexcept;
        NODISCARD ObjectContainerConstIter end() const noexcept;

        NODISCARD int GetSize() const;

    private:
        ObjectContainer container;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_IMPL_H