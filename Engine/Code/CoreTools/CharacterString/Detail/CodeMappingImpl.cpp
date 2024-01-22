/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:21)

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
        THROW_EXCEPTION(SYSTEM_TEXT("Ԫ���Ѵ���, key = ") + codeKey)
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
        THROW_EXCEPTION(SYSTEM_TEXT("�Ҳ�����Ӧ��key, key = ") + codeKey)
    }
}
