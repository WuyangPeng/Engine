﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:49)

#include "Database/DatabaseExport.h"

#include "DatabaseEntity.h"
#include "Detail/DatabaseEntityImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseEntity)

Database::DatabaseEntity::DatabaseEntity(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, const BasisDatabaseContainer& key)
    : impl{ wrappersStrategy, databaseName, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseEntity::DatabaseEntity(const BasisDatabaseManager& entity)
    : impl{ entity }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseEntity)

Database::BasisDatabaseManager Database::DatabaseEntity::GetModify() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetModify();
}

Database::BasisDatabaseManager Database::DatabaseEntity::GetDelete() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDelete();
}

void Database::DatabaseEntity::ClearModify()
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ClearModify();
}

bool Database::DatabaseEntity::IsModify() const
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->IsModify();
}

void Database::DatabaseEntity::AddModify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->AddModify(basisDatabase);
}
