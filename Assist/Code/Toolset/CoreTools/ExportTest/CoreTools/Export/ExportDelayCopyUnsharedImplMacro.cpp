///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:30)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "ExportDelayCopyUnsharedImplMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/ExportDelayCopyUnsharedImplMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(ExportTest, ExportDelayCopyUnsharedImplMacro)

ExportTest::ExportDelayCopyUnsharedImplMacro::ExportDelayCopyUnsharedImplMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, ExportDelayCopyUnsharedImplMacro)

int ExportTest::ExportDelayCopyUnsharedImplMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::ExportDelayCopyUnsharedImplMacro::SetCount(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
