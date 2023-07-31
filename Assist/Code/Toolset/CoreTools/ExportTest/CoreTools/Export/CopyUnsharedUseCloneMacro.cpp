///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:14)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "CopyUnsharedUseCloneMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Export/CopyUnsharedUseCloneMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(ExportTest, CopyUnsharedUseCloneMacro)

ExportTest::CopyUnsharedUseCloneMacro::CopyUnsharedUseCloneMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, CopyUnsharedUseCloneMacro)

int ExportTest::CopyUnsharedUseCloneMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void ExportTest::CopyUnsharedUseCloneMacro::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
