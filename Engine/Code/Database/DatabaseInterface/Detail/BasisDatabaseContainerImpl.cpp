///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 13:43)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseContainerImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"

#include <algorithm>

Database::BasisDatabaseContainerImpl::BasisDatabaseContainerImpl(WrappersStrategy wrappersStrategy, std::string databaseName, ChangeType changeType, ObjectContainer key) noexcept
    : wrappersStrategy{ wrappersStrategy }, container{}, databaseName{ std::move(databaseName) }, changeType{ changeType }, key{ std::move(key) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseContainerImpl)

Database::WrappersStrategy Database::BasisDatabaseContainerImpl::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return wrappersStrategy;
}

void Database::BasisDatabaseContainerImpl::Modify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    const auto result = std::ranges::remove_if(container, [&basisDatabase](const auto& value) {
        return value.GetFieldName() == basisDatabase.GetFieldName();
    });

    container.erase(result.begin(), result.end());

    container.emplace_back(basisDatabase);
}

void Database::BasisDatabaseContainerImpl::Clear() noexcept
{
    DATABASE_CLASS_IS_VALID_9;

    container.clear();
    if (changeType == ChangeType::Insert)
    {
        changeType = ChangeType::Update;
    }
}

std::any Database::BasisDatabaseContainerImpl::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto result = std::ranges::find_if(container, [&fieldName](const auto& value) {
            return value.GetFieldName() == fieldName;
        });
        result != container.cend())
    {
        return result->GetAnyValue();
    }
    else
    {
        return std::any{};
    }
}

std::string Database::BasisDatabaseContainerImpl::GetDatabaseName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return databaseName;
}

Database::ChangeType Database::BasisDatabaseContainerImpl::GetChangeType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return changeType;
}

Database::BasisDatabaseContainerImpl::ObjectContainer Database::BasisDatabaseContainerImpl::GetKey() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return key;
}

Database::BasisDatabaseContainerImpl::ObjectContainer Database::BasisDatabaseContainerImpl::GetContainer() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container;
}
