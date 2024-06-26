/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:20)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/RenderingTestExportMacroImpl.h"

Rendering::RenderingTestExportMacro::RenderingTestExportMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportMacro)

int Rendering::RenderingTestExportMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingTestExportMacro::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
