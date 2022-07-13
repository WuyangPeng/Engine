///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:41)

#include "Script/ScriptExport.h"

#include "ScriptDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/ScriptDelayCopyUnsharedMacroImpl.h"

Script::ScriptDelayCopyUnsharedMacro::ScriptDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptDelayCopyUnsharedMacro)

int Script::ScriptDelayCopyUnsharedMacro::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Script::ScriptDelayCopyUnsharedMacro::SetCount(int count)
{
    SCRIPT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Script, ScriptDelayCopyUnsharedMacro)