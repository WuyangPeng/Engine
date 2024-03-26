/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:18)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportCopyUnsharedImplMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportCopyUnsharedImplMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ExportTest, ExportCopyUnsharedImplMacro)

ExportTest::ExportCopyUnsharedImplMacro::ExportCopyUnsharedImplMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportCopyUnsharedImplMacro)

int ExportTest::ExportCopyUnsharedImplMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::ExportCopyUnsharedImplMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
