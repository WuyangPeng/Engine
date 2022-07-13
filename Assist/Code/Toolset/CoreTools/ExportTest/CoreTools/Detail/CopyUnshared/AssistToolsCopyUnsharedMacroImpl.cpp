///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:38)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsCopyUnsharedMacroImpl::AssistToolsCopyUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsCopyUnsharedMacroImpl)

int AssistTools::AssistToolsCopyUnsharedMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void AssistTools::AssistToolsCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    mCount = count;
}
