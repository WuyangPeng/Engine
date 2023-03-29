///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:04)

#include "Script/ScriptExport.h"

#include "ScriptNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

Script::ScriptNonCopyMacroImpl::ScriptNonCopyMacroImpl(int count) noexcept
    : count{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptNonCopyMacroImpl)

int Script::ScriptNonCopyMacroImpl::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return count;
}

void Script::ScriptNonCopyMacroImpl::SetCount(int aCount) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    count = aCount;
}
