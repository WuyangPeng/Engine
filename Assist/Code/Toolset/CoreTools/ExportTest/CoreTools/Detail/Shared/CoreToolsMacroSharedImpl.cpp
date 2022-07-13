///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:02)

#define FUNCTION_DESCRIBED_NO_EXPORT

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CoreToolsMacroSharedImpl::CoreToolsMacroSharedImpl(int count) noexcept
    : mCount{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsMacroSharedImpl)

int CoreTools::CoreToolsMacroSharedImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void CoreTools::CoreToolsMacroSharedImpl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCount = count;
}
