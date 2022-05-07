///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/15 15:33)

#ifndef RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H
#define RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PrincipalCurvatureInfoImpl
    {
    public:
        using ClassType = PrincipalCurvatureInfoImpl;
        using AVector = Mathematics::AVectorF;

    public:
        PrincipalCurvatureInfoImpl(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const AVector& principalDirection1) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetPrincipalCurvature0() const noexcept;
        NODISCARD float GetPrincipalCurvature1() const noexcept;
        NODISCARD AVector GetPrincipalDirection0() const noexcept;
        NODISCARD AVector GetPrincipalDirection1() const noexcept;

    private:
        float principalCurvature0;
        float principalCurvature1;
        AVector principalDirection0;
        AVector principalDirection1;
    };
}

#endif  // RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_IMPL_H
