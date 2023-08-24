///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:49)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseContainer.h"
#include "Detail/BasisDatabaseContainerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Database, BasisDatabaseContainer)

Database::BasisDatabaseContainer Database::BasisDatabaseContainer::Create()
{
    return BasisDatabaseContainer{ CoreTools::DisableNotThrow::Disable };
}

Database::BasisDatabaseContainer::BasisDatabaseContainer(const BasisDatabase& basisDatabase)
    : impl{ basisDatabase }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseContainer::BasisDatabaseContainer(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabaseContainer::BasisDatabaseContainer(const ObjectContainer& container)
    : impl{ container }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabaseContainer)

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

void Database::BasisDatabaseContainer::Set(const ObjectContainer& container)
{
    DATABASE_CLASS_IS_VALID_9;

    // 直接创建新的BasisDatabaseContainerImpl，否则会先执行复制操作再设置。
    impl = PackageType{ container };
}

void Database::BasisDatabaseContainer::Clear()
{
    DATABASE_CLASS_IS_VALID_9;

    // 直接创建空的BasisDatabaseContainerImpl，否则会先执行复制操作再清除。
    impl = PackageType{ CoreTools::ImplCreateUseDefaultConstruction::Default };
}

std::any Database::BasisDatabaseContainer::GetAnyValue(const std::string_view& fieldName) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetAnyValue(fieldName);
}

Database::BasisDatabaseContainer::ObjectContainerConstIter Database::BasisDatabaseContainer::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->begin();
}

Database::BasisDatabaseContainer::ObjectContainerConstIter Database::BasisDatabaseContainer::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->end();
}

int Database::BasisDatabaseContainer::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}
