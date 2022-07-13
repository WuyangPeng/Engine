///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:40)

#define FUNCTION_DESCRIBED_NO_EXPORT

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::CoreToolsTestExportCopyMacroImpl::CoreToolsTestExportCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsTestExportCopyMacroImpl)

int CoreTools::CoreToolsTestExportCopyMacroImpl::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void CoreTools::CoreToolsTestExportCopyMacroImpl::SetCount(int count) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    mCount = count;
}
