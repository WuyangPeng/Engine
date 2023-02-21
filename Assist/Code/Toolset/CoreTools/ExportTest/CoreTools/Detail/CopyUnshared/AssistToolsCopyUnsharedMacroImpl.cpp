///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:01)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsCopyUnsharedMacroImpl::AssistToolsCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsCopyUnsharedMacroImpl)

int AssistTools::AssistToolsCopyUnsharedMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void AssistTools::AssistToolsCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}
