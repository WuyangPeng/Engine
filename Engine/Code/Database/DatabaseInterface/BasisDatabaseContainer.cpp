///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 22:21)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseContainer.h"
#include "Detail/BasisDatabaseContainerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, BasisDatabaseContainer)

Database::BasisDatabaseContainer::BasisDatabaseContainer(WrappersStrategy wrappersStrategy, const std::string& databaseName, ChangeType changeType, const ObjectContainer& key)
    : impl{ wrappersStrategy, databaseName, changeType, key }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseContainer)

Database::WrappersStrategy Database::BasisDatabaseContainer::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetWrappersStrategy();
}

std::string Database::BasisDatabaseContainer::GetDatabaseName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDatabaseName();
}

Database::ChangeType Database::BasisDatabaseContainer::GetChangeType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetChangeType();
}

Database::BasisDatabaseContainer::ObjectContainer Database::BasisDatabaseContainer::GetKey() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetKey();
}

Database::BasisDatabaseContainer::ObjectContainer Database::BasisDatabaseContainer::GetContainer() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetContainer();
}

void Database::BasisDatabaseContainer::Modify(const BasisDatabase& basisDatabase)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Modify(basisDatabase);
}

void Database::BasisDatabaseContainer::Clear()
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Clear();
}

std::any Database::BasisDatabaseContainer::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetAnyValue(fieldName);
}
