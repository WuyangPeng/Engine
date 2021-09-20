///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 21:11)

#define FUNCTION_DESCRIBED_NO_EXPORT

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CoreToolsNonCopyMacroImpl::CoreToolsNonCopyMacroImpl(int count) noexcept
    : m_Count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsNonCopyMacroImpl)

int CoreTools::CoreToolsNonCopyMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void CoreTools::CoreToolsNonCopyMacroImpl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Count = count;
}
