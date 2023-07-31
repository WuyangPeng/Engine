///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 15:37)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/RenderingTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RenderingTestExportCopyMacro)

Rendering::RenderingTestExportCopyMacro::RenderingTestExportCopyMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportCopyMacro)

int Rendering::RenderingTestExportCopyMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingTestExportCopyMacro::SetCount(int count) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}


