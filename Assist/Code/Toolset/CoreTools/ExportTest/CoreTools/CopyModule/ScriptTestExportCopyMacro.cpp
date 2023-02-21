///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:52)

#include "Script/ScriptExport.h"

#include "ScriptTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/ScriptClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/ScriptTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Script, ScriptTestExportCopyMacro)

Script::ScriptTestExportCopyMacro::ScriptTestExportCopyMacro(int count)
    : impl{ count }
{
    SCRIPT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Script, ScriptTestExportCopyMacro)

int Script::ScriptTestExportCopyMacro::GetCount() const noexcept
{
    SCRIPT_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Script::ScriptTestExportCopyMacro::SetCount(int count) noexcept
{
    SCRIPT_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
