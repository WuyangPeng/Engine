///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 22:36)

#include "Framework/FrameworkExport.h"

#include "FrameworkCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkCopyUnsharedMacroImpl::FrameworkCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkCopyUnsharedMacroImpl)

int Framework::FrameworkCopyUnsharedMacroImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Framework::FrameworkCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    m_Count = count;
}