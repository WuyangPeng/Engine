///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:43)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"

#include <algorithm>

Database::BasisDatabaseManagerImpl::BasisDatabaseManagerImpl(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, ChangeType changeType, BasisDatabaseContainer key)
    : wrappersStrategy{ wrappersStrategy }, database{ BasisDatabaseContainer::Create() }, databaseName{ databaseName }, changeType{ changeType }, key{ std::move(key) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseManagerImpl::BasisDatabaseManagerImpl(WrappersStrategy wrappersStrategy, const std::string_view& databaseName, ChangeType changeType, BasisDatabaseContainer key, BasisDatabaseContainer database) noexcept
    : wrappersStrategy{ wrappersStrategy }, database{ std::move(database) }, databaseName{ databaseName }, changeType{ changeType }, key{ std::move(key) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseManagerImpl)

Database::WrappersStrategy Database::BasisDatabaseManagerImpl::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return wrappersStrategy;
}

void Database::BasisDatabaseManagerImpl::Modify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    database.Modify(basisDatabase);
}

void Database::BasisDatabaseManagerImpl::Set(const BasisDatabaseContainer& aDatabase) noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    database = aDatabase;
}

void Database::BasisDatabaseManagerImpl::Clear()
{
    DATABASE_CLASS_IS_VALID_9;

    database.Clear();
    if (changeType == ChangeType::Insert)
    {
        changeType = ChangeType::Update;
    }
}

std::any Database::BasisDatabaseManagerImpl::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return database.GetAnyValue(fieldName);
}

bool Database::BasisDatabaseManagerImpl::IsModify() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return 0 < database.GetSize();
}

std::string_view Database::BasisDatabaseManagerImpl::GetDatabaseName() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return databaseName;
}

Database::ChangeType Database::BasisDatabaseManagerImpl::GetChangeType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return changeType;
}

Database::BasisDatabaseContainer Database::BasisDatabaseManagerImpl::GetKey() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return key;
}

Database::BasisDatabaseContainer Database::BasisDatabaseManagerImpl::GetDatabase() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return database;
}
