/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:43)

#include "Rendering/RenderingExport.h"

#include "TotalAllocation.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::TotalAllocation::TotalAllocation() noexcept
    : numBytes{ 0 }, numObjects{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TotalAllocation);

int Rendering::TotalAllocation::GetNumBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numBytes;
}

void Rendering::TotalAllocation::AddNumBytes(int num) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    numBytes += num;
}

int Rendering::TotalAllocation::GetNumObjects() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numObjects;
}

void Rendering::TotalAllocation::AddNumObjects(int num) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    numObjects += num;
}
