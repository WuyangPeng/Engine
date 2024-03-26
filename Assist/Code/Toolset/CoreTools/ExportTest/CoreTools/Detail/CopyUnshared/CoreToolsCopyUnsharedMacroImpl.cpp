/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:05)

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CoreToolsCopyUnsharedMacroImpl::CoreToolsCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsCopyUnsharedMacroImpl)

int CoreTools::CoreToolsCopyUnsharedMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return count;
}

void CoreTools::CoreToolsCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    count = aCount;
}
