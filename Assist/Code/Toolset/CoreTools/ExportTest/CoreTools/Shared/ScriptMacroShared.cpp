///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/15 19:13)

#include "Script/ScriptExport.h"

#include "ScriptMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/ScriptMacroSharedImpl.h"

Script::ScriptMacroShared::ScriptMacroShared(int count)
    : impl{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptMacroShared)

int Script::ScriptMacroShared::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Script::ScriptMacroShared::SetCount(int count) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Script::ScriptMacroShared::GetAddress() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}