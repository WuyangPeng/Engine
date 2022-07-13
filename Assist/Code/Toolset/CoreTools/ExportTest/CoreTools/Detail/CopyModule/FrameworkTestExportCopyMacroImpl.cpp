///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:40)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkTestExportCopyMacroImpl::FrameworkTestExportCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportCopyMacroImpl)

int Framework::FrameworkTestExportCopyMacroImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Framework::FrameworkTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    mCount = count;
}