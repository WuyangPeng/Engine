/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:17)

#include "Script/ScriptExport.h"

#include "ScriptMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

Script::ScriptMacroSharedImpl::ScriptMacroSharedImpl(int count) noexcept
    : count{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptMacroSharedImpl)

int Script::ScriptMacroSharedImpl::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return count;
}

void Script::ScriptMacroSharedImpl::SetCount(int aCount) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    count = aCount;
}
