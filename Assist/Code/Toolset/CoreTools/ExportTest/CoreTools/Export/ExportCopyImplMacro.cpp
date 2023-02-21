///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:30)

#include "CoreTools/CoreToolsExport.h"

#include "ExportCopyImplMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportCopyImplMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ExportCopyImplMacro)

CoreTools::ExportCopyImplMacro::ExportCopyImplMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExportCopyImplMacro)

int CoreTools::ExportCopyImplMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void CoreTools::ExportCopyImplMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
