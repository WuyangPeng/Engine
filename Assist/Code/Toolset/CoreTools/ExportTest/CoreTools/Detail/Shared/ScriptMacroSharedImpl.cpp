///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/13 22:03)

#include "Script/ScriptExport.h"

#include "ScriptMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"

Script::ScriptMacroSharedImpl::ScriptMacroSharedImpl(int count) noexcept
    : m_Count{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptMacroSharedImpl)

int Script::ScriptMacroSharedImpl::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Script::ScriptMacroSharedImpl::SetCount(int count) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    m_Count = count;
}
