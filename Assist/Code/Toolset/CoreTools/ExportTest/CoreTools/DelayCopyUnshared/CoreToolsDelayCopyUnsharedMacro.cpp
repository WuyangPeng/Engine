///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:40)

#include "CoreTools/CoreToolsExport.h"

#include "CoreToolsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/CoreToolsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, CoreToolsDelayCopyUnsharedMacro)

CoreTools::CoreToolsDelayCopyUnsharedMacro::CoreToolsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CoreToolsDelayCopyUnsharedMacro)

int CoreTools::CoreToolsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void CoreTools::CoreToolsDelayCopyUnsharedMacro::SetCount(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* CoreTools::CoreToolsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}