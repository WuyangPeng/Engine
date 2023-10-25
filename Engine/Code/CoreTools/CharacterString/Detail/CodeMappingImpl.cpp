///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:26)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMappingImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::CodeMappingImpl::CodeMappingImpl() noexcept
    : codeMapping{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CodeMappingImpl)

void CoreTools::CodeMappingImpl::Insert(const String& codeKey, const String& element)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    codeMapping.emplace(codeKey, element);
}

System::String CoreTools::CodeMappingImpl::GetElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = codeMapping.find(codeKey);
        iter != codeMapping.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到对应的key, key = ") + codeKey)
    }
}
