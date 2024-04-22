/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/29 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMapping.h"
#include "Detail/CodeMappingImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CodeMapping)

CoreTools::CodeMapping CoreTools::CodeMapping::Create()
{
    return CodeMapping{ DisableNotThrow::Disable };
}

CoreTools::CodeMapping::CodeMapping(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CodeMapping)

void CoreTools::CodeMapping::Insert(const String& codeKey, const String& element)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Insert(codeKey, element);
}

System::String CoreTools::CodeMapping::GetElement(const String& codeKey) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetElement(codeKey);
}
