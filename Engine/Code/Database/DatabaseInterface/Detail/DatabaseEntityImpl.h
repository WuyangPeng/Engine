///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:19)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseEntityImpl
    {
    public:
        using ClassType = DatabaseEntityImpl;
        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        DatabaseEntityImpl(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, const BasisDatabaseContainer& key);
        explicit DatabaseEntityImpl(const BasisDatabaseManager& entity);

        CLASS_INVARIANT_DECLARE;

        void AddModify(const BasisDatabase& basisDatabase);
        void ClearModify();

        NODISCARD BasisDatabaseManager GetModify() const noexcept;
        NODISCARD BasisDatabaseManager GetDelete() const;

        NODISCARD bool IsModify() const;

    private:
        BasisDatabaseContainer entity;
        BasisDatabaseManager modify;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H