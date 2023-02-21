///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:36)

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/CoreToolsPerformanceUnsharedMacroImpl.h"

CoreTools::CoreToolsPerformanceUnsharedMacro::CoreToolsPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsPerformanceUnsharedMacro)

int CoreTools::CoreToolsPerformanceUnsharedMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* CoreTools::CoreToolsPerformanceUnsharedMacro::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}