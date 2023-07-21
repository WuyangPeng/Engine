///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/01 23:55)

#include "Database/DatabaseExport.h"

#include "CodeEntity.h"
#include "Detail/CodeEntityImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

Database::CodeEntity::CodeEntity(const String& fieldName, const String& dataType, const String& indexType)
    : impl{ fieldName, dataType, indexType }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeEntity)

System::String Database::CodeEntity::GetFieldName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetFieldName();
}

System::String Database::CodeEntity::GetDataType() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDataType();
}

System::String Database::CodeEntity::GetIndexType() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetIndexType();
}
