///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:40)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/AssistToolsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(AssistTools, AssistToolsDelayCopyUnsharedMacro)

AssistTools::AssistToolsDelayCopyUnsharedMacro::AssistToolsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsDelayCopyUnsharedMacro)

int AssistTools::AssistToolsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void AssistTools::AssistToolsDelayCopyUnsharedMacro::SetCount(int count)
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* AssistTools::AssistToolsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}