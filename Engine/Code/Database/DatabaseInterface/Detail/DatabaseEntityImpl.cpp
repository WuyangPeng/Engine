///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:23)

#include "Database/DatabaseExport.h"

#include "DatabaseEntityImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"
#include "Database/DatabaseInterface/BasisDatabaseContainer.h"

Database::DatabaseEntityImpl::DatabaseEntityImpl(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, const BasisDatabaseContainer& key)
    : entity{ key }, modify{ wrappersStrategy, databaseName, ChangeType::Insert, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseEntityImpl::DatabaseEntityImpl(const BasisDatabaseManager& entity)
    : entity{ entity.GetDatabase() }, modify{ entity.GetWrappersStrategy(), entity.GetDatabaseName(), ChangeType::Update, entity.GetKey() }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseEntityImpl)

void Database::DatabaseEntityImpl::AddModify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    entity.Modify(basisDatabase);
    modify.Modify(basisDatabase);
}

void Database::DatabaseEntityImpl::ClearModify()
{
    DATABASE_CLASS_IS_VALID_9;

    modify.Clear();
}

Database::BasisDatabaseManager Database::DatabaseEntityImpl::GetModify() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return modify;
}

Database::BasisDatabaseManager Database::DatabaseEntityImpl::GetDelete() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return BasisDatabaseManager{ modify.GetWrappersStrategy(), modify.GetDatabaseName(), ChangeType::Delete, modify.GetKey() };
}

bool Database::DatabaseEntityImpl::IsModify() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return modify.IsModify();
}
