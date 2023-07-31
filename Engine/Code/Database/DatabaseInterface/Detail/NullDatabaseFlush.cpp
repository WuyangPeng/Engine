///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/23 13:38)

#include "Database/DatabaseExport.h"

#include "NullDatabaseFlush.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"
#include "Database/DatabaseInterface/BasisDatabaseManager.h"

Database::NullDatabaseFlush::NullDatabaseFlush(const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Database, NullDatabaseFlush)

void Database::NullDatabaseFlush::ChangeDatabase(int64_t userId, const BasisDatabaseManager& basisDatabaseContainer) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    System::UnusedFunction(userId, basisDatabaseContainer);
}

Database::BasisDatabaseManager Database::NullDatabaseFlush::SelectOne(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(fieldNameContainer);

    return BasisDatabaseManager{ basisDatabaseContainer.GetWrappersStrategy(), basisDatabaseContainer.GetDatabaseName(), ChangeType::Select, BasisDatabaseContainer::Create() };
}

Database::DatabaseFlushImpl::ResultContainer Database::NullDatabaseFlush::SelectAll(const BasisDatabaseManager& basisDatabaseContainer, const FieldNameContainer& fieldNameContainer) const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(basisDatabaseContainer, fieldNameContainer);

    return ResultContainer{};
}

void Database::NullDatabaseFlush::Wait() noexcept
{
    DATABASE_CLASS_IS_VALID_9;
}
