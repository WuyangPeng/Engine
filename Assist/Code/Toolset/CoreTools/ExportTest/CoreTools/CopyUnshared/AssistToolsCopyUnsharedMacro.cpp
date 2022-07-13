///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/02 13:42)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyUnshared/AssistToolsCopyUnsharedMacroImpl.h"

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

COPY_UNSHARED_CLONE_SELF_DEFINE(AssistTools, AssistToolsCopyUnsharedMacro)