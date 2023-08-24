///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:49)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseManager.h"
#include "Detail/BasisDatabaseManagerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, BasisDatabaseManager)

Database::BasisDatabaseManager::BasisDatabaseManager(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, ChangeType changeType, const BasisDatabaseContainer& key)
    : impl{ wrappersStrategy, databaseName, changeType, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseManager::BasisDatabaseManager(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, ChangeType changeType, const BasisDatabaseContainer& key, const BasisDatabaseContainer& database)
    : impl{ wrappersStrategy, databaseName, changeType, key, database }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseManager)

Database::WrappersStrategy Database::BasisDatabaseManager::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetWrappersStrategy();
}

std::string_view Database::BasisDatabaseManager::GetDatabaseName() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDatabaseName();
}

Database::ChangeType Database::BasisDatabaseManager::GetChangeType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetChangeType();
}

Database::BasisDatabaseContainer Database::BasisDatabaseManager::GetKey() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetKey();
}

Database::BasisDatabaseContainer Database::BasisDatabaseManager::GetDatabase() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDatabase();
}

void Database::BasisDatabaseManager::Modify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Modify(basisDatabase);
}

void Database::BasisDatabaseManager::Set(const BasisDatabaseContainer& database)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Set(database);
}

void Database::BasisDatabaseManager::Clear()
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Clear();
}

bool Database::BasisDatabaseManager::IsModify() const
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->IsModify();
}

std::any Database::BasisDatabaseManager::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetAnyValue(fieldName);
}
