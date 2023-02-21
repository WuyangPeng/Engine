///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:21)

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
