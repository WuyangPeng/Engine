///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:45)

#include "CoreTools/CoreToolsExport.h"

#include "CodeMapping.h"
#include "Detail/CodeMappingImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CodeMapping)

CoreTools::CodeMapping CoreTools::CodeMapping::Create()
{
    return CodeMapping{ CoreTools::DisableNotThrow::Disable };
}

CoreTools::CodeMapping::CodeMapping(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
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
