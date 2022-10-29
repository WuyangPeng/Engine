///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:29)

#include "Framework/FrameworkExport.h"

#include "FrameworkTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::FrameworkTestExportMacroImpl::FrameworkTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, FrameworkTestExportMacroImpl)

int Framework::FrameworkTestExportMacroImpl::GetCount() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return count;
}

void Framework::FrameworkTestExportMacroImpl::SetCount(int aCount) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    count = aCount;
}