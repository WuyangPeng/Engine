///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:52)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H

#include "ParametricSurface.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::ParametricSurface<Real>::ParametricSurface(Real umin, Real umax, Real vmin, Real vmax, bool rectangular)
    : ParentType{}, uMin{ umin }, uMax{ umax }, vMin{ vmin }, vMax{ vmax }, rectangular{ rectangular }
{
    MATHEMATICS_ASSERTION_0(umin < umax && vmin < vmax, "无效域\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ParametricSurface<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::ParametricSurface<Real>::GetUMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uMin;
}

template <typename Real>
Real Mathematics::ParametricSurface<Real>::GetUMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uMax;
}

template <typename Real>
Real Mathematics::ParametricSurface<Real>::GetVMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vMin;
}

template <typename Real>
Real Mathematics::ParametricSurface<Real>::GetVMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vMax;
}

template <typename Real>
bool Mathematics::ParametricSurface<Real>::IsRectangular() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rectangular;
}

template <typename Real>
void Mathematics::ParametricSurface<Real>::GetFrame(Real u, Real v, Vector3<Real>& position, Vector3<Real>& tangent0, Vector3<Real>& tangent1, Vector3<Real>& normal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    position = P(u, v);

    tangent0 = PU(u, v);
    tangent1 = PV(u, v);
    tangent0.Normalize();
    tangent1.Normalize();
    normal = Vector3Tools<Real>::CrossProduct(tangent0, tangent1);

    tangent1 = Vector3Tools<Real>::CrossProduct(normal, tangent0);
}

template <typename Real>
void Mathematics::ParametricSurface<Real>::ComputePrincipalCurvatureInfo(Real u, Real v, Real& curv0, Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto derU = PU(u, v);
    const auto derV = PV(u, v);
    const auto derUU = PUU(u, v);
    const auto derUV = PUV(u, v);
    const auto derVV = PVV(u, v);

    Matrix2<Real> metricTensor{};
    metricTensor[0][0] = Vector3Tools<Real>::DotProduct(derU, derU);
    metricTensor[0][1] = Vector3Tools<Real>::DotProduct(derU, derV);
    metricTensor[1][0] = metricTensor[0][1];
    metricTensor[1][1] = Vector3Tools<Real>::DotProduct(derV, derV);

    const auto normal = Vector3Tools<Real>::CrossProduct(derU, derV);
    Matrix2<Real> curvatureTensor{};
    curvatureTensor[0][0] = -Vector3Tools<Real>::DotProduct(normal, derUU);
    curvatureTensor[0][1] = -Vector3Tools<Real>::DotProduct(normal, derUV);
    curvatureTensor[1][0] = curvatureTensor[0][1];
    curvatureTensor[1][1] = -Vector3Tools<Real>::DotProduct(normal, derVV);

    auto c0 = curvatureTensor.Determinant();
    auto c1 = Math::GetValue(2) * curvatureTensor[0][1] * metricTensor[0][1] - curvatureTensor[0][0] * metricTensor[1][1] - curvatureTensor[1][1] * metricTensor[0][0];
    auto c2 = metricTensor.Determinant();

    auto temp = Math::Sqrt(Math::FAbs(c1 * c1 - Math::GetValue(4) * c0 * c2));
    auto mult = Math::GetRational(1, 2) / c2;
    curv0 = -mult * (c1 + temp);
    curv1 = mult * (-c1 + temp);

    auto a0 = curvatureTensor[0][1] - curv0 * metricTensor[0][1];
    auto a1 = curv0 * metricTensor[0][0] - curvatureTensor[0][0];
    auto length = Math::Sqrt(a0 * a0 + a1 * a1);
    if (length >= Math::GetZeroTolerance())
    {
        dir0 = a0 * derU + a1 * derV;
    }
    else
    {
        a0 = curvatureTensor[1][1] - curv0 * metricTensor[1][1];
        a1 = curv0 * metricTensor[0][1] - curvatureTensor[0][1];
        length = Math::Sqrt(a0 * a0 + a1 * a1);
        if (length >= Math::GetZeroTolerance())
        {
            dir0 = a0 * derU + a1 * derV;
        }
        else
        {
            dir0 = derU;
        }
    }
    dir0.Normalize();

    dir1 = Vector3Tools<Real>::CrossProduct(dir0, normal);
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H