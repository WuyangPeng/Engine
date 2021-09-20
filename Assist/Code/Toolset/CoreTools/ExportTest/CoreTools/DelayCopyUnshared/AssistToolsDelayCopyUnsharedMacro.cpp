///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:12)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/AssistToolsDelayCopyUnsharedMacroImpl.h"

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

COPY_UNSHARED_CLONE_SELF_DEFINE(AssistTools, AssistToolsDelayCopyUnsharedMacro)