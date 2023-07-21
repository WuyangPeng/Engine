///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:10)

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
        THROW_EXCEPTION(SYSTEM_TEXT("找不到对应的key, key = ") + codeKey)
    }
}
