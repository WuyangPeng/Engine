///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/01 23:43)

#include "Database/DatabaseExport.h"

#include "CodeEntityClass.h"
#include "Detail/CodeEntityClassImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::CodeEntityClass::CodeEntityClass(const String& entityClassName, const String& databaseName, const FieldContainer& codeEntity)
    : impl{ entityClassName, databaseName, codeEntity }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeEntityClass)

System::String Database::CodeEntityClass::GetEntityClassName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetEntityClassName();
}

System::String Database::CodeEntityClass::GetDatabaseName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDatabaseName();
}

Database::CodeEntityClassImpl::FieldContainerConstIter Database::CodeEntityClass::begin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetBegin();
}

Database::CodeEntityClassImpl::FieldContainerConstIter Database::CodeEntityClass::end() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetEnd();
}

System::String Database::CodeEntityClass::GetKeyType() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetKeyType();
}

System::String Database::CodeEntityClass::GetKeyName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetKeyName();
}

int Database::CodeEntityClass::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetSize();
}
