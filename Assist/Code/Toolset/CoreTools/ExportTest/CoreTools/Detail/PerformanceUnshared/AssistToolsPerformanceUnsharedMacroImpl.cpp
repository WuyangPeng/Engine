///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 21:39)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::AssistToolsPerformanceUnsharedMacroImpl::AssistToolsPerformanceUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsPerformanceUnsharedMacroImpl)

int AssistTools::AssistToolsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void AssistTools::AssistToolsPerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    m_Count = count;
}
