/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:46)

#ifndef DATABASE_DATABASE_INTERFACE_NULL_DATABASE_FLUSH_H
#define DATABASE_DATABASE_INTERFACE_NULL_DATABASE_FLUSH_H

#include "Database/DatabaseDll.h"

#include "DatabaseFlushImpl.h"
#include "Database/Configuration/ConfigurationStrategy.h"
#include "Database/DatabaseInterface/DatabaseFlush.h"
#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

namespace Database
{
    class DATABASE_HIDDEN_DECLARE NullDatabaseFlush final : public DatabaseFlushImpl
    {
    public:
        using ClassType = NullDatabaseFlush;
        using ParentType = DatabaseFlushImpl;

    public:
        explicit NullDatabaseFlush(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer) noexcept override;

        NODISCARD BasisDatabaseManager SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const override;
        NODISCARD ResultContainer SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const noexcept override;

        void Wait() noexcept override;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_NULL_DATABASE_FLUSH_H