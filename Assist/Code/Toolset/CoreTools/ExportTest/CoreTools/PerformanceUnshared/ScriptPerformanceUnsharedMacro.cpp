///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/14 16:16)

#include "Script/ScriptExport.h"

#include "ScriptPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/ScriptPerformanceUnsharedMacroImpl.h"

Script::ScriptPerformanceUnsharedMacro::ScriptPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptPerformanceUnsharedMacro)

int Script::ScriptPerformanceUnsharedMacro::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}