﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:43)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/BasisDatabaseContainer.h"

#include <vector>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE DatabaseEntityImpl
    {
    public:
        using ClassType = DatabaseEntityImpl;
        using ObjectContainer = std::vector<BasisDatabase>;

    public:
        DatabaseEntityImpl(WrappersStrategy wrappersStrategy, const std::string& databaseName, const ObjectContainer& key);
        explicit DatabaseEntityImpl(BasisDatabaseContainer entity);

        CLASS_INVARIANT_DECLARE;

        void AddModify(const BasisDatabase& basisDatabase);
        void ClearModify();

        NODISCARD BasisDatabaseContainer GetModify() const noexcept;

    private:
        BasisDatabaseContainer entity;
        BasisDatabaseContainer modify;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_ENTITY_IMPL_H