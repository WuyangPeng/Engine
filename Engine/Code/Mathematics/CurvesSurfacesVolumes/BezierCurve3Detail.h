///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:48)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H

#include "BezierCurve3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"

#include <gsl/util>

template <typename Real>
Mathematics::BezierCurve3<Real>::BezierCurve3(int degree, const std::vector<Vector3<Real>>& ctrlPoint)
    : ParentType{ MathType::GetValue(0), MathType::GetValue(1) },
      degree{ degree },
      numCtrlPoints{ degree + 1 },
      ctrlPoint{ ctrlPoint },
      der1CtrlPoint{},
      der2CtrlPoint{},
      der3CtrlPoint{},
      choose(numCtrlPoints, std::vector<Real>(numCtrlPoints))
{
    MATHEMATICS_ASSERTION_0(degree >= 2, "维度必须是3或更大。\n");

    for (auto i = 0; i < numCtrlPoints - 1; ++i)
    {
        der1CtrlPoint.emplace_back(ctrlPoint.at(gsl::narrow_cast<size_t>(i) + 1));
        der1CtrlPoint.at(i) -= ctrlPoint.at(i);
    }

    for (auto i = 0; i < numCtrlPoints - 2; ++i)
    {
        der2CtrlPoint.emplace_back(der1CtrlPoint.at(gsl::narrow_cast<size_t>(i) + 1) - der1CtrlPoint.at(i));
    }

    if (degree >= 3)
    {
        for (auto i = 0; i < numCtrlPoints - 3; ++i)
        {
            der3CtrlPoint.emplace_back(der2CtrlPoint.at(gsl::narrow_cast<size_t>(i) + 1) - der2CtrlPoint.at(i));
        }
    }

    choose.at(0).at(0) = MathType::GetValue(1);
    choose.at(1).at(0) = MathType::GetValue(1);
    choose.at(1).at(1) = MathType::GetValue(1);
    for (auto i = 2; i <= degree; ++i)
    {
        choose.at(i).at(0) = MathType::GetValue(1);
        choose.at(i).at(i) = MathType::GetValue(1);
        for (auto j = 1; j < i; ++j)
        {
            choose.at(i).at(j) = choose.at(gsl::narrow_cast<size_t>(i) - 1).at(gsl::narrow_cast<size_t>(j) - 1) + choose.at(gsl::narrow_cast<size_t>(i) - 1).at(j);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BezierCurve3<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BezierCurve3<Real>::GetDegree() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return degree;
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::BezierCurve3<Real>::GetControlPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ctrlPoint;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BezierCurve3<Real>::GetPosition(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto oneMinusT = MathType::GetValue(1) - t;
    auto powT = t;
    auto result = oneMinusT * ctrlPoint.at(0);

    for (auto i = 1; i < degree; ++i)
    {
        auto coeff = choose.at(degree).at(i) * powT;
        result = (result + ctrlPoint.at(i) * coeff) * oneMinusT;
        powT *= t;
    }

    result += ctrlPoint.at(degree) * powT;

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BezierCurve3<Real>::GetFirstDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto oneMinusT = MathType::GetValue(1) - t;
    auto powT = t;
    auto result = oneMinusT * der1CtrlPoint.at(0);

    const auto degreeM1 = degree - 1;
    for (auto i = 1; i < degreeM1; ++i)
    {
        auto coeff = choose.at(degreeM1).at(i) * powT;
        result = (result + der1CtrlPoint.at(i) * coeff) * oneMinusT;
        powT *= t;
    }

    result += der1CtrlPoint.at(degreeM1) * powT;
    result *= static_cast<Real>(degree);

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BezierCurve3<Real>::GetSecondDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto oneMinusT = MathType::GetValue(1) - t;
    auto powT = t;
    auto result = oneMinusT * der2CtrlPoint.at(0);

    const auto degreeM2 = degree - 2;
    for (auto i = 1; i < degreeM2; ++i)
    {
        auto coeff = choose.at(degreeM2).at(i) * powT;
        result = (result + der2CtrlPoint.at(i) * coeff) * oneMinusT;
        powT *= t;
    }

    result += der2CtrlPoint.at(degreeM2) * powT;
    const auto temp = degree - 1;
    const auto temp2 = degree * temp;
    result *= static_cast<Real>(temp2);

    return result;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::BezierCurve3<Real>::GetThirdDerivative(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (degree < 3)
    {
        return Vector3<Real>::GetZero();
    }

    auto oneMinusT = MathType::GetValue(1) - t;
    auto powT = t;
    auto result = oneMinusT * der3CtrlPoint.at(0);

    const int degreeM3 = degree - 3;
    for (auto i = 1; i < degreeM3; ++i)
    {
        auto coeff = choose.at(degreeM3).at(i) * powT;
        result = (result + coeff * der3CtrlPoint.at(i)) * oneMinusT;
        powT *= t;
    }

    result += powT * der3CtrlPoint.at(degreeM3);
    const auto temp1 = degree - 1;
    const auto temp2 = degree - 2;
    const auto temp3 = degree * temp1 * temp2;
    result *= static_cast<Real>(temp3);

    return result;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_DETAIL_H