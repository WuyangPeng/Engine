///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/17 15:57)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_DETAIL_H

#include "NURBSCurve3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::NURBSCurve3<Real>::NURBSCurve3(int numCtrlPoints, const std::vector<Vector3<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, bool open)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1) },
      numCtrlPoints{ numCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ loop },
      basis{},
      replicate{ (loop ? (open ? 1 : degree) : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);
    basis.Create(numCtrlPoints + replicate, degree, open);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::NURBSCurve3<Real>::NURBSCurve3(int numCtrlPoints, const std::vector<Vector3<Real>>& ctrlPoint, const std::vector<Real>& ctrlWeight, int degree, bool loop, const std::vector<Real>& knot)
    : ParentType{ Math<Real>::GetValue(0), Math<Real>::GetValue(1) },
      numCtrlPoints{ numCtrlPoints },
      ctrlPoint{},
      ctrlWeight{},
      loop{ loop },
      basis{},
      replicate{ (loop ? 1 : 0) }
{
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "无效输入。\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree <= numCtrlPoints - 1, "无效输入。\n");

    CreateControl(ctrlPoint, ctrlWeight);
    basis.Create(numCtrlPoints + replicate, degree, knot);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::NURBSCurve3<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::NURBSCurve3<Real>::CreateControl(const std::vector<Vector3<Real>>& newCtrlPoint, const std::vector<Real>& newCtrlWeight)
{
    const auto newNumCtrlPoints = numCtrlPoints + replicate;

    ctrlPoint.resize(newNumCtrlPoints);
    ctrlWeight.resize(newNumCtrlPoints);

    for (auto i = 0; i < replicate; ++i)
    {
        const auto index = numCtrlPoints + i;
        ctrlPoint.at(index) = newCtrlPoint.at(i);
        ctrlWeight.at(index) = newCtrlWeight.at(i);
    }
}

template <typename Real>
int Mathematics::NURBSCurve3<Real>::GetNumCtrlPoints() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numCtrlPoints;
}

template <typename Real>
int Mathematics::NURBSCurve3<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetDegree();
}

template <typename Real>
bool Mathematics::NURBSCurve3<Real>::IsOpen() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsOpen();
}

template <typename Real>
bool Mathematics::NURBSCurve3<Real>::IsUniform() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.IsUniform();
}

template <typename Real>
bool Mathematics::NURBSCurve3<Real>::IsLoop() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return loop;
}

template <typename Real>
void Mathematics::NURBSCurve3<Real>::SetControlPoint(int i, const Vector3<Real>& ctrl)
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
Mathematics::Vector3<Real> Mathematics::NURBSCurve3<Real>::GetControlPoint(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlPoint.at(i);
}

template <typename Real>
void Mathematics::NURBSCurve3<Real>::SetControlWeight(int i, Real weight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= i && i < numCtrlPoints)
    {
        ctrlWeight.at(i) = weight;

        if (i < replicate)
        {
            const auto index = numCtrlPoints + i;
            ctrlWeight.at(index) = weight;
        }
    }
}

template <typename Real>
Real Mathematics::NURBSCurve3<Real>::GetControlWeight(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlWeight.at(i);
}

template <typename Real>
void Mathematics::NURBSCurve3<Real>::SetKnot(int i, Real knot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    basis.SetKnot(i, knot);
}

template <typename Real>
Real Mathematics::NURBSCurve3<Real>::GetKnot(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return basis.GetKnot(i);
}

template <typename Real>
void Mathematics::NURBSCurve3<Real>::Get(Real t, Vector3<Real>* pos, Vector3<Real>* der1, Vector3<Real>* der2, Vector3<Real>* der3) const
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

    auto x = Vector3<Real>::GetZero();
    auto w = Math<Real>::GetValue(0);
    for (auto i = imin; i <= imax; ++i)
    {
        auto tmp = basis.GetD0(i) * ctrlWeight.at(i);
        x += tmp * ctrlPoint.at(i);
        w += tmp;
    }
    auto invW = (Math<Real>::GetValue(1)) / w;
    auto p = invW * x;
    if (pos != nullptr)
    {
        *pos = p;
    }

    if (der1 == nullptr && der2 == nullptr && der3 == nullptr)
    {
        return;
    }

    auto xDer1 = Vector3<Real>::GetZero();
    auto wDer1 = Math<Real>::GetValue(0);
    for (auto i = imin; i <= imax; ++i)
    {
        auto tmp = basis.GetD1(i) * ctrlWeight.at(i);
        xDer1 += tmp * ctrlPoint.at(i);
        wDer1 += tmp;
    }

    auto pDer1 = invW * (xDer1 - wDer1 * p);
    if (der1 != nullptr)
    {
        *der1 = pDer1;
    }

    if (der2 == nullptr && der3 == nullptr)
    {
        return;
    }

    auto xDer2 = Vector3<Real>::GetZero();
    auto wDer2 = Math<Real>::GetValue(0);
    for (auto i = imin; i <= imax; ++i)
    {
        auto tmp = basis.GetD2(i) * ctrlWeight.at(i);
        xDer2 += tmp * ctrlPoint.at(i);
        wDer2 += tmp;
    }

    auto pDer2 = invW * (xDer2 - (Math<Real>::GetValue(2)) * wDer1 * pDer1 - wDer2 * p);
    if (der2 != nullptr)
    {
        *der2 = pDer2;
    }

    if (der3 == nullptr)
    {
        return;
    }

    auto xDer3 = Vector3<Real>::GetZero();
    auto wDer3 = Math<Real>::GetValue(0);
    for (auto i = imin; i <= imax; ++i)
    {
        auto tmp = basis.GetD3(i) * ctrlWeight.at(i);
        xDer3 += tmp * ctrlPoint.at(i);
        wDer3 += tmp;
    }
    if (der3 != nullptr)
    {
        *der3 = invW * (xDer3 - Math<Real>::GetValue(3) * wDer1 * pDer2 - Math<Real>::GetValue(3) * wDer2 * pDer1 - wDer3 * p);
    }
}

template <typename Real>
Mathematics::BSplineBasis<Real>& Mathematics::NURBSCurve3<Real>::GetBasis() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return basis;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSCurve3<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> pos{};
    Get(t, &pos, 0, 0, 0);

    return pos;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSCurve3<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der1{};
    Get(t, 0, &der1, 0, 0);

    return der1;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSCurve3<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der2{};
    Get(t, 0, 0, &der2, 0);

    return der2;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::NURBSCurve3<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Vector3<Real> der3{};
    Get(t, 0, 0, 0, &der3);

    return der3;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE3_DETAIL_H