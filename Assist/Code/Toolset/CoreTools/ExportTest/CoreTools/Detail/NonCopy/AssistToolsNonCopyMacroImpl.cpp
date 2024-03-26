/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:11)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsNonCopyMacroImpl::AssistToolsNonCopyMacroImpl(int count) noexcept
    : count{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsNonCopyMacroImpl)

int AssistTools::AssistToolsNonCopyMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void AssistTools::AssistToolsNonCopyMacroImpl::SetCount(int aCount) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}
