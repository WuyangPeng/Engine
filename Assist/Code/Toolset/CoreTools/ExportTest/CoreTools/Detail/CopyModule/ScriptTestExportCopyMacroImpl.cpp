/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:04)

#include "Script/ScriptExport.h"

#include "ScriptTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

Script::ScriptTestExportCopyMacroImpl::ScriptTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptTestExportCopyMacroImpl)

int Script::ScriptTestExportCopyMacroImpl::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return count;
}

void Script::ScriptTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    count = aCount;
}
