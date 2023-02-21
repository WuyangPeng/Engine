///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 18:57)

#include "Rendering/RenderingExport.h"

#include "RenderingDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/RenderingDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, RenderingDelayCopyUnsharedMacro)

Rendering::RenderingDelayCopyUnsharedMacro::RenderingDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDelayCopyUnsharedMacro)

int Rendering::RenderingDelayCopyUnsharedMacro::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Rendering::RenderingDelayCopyUnsharedMacro::SetCount(int count)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Rendering::RenderingDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}