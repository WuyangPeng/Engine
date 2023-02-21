///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:06)

#include "Toolset/CoreTools/ExportTest/ExportTestExport.h"

#include "CopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

ExportTest::CopyUnsharedMacroImpl::CopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(ExportTest, CopyUnsharedMacroImpl)

int ExportTest::CopyUnsharedMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void ExportTest::CopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}
