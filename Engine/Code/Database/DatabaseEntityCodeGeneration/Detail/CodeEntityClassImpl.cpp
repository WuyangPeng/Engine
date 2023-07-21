///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/01 23:43)

#include "Database/DatabaseExport.h"

#include "CodeEntityClassImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::CodeEntityClassImpl::CodeEntityClassImpl(String entityClassName, String databaseName, FieldContainer codeEntity)
    : entityClassName{ std::move(entityClassName) },
      databaseName{ std::move(databaseName) },
      codeEntity{ std::move(codeEntity) }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的类名或数据库名称或代码实体容器为空。"));
    }
}

bool Database::CodeEntityClassImpl::IsValid() const noexcept
{
    return !entityClassName.empty() && !databaseName.empty() && !codeEntity.empty();
}

System::String Database::CodeEntityClassImpl::GetEntityClassName() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return entityClassName;
}

System::String Database::CodeEntityClassImpl::GetDatabaseName() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return databaseName;
}

Database::CodeEntityClassImpl::FieldContainerConstIter Database::CodeEntityClassImpl::GetBegin() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return codeEntity.cbegin();
}

Database::CodeEntityClassImpl::FieldContainerConstIter Database::CodeEntityClassImpl::GetEnd() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return codeEntity.cend();
}

System::String Database::CodeEntityClassImpl::GetKeyType() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    for (const auto element : codeEntity)
    {
        if (element.GetIndexType() == SYSTEM_TEXT("Key"))
        {
            return element.GetDataType();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到数据库的键值"))
}

System::String Database::CodeEntityClassImpl::GetKeyName() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    for (const auto element : codeEntity)
    {
        if (element.GetIndexType() == SYSTEM_TEXT("Key"))
        {
            return element.GetFieldName();
        }
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未找到数据库的键值"))
}

int Database::CodeEntityClassImpl::GetSize() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(codeEntity.size());
}
