///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:02)

#include "Framework/FrameworkExport.h"

#include "FrameworkMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkMacroSharedImpl::FrameworkMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkMacroSharedImpl)

int Framework::FrameworkMacroSharedImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Framework::FrameworkMacroSharedImpl::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    mCount = count;
}