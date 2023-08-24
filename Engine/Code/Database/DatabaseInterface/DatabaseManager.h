///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:21)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Database/DatabaseInterface/DataTypeTraits.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(DatabaseManager, DatabaseManagerImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE DatabaseManager
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DatabaseManager);

        using ResultContainer = std::vector<BasisDatabaseManager>;
        using String = System::String;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit DatabaseManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;
        NODISCARD ResultContainer SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;

    private:
        PackageType impl;
    };

}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_H