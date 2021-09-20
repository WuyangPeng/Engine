///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 22:03)

#include "Framework/FrameworkExport.h"

#include "FrameworkMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkMacroSharedImpl::FrameworkMacroSharedImpl(int count) noexcept
    : m_Count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkMacroSharedImpl)

int Framework::FrameworkMacroSharedImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Framework::FrameworkMacroSharedImpl::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    m_Count = count;
}