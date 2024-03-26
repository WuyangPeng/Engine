/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:10)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportMacroImpl::RenderingTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportMacroImpl)

int Rendering::RenderingTestExportMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return count;
}

void Rendering::RenderingTestExportMacroImpl::SetCount(int aCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    count = aCount;
}