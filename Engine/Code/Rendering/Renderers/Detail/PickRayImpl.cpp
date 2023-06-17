///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:42)

#include "Rendering/RenderingExport.h"

#include "PickRayImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"

Rendering::PickRayImpl::PickRayImpl(bool result, const Mathematics::APointF& origin, const Mathematics::AVectorF& direction) noexcept
    : result{ result }, origin{ origin }, direction{ direction }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PickRayImpl::PickRayImpl() noexcept
    : result{ false }, origin{}, direction{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PickRayImpl)

bool Rendering::PickRayImpl::IsResult() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return result;
}

Mathematics::APointF Rendering::PickRayImpl::GetOrigin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return origin;
}

Mathematics::AVectorF Rendering::PickRayImpl::GetDirection() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return direction;
}
