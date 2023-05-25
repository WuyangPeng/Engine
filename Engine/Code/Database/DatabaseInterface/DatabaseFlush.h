///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 13:51)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_H

#include "Database/DatabaseDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

DATABASE_NON_COPY_EXPORT_IMPL(DatabaseFlushImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseFlush
    {
    public:
        NON_COPY_TYPE_DECLARE(DatabaseFlush);
        using ResultContainer = std::vector<BasisDatabaseContainer>;
        using FieldNameContainer = std::vector<FieldName>;

    public:
        explicit DatabaseFlush(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(int64_t userId, const BasisDatabaseContainer& basisDatabaseContainer);

        NODISCARD BasisDatabaseContainer SelectOne(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;
        NODISCARD ResultContainer SelectAll(const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_FLUSH_H