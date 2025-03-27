///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:49)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H

#include "BSplineCurve3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::BSplineCurve3<Real>::BSplineCurve3(const std::vector<Vector3<Real>>& ctrlPoint, int degree, bool loop, bool open)
    : SingleCurve3<Real>{ MathType::GetValue(0), MathType::GetValue(1) },
      numCtrlPoints{ boost::numeric_cast<int>(ctrlPoint.size()) },
      loop{ loop },
      ctrlPoint{},
      basis{},
      replicate{ (loop ? (open ? 1 : degree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "Invalid input\n");

    CreateControl(ctrlPoint);
    basis.Create(numCtrlPoints + replicate, degree, open);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BSplineCurve3<Real>::BSplineCurve3(const std::vector<Vector3<Real>>& ctrlPoint, int degree, bool loop, const std::vector<Real>& knot)
    : SingleCurve3<Real>{ MathType::GetValue(0), MathType::GetValue(1) },
      numCtrlPoints{ boost::numeric_cast<int>(ctrlPoint.size()) },
      loop(loop),
      ctrlPoint{},
      basis{},
      replicate{ (loop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "Invalid input\n");

    CreateControl(ctrlPoint);
    basis.Create(numCtrlPoints + replicate, degree, knot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>::CreateControl(const std::vector<Vector3<Real>>& newCtrlPoint)
{
    const auto newNumCtrlPoints = numCtrlPoints + replicate;

    ctrlPoint.resize(newNumCtrlPoints);

    for (auto i = 0; i < replicate; ++i)
    {
        const auto index = numCtrlPoints + i;
        ctrlPoint.at(index) = newCtrlPoint.at(i);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BSplineCurve3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BSplineCurve3<Real>::GetNumCtrlPoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numCtrlPoints;
}

template <typename Real>
int Mathematics::BSplineCurve3<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetDegree();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>::IsOpen() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsOpen();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>::IsUniform() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsUniform();
}

template <typename Real>
bool Mathematics::BSplineCurve3<Real>::IsLoop() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return loop;
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>::SetControlPoint(int i, const Vector3<Real>& ctrl)
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
Mathematics::Vector3<Real> Mathematics::BSplineCurve3<Real>::GetControlPoint(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= i && i < numCtrlPoints)
    {
        return ctrlPoint.at(i);
    }

    return Vector3<Real>{ MathType::maxReal, MathType::maxReal, MathType::maxReal };
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>::SetKnot(int i, Real knot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    basis.SetKnot(i, knot);
}

template <typename Real>
Real Mathematics::BSplineCurve3<Real>::GetKnot(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetKnot(i);
}

template <typename Real>
void Mathematics::BSplineCurve3<Real>::Get(Real t, Vector3<Real>* pos, Vector3<Real>* der1, Vector3<Real>* der2, Vector3<Real>* der3) const
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
        *pos = Vector3<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *pos += basis.GetD0(i) * ctrlPoint.at(i);
        }
    }

    if (der1 != nullptr)
    {
        *der1 = Vector3<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der1 += basis.GetD1(i) * ctrlPoint.at(i);
        }
    }

    if (der2 != nullptr)
    {
        *der2 = Vector3<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der2 += basis.GetD2(i) * ctrlPoint.at(i);
        }
    }

    if (der3 != nullptr)
    {
        *der3 = Vector3<Real>::GetZero();
        for (auto i = imin; i <= imax; ++i)
        {
            *der3 += basis.GetD3(i) * ctrlPoint.at(i);
        }
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>& Mathematics::BSplineCurve3<Real>::GetBasis() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return basis;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineCurve3<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> pos{};
    Get(t, &pos, 0, 0, 0);

    return pos;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineCurve3<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der1{};
    Get(t, 0, &der1, 0, 0);

    return der1;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineCurve3<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der2{};
    Get(t, 0, 0, &der2, 0);

    return der2;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BSplineCurve3<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der3{};
    Get(t, 0, 0, 0, &der3);

    return der3;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE3_DETAIL_H