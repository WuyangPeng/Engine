///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.10 (2023/05/25 17:58)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Contract/ContractFwd.h"
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
        using ObjectContainerConstIter = ObjectContainer::const_iterator;

    public:
        NODISCARD static BasisDatabaseContainer Create();
        explicit BasisDatabaseContainer(const BasisDatabase& basisDatabase);
        explicit BasisDatabaseContainer(const ObjectContainer& container);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ObjectContainer GetContainer() const;

        void Modify(const BasisDatabase& basisDatabase);
        void Set(const ObjectContainer& container);

        void Clear();

        NODISCARD std::any GetAnyValue(const std::string_view& fieldName) const;

        NODISCARD ObjectContainerConstIter begin() const noexcept;
        NODISCARD ObjectContainerConstIter end() const noexcept;

        NODISCARD int GetSize() const;

    private:
        explicit BasisDatabaseContainer(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_CONTAINER_H