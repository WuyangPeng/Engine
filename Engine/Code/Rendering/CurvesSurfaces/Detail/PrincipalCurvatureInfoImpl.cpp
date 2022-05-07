///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:34)

#include "Rendering/RenderingExport.h"

#include "PrincipalCurvatureInfoImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PrincipalCurvatureInfoImpl::PrincipalCurvatureInfoImpl(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const AVector& principalDirection1) noexcept
    : principalCurvature0{ principalCurvature0 },
      principalCurvature1{ principalCurvature1 },
      principalDirection0{ principalDirection0 },
      principalDirection1{ principalDirection1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::PrincipalCurvatureInfoImpl::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

float Rendering::PrincipalCurvatureInfoImpl::GetPrincipalCurvature0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return principalCurvature0;
}

float Rendering::PrincipalCurvatureInfoImpl::GetPrincipalCurvature1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return principalCurvature1;
}

Rendering::PrincipalCurvatureInfoImpl::AVector Rendering::PrincipalCurvatureInfoImpl::GetPrincipalDirection0() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return principalDirection0;
}

Rendering::PrincipalCurvatureInfoImpl::AVector Rendering::PrincipalCurvatureInfoImpl::GetPrincipalDirection1() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return principalDirection1;
}