/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:21)

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

    if (!codeMapping.emplace(codeKey, element).second)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("元素已存在, key = ") + codeKey)
    }
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
