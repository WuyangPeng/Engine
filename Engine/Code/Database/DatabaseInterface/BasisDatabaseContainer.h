///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 22:20)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <any>

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(BasisDatabaseContainer, BasisDatabaseContainerImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE BasisDatabaseContainer
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(BasisDatabaseContainer);
        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        BasisDatabaseContainer(WrappersStrategy wrappersStrategy, const std::string& databaseName, ChangeType changeType, const ObjectContainer& key);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WrappersStrategy GetWrappersStrategy() const noexcept;
        NODISCARD std::string GetDatabaseName() const;
        NODISCARD ChangeType GetChangeType() const noexcept;
        NODISCARD ObjectContainer GetKey() const;
        NODISCARD ObjectContainer GetContainer() const;

        void Modify(const BasisDatabase& basisDatabase);

        void Clear();

        template <DataType Type>
        NODISCARD typename DataTypeTraits<Type>::Type GetValue(const std::string_view& fieldName) const;

    private:
        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H