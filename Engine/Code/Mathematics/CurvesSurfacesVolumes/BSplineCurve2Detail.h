///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/14 15:46)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H

#include "BSplineCurve2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::BSplineCurve2<Real>::BSplineCurve2(const std::vector<Vector2<Real>>& ctrlPoint, int degree, bool loop, bool open)
    : ParentType{ Math::GetValue(0), Math::GetValue(1) },
      numCtrlPoints{ boost::numeric_cast<int>(ctrlPoint.size()) },
      loop{ loop },
      ctrlPoint{},
      basis{},
      replicate{ (loop ? (open ? 1 : degree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint);
    basis.Create(numCtrlPoints + replicate, degree, open);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineCurve2<Real>::BSplineCurve2(const std::vector<Vector2<Real>>& ctrlPoint, int degree, bool loop, const std::vector<Real>& knot)
    : ParentType(Math ::GetValue(0), Math::GetValue(1)),
      numCtrlPoints{ boost::numeric_cast<int>(ctrlPoint.size()) },
      loop(loop),
      ctrlPoint{},
      basis{},
      replicate{ (loop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint);
    basis.Create(numCtrlPoints + replicate, degree, knot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineCurve2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::BSplineCurve2<Real>::CreateControl(const std::vector<Vector2<Real>>& newCtrlPoint)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto newNumCtrlPoints = numCtrlPoints + replicate;

    ctrlPoint.resize(newNumCtrlPoints);

    for (auto i = 0; i < replicate; ++i)
    {
        const auto index = numCtrlPoints + i;
        ctrlPoint.at(index) = newCtrlPoint.at(i);
    }
}

template <typename Real>
int Mathematics::BSplineCurve2<Real>::GetNumCtrlPoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numCtrlPoints;
}

template <typename Real>
int Mathematics::BSplineCurve2<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetDegree();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>::IsOpen() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsOpen();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>::IsUniform() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsUniform();
}

template <typename Real>
bool Mathematics::BSplineCurve2<Real>::IsLoop() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return loop;
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>::SetControlPoint(int i, const Vector2<Real>& ctrl)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= i && i < numCtrlPoints)
    {
        ctrlPoint.at(i) = ctrl;

        if (i < replicate)
        {
            const auto index = numCtrlPoints + i;
            ctrlPoint.at(index) = ctrl;
        }
    }
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::BSplineCurve2<Real>::GetControlPoint(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= i && i < numCtrlPoints)
    {
        return ctrlPoint.at(i);
    }

    return Vector2<Real>{ Math::maxReal, Math::maxReal };
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>::SetKnot(int i, Real knot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    basis.SetKnot(i, knot);
}

template <typename Real>
Real Mathematics::BSplineCurve2<Real>::GetKnot(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetKnot(i);
}

template <typename Real>
void Mathematics::BSplineCurve2<Real>::Get(Real t, Vector2<Real>* pos, Vector2<Real>* der1, Vector2<Real>* der2, Vector2<Real>* der3) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto imin = 0;
    auto imax = 0;
    if (der3 != nullptr)
    {
        basis.Compute(t, 0, imin, imax);
        basis.Compute(t, 1, imin, imax);
        basis.Compute(t, 2, imin, imax);
        basis.Compute(t, 3, imin, imax);
    }
    else if (der2 != nullptr)
    {
        basis.Compute(t, 0, imin, imax);
        basis.Compute(t, 1, imin, imax);
        basis.Compute(t, 2, imin, imax);
    }
    else if (der1 != nullptr)
    {
        basis.Compute(t, 0, imin, imax);
        basis.Compute(t, 1, imin, imax);
    }
    else
    {
        basis.Compute(t, 0, imin, imax);
    }

    if (pos != nullptr)
    {
        *pos = Vector2<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *pos += ctrlPoint.at(i) * basis.GetD0(i);
        }
    }

    if (der1)
    {
        *der1 = Vector2<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der1 += ctrlPoint.at(i) * basis.GetD1(i);
        }
    }

    if (der2)
    {
        *der2 = Vector2<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der2 += ctrlPoint.at(i) * basis.GetD2(i);
        }
    }

    if (der3)
    {
        *der3 = Vector2<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der3 += ctrlPoint.at(i) * basis.GetD3(i);
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>& Mathematics::BSplineCurve2<Real>::GetBasis() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return basis;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::BSplineCurve2<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector2<Real> pos{};
    Get(t, &pos, 0, 0, 0);

    return pos;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::BSplineCurve2<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector2<Real> der1{};
    Get(t, 0, &der1, 0, 0);

    return der1;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::BSplineCurve2<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector2<Real> der2{};
    Get(t, 0, 0, &der2, 0);

    return der2;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::BSplineCurve2<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector2<Real> der3{};
    Get(t, 0, 0, 0, &der3);

    return der3;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE2_DETAIL_H