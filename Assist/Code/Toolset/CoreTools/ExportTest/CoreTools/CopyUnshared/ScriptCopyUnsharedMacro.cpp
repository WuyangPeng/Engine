///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/17 09:13)

#include "Script/ScriptExport.h"

#include "ScriptCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/ScriptCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Script, ScriptCopyUnsharedMacro)

Script::ScriptCopyUnsharedMacro::ScriptCopyUnsharedMacro(int count)
    : impl{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptCopyUnsharedMacro)

int Script::ScriptCopyUnsharedMacro::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Script::ScriptCopyUnsharedMacro::SetCount(int count) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Script::ScriptCopyUnsharedMacro::GetAddress() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}