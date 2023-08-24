///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:19)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_IMPL_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_IMPL_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <map>
#include <string>
#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseManagerImpl
    {
    public:
        using ClassType = DatabaseManagerImpl;

        using String = System::String;
        using ResultContainer = std::vector<BasisDatabaseManager>;
        using FieldNameContainer = std::vector<DatabaseField>;

    public:
        explicit DatabaseManagerImpl(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        void ChangeDatabase(const String& databaseIndex, int64_t userId, const BasisDatabaseManager& basisDatabaseContainer);

        NODISCARD BasisDatabaseManager SelectOne(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;
        NODISCARD ResultContainer SelectAll(const String& databaseIndex, const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const;

    private:
        using DatabaseFlushSharedPtr = std::shared_ptr<DatabaseFlush>;
        using Container = std::map<String, DatabaseFlushSharedPtr>;

    private:
        void LoadFlush(const std::string& fileName);

    private:
        Container databaseFlush;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_MANAGER_IMPL_H