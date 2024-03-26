/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:14)

#include "Rendering/RenderingExport.h"

#include "RenderingPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingPerformanceUnsharedMacroImpl::RenderingPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingPerformanceUnsharedMacroImpl)

int Rendering::RenderingPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return count;
}
