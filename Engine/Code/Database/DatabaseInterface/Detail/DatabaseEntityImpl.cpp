///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:43)

#include "Database/DatabaseExport.h"

#include "DatabaseEntityImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Database/DatabaseInterface/BasisDatabase.h"

Database::DatabaseEntityImpl::DatabaseEntityImpl(WrappersStrategy wrappersStrategy, const std::string& databaseName, const ObjectContainer& key)
    : entity{ wrappersStrategy, databaseName, ChangeType::Select, key }, modify{ wrappersStrategy, databaseName, ChangeType::Insert, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseEntityImpl::DatabaseEntityImpl(BasisDatabaseContainer entity)
    : entity{ std::move(entity) }, modify{ this->entity.GetWrappersStrategy(), this->entity.GetDatabaseName(), ChangeType::Update, this->entity.GetKey() }
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

Database::BasisDatabaseContainer Database::DatabaseEntityImpl::GetModify() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return modify;
}
