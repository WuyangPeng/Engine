///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/01 14:06)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsNonCopyMacroImpl::AssistToolsNonCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsNonCopyMacroImpl)

int AssistTools::AssistToolsNonCopyMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void AssistTools::AssistToolsNonCopyMacroImpl::SetCount(int count) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    mCount = count;
}
