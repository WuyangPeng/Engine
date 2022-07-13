///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:13)

#include "Script/ScriptExport.h"

#include "ScriptDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

Script::ScriptDelayCopyUnsharedMacroImpl::ScriptDelayCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptDelayCopyUnsharedMacroImpl)

int Script::ScriptDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Script::ScriptDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    mCount = count;
}
