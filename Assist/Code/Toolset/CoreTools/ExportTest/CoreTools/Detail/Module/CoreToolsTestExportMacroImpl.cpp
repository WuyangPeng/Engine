///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:16)

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CoreToolsTestExportMacroImpl::CoreToolsTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsTestExportMacroImpl)

int CoreTools::CoreToolsTestExportMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void CoreTools::CoreToolsTestExportMacroImpl::SetCount(int aCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}
