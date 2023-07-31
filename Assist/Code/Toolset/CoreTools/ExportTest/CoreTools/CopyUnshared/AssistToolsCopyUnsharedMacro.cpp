///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:38)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/AssistToolsCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(AssistTools, AssistToolsCopyUnsharedMacro)

AssistTools::AssistToolsCopyUnsharedMacro::AssistToolsCopyUnsharedMacro(int count)
    : impl{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsCopyUnsharedMacro)

int AssistTools::AssistToolsCopyUnsharedMacro::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void AssistTools::AssistToolsCopyUnsharedMacro::SetCount(int count) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* AssistTools::AssistToolsCopyUnsharedMacro::GetAddress() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}