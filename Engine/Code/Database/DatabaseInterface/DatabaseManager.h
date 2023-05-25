///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 13:49)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Database/Configuration/ConfigurationFwd.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(DatabaseManager, DatabaseManagerImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseManager
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DatabaseManager);
        using ResultContainer = std::vector<BasisDatabaseContainer>;
        using String = System::String;
        using FieldNameContainer = std::vector<FieldName>;

    public:
        explicit DatabaseManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseContainer& basisDatabaseContainer);

        NODISCARD BasisDatabaseContainer SelectOne(const String& databaseIndex, const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;
        NODISCARD ResultContainer SelectAll(const String& databaseIndex, const BasisDatabaseContainer& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H