///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:50)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H

#include "CubicPolynomialCurve2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::CubicPolynomialCurve2<Real>::CubicPolynomialCurve2(const Polynomial<Real>& xPoly, const Polynomial<Real>& yPoly)
    : ParentType{ xPoly, yPoly }, vertices{}
{
    MATHEMATICS_ASSERTION_0(xPoly.GetDegree() == 3, "无效输入\n");
    MATHEMATICS_ASSERTION_0(yPoly.GetDegree() == 3, "无效输入\n");

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::CubicPolynomialCurve2<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::CubicPolynomialCurve2<Real>::GetNumVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(vertices.size());
}

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::CubicPolynomialCurve2<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <typename Real>
void Mathematics::CubicPolynomialCurve2<Real>::Tessellate(int level)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto twoPowL = (1 << level);
    const auto numVertices = twoPowL + 1;

    vertices.resize(numVertices);

    IntervalParameters ip{};
    ip.i0 = 0;
    ip.i1 = twoPowL;

    vertices.at(ip.i0) = this->GetPosition(this->GetMinTime());
    vertices.at(ip.i1) = this->GetPosition(this->GetMaxTime());

    if (level > 0)
    {
        ip.xuu.at(0) = this->GetSecondDerivative(this->GetMinTime());
        ip.xuu.at(1) = this->GetSecondDerivative(this->GetMaxTime());
        Subdivide(--level, MathType::GetRational(1, 4), vertices, ip);
    }
}

template <typename Real>
void Mathematics::CubicPolynomialCurve2<Real>::Subdivide(int level, Real dsqr, std::vector<Vector2<Real>>& x, IntervalParameters& ip)
{
    const auto iMid = (ip.i0 + ip.i1) >> 1;

    auto xuuM = MathType::GetRational(1, 2) * (ip.xuu.at(0) + ip.xuu.at(1));
    x.at(iMid) = MathType::GetRational(1, 2) * (x.at(ip.i0) + x.at(ip.i1) - dsqr * xuuM);

    if (level > 0)
    {
        --level;
        dsqr *= MathType::GetRational(1, 4);

        IntervalParameters subIP{};

        subIP.i0 = ip.i0;
        subIP.i1 = iMid;
        subIP.xuu.at(0) = ip.xuu.at(0);
        subIP.xuu.at(1) = xuuM;
        Subdivide(level, dsqr, x, subIP);

        subIP.i0 = iMid;
        subIP.i1 = ip.i1;
        subIP.xuu.at(0) = xuuM;
        subIP.xuu.at(1) = ip.xuu.at(1);
        Subdivide(level, dsqr, x, subIP);
    }
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_DEATIL_H
