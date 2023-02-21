///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:05)

#include "Rendering/RenderingExport.h"

#include "RenderingDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingDelayCopyUnsharedMacroImpl::RenderingDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDelayCopyUnsharedMacroImpl)

int Rendering::RenderingDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return count;
}

void Rendering::RenderingDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    count = aCount;
}