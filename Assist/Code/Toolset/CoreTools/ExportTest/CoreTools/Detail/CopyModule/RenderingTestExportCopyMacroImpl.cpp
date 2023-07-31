///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 10:04)

#include "Rendering/RenderingExport.h"

#include "RenderingTestExportCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::RenderingTestExportCopyMacroImpl::RenderingTestExportCopyMacroImpl(int count) noexcept
    : count{ count }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingTestExportCopyMacroImpl)

int Rendering::RenderingTestExportCopyMacroImpl::GetCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return count;
}

void Rendering::RenderingTestExportCopyMacroImpl::SetCount(int aCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    count = aCount;
}