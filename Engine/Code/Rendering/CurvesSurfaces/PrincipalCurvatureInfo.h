///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 18:45)

#ifndef RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H
#define RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(PrincipalCurvatureInfoImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PrincipalCurvatureInfo
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(PrincipalCurvatureInfo);
        using AVector = Mathematics::AVectorF;

    public:
        PrincipalCurvatureInfo(float principalCurvature0, float principalCurvature1, const AVector& principalDirection0, const AVector& principalDirection1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetPrincipalCurvature0() const noexcept;
        NODISCARD float GetPrincipalCurvature1() const noexcept;
        NODISCARD AVector GetPrincipalDirection0() const noexcept;
        NODISCARD AVector GetPrincipalDirection1() const noexcept;

    private:
        PackageType impl;
    };

}

#endif  // RENDERING_CURVES_SURFACES_PRINCIPAL_CURVATURE_INFO_H
