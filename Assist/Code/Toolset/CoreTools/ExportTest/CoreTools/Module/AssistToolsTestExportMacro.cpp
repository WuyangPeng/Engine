/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:19)

#include "AssistTools/AssistToolsExport.h"

#include "AssistToolsTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/AssistToolsTestExportMacroImpl.h"

AssistTools::AssistToolsTestExportMacro::AssistToolsTestExportMacro(int count)
    : impl{ count }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, AssistToolsTestExportMacro)

int AssistTools::AssistToolsTestExportMacro::GetCount() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void AssistTools::AssistToolsTestExportMacro::SetCount(int count) noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}