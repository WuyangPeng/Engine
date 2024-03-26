/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 09:59)

#include "CoreTools/CoreToolsExport.h"

#include "ExportCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/ExportCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ExportCopyUnsharedMacro)

CoreTools::ExportCopyUnsharedMacro::ExportCopyUnsharedMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExportCopyUnsharedMacro)

int CoreTools::ExportCopyUnsharedMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void CoreTools::ExportCopyUnsharedMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* CoreTools::ExportCopyUnsharedMacro::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}