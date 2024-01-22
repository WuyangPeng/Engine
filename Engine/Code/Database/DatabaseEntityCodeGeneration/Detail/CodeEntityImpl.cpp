/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 13:51)

#include "Database/DatabaseExport.h"

#include "CodeEntityImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::CodeEntityImpl::CodeEntityImpl(String fieldName, String dataType, String indexType)
    : fieldName{ std::move(fieldName) },
      dataType{ std::move(dataType) },
      indexType{ std::move(indexType) }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("������ֶ�������������Ϊ�ա�"));
    }
}

bool Database::CodeEntityImpl::IsValid() const noexcept
{
    return !fieldName.empty() && !dataType.empty();
}

System::String Database::CodeEntityImpl::GetFieldName() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return fieldName;
}

System::String Database::CodeEntityImpl::GetDataType() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return dataType;
}

System::String Database::CodeEntityImpl::GetIndexType() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return indexType;
}
