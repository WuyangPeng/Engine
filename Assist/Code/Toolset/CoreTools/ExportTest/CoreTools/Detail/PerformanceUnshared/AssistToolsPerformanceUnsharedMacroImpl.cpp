///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.4 (2023/03/16 20:35)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsPerformanceUnsharedMacroImpl::AssistToolsPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsPerformanceUnsharedMacroImpl)

int AssistTools::AssistToolsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}
 