/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/17 09:47)

#include "Rendering/RenderingExport.h"

#include "DepthRange.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::DepthRange::DepthRange() noexcept
    : zMin{ -1.0f }, zMax{ 1.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::DepthRange::DepthRange(float zMin, float zMax)
    : zMin{ zMin }, zMax{ zMax }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("深度范围为[-1, 1] 的子集"))
    }
}

bool Rendering::DepthRange::IsValid() const noexcept
{
    return -1.0f <= zMin && zMin <= 1.0f && -1.0f <= zMax && zMax <= 1.0f && zMin <= zMax;
}

float Rendering::DepthRange::GetZMin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return zMin;
}

float Rendering::DepthRange::GetZMax() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return zMax;
}
