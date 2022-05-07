///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:36)

#include "Rendering/RenderingExport.h"

#include "SurfacePatchFrameImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::SurfacePatchFrameImpl::SurfacePatchFrameImpl(const APoint& position, const AVector& tangent0, const AVector& tangent1, const AVector& normal) noexcept
    : position{ position }, tangent0{ tangent0 }, tangent1{ tangent1 }, normal{ normal }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::SurfacePatchFrameImpl::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

Rendering::SurfacePatchFrameImpl::APoint Rendering::SurfacePatchFrameImpl::GetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return position;
}

Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl::GetTangent0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return tangent0;
}

Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl::GetTangent1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return tangent1;
}

Rendering::SurfacePatchFrameImpl::AVector Rendering::SurfacePatchFrameImpl::GetNormal() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normal;
}