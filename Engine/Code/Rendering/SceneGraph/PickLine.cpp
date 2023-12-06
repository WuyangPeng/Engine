///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/27 14:14)

#include "Rendering/RenderingExport.h"

#include "PickLine.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PickLine::PickLine() noexcept
    : origin{}, direction{}, isContain{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PickLine::PickLine(const APoint& origin, const AVector& direction, bool isContain) noexcept
    : origin{ origin }, direction{ direction }, isContain{ isContain }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickLine)

Rendering::PickLine::APoint Rendering::PickLine::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin;
}

Rendering::PickLine::AVector Rendering::PickLine::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return direction;
}

bool Rendering::PickLine::IsContain() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isContain;
}
