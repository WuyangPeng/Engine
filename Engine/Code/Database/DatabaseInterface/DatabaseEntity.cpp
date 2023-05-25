///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:41)

#include "Database/DatabaseExport.h"

#include "DatabaseEntity.h"
#include "Detail/DatabaseEntityImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, DatabaseEntity)

Database::DatabaseEntity::DatabaseEntity(WrappersStrategy wrappersStrategy, const std::string& databaseName, const ObjectContainer& key)
    : impl{ wrappersStrategy, databaseName, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseEntity::DatabaseEntity(const BasisDatabaseContainer& entity)
    : impl{ entity }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseEntity)

Database::BasisDatabaseContainer Database::DatabaseEntity::GetModify() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetModify();
}

void Database::DatabaseEntity::AddModify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->AddModify(basisDatabase);
}