///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:22)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseContainerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/BasisDatabaseDetail.h"

#include <algorithm>

Database::BasisDatabaseContainerImpl::BasisDatabaseContainerImpl() noexcept
    : container{}
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseContainerImpl::BasisDatabaseContainerImpl(ObjectContainer container) noexcept
    : container{ std::move(container) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseContainerImpl::BasisDatabaseContainerImpl(const BasisDatabase& basisDatabase)
    : container{ basisDatabase }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseContainerImpl)

std::any Database::BasisDatabaseContainerImpl::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto result = std::ranges::find_if(container, [&fieldName](const auto& element) {
            return element.GetFieldName() == fieldName;
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

Database::BasisDatabaseContainerImpl::ObjectContainerConstIter Database::BasisDatabaseContainerImpl::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.cbegin();
}

Database::BasisDatabaseContainerImpl::ObjectContainerConstIter Database::BasisDatabaseContainerImpl::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container.cend();
}

int Database::BasisDatabaseContainerImpl::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}

Database::BasisDatabaseContainerImpl::ObjectContainer Database::BasisDatabaseContainerImpl::GetContainer() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return container;
}

void Database::BasisDatabaseContainerImpl::Modify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    const auto result = std::ranges::remove_if(container, [&basisDatabase](const auto& element) {
        return element.GetFieldName() == basisDatabase.GetFieldName();
    });

    container.erase(result.begin(), result.end());

    container.emplace_back(basisDatabase);
}