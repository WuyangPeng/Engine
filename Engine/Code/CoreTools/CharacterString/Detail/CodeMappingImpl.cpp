///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/15 10:25)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ�����Ӧ��key, key = ") + codeKey)
    }
}