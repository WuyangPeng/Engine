///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/02 18:10)

#include "Database/DatabaseExport.h"

#include "CodeMappingImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::CodeMappingImpl::CodeMappingImpl() noexcept
    : codeMapping{}
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CodeMappingImpl)

void Database::CodeMappingImpl::Insert(const String& codeKey, const String& element)
{
    DATABASE_CLASS_IS_VALID_9;

    codeMapping.emplace(codeKey, element);
}

System::String Database::CodeMappingImpl::GetElement(const String& codeKey) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto iter = codeMapping.find(codeKey);

    if (iter != codeMapping.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ�����Ӧ��key, key = ") + codeKey)
    }
}
