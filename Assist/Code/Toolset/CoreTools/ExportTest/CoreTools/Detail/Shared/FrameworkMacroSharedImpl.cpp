///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:25)

#include "Framework/FrameworkExport.h"

#include "FrameworkMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkMacroSharedImpl::FrameworkMacroSharedImpl(int count) noexcept
    : count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkMacroSharedImpl)

int Framework::FrameworkMacroSharedImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Framework::FrameworkMacroSharedImpl::SetCount(int aCount) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    count = aCount;
}