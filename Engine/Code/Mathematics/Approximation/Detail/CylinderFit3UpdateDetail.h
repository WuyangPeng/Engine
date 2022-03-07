///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 18:23)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H

#include "CylinderFit3Update.h"
#include "CylinderFit3UpdateDataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <algorithm>

template <typename Real>
Mathematics::CylinderFit3Update<Real>::CylinderFit3Update(const Points& points, const Vector3& guessCenter, const Vector3& guessAxis, const Real epsilon)
    : points{ points },
      inverseRadiusSqrare{ Math::GetValue(1) },
      axis{ guessAxis },
      center{ guessCenter },
      exactly{ Math::maxReal },
      epsilon{ epsilon },
      updateData{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::Update(int maxLoopTime)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_2(0 < maxLoopTime, "循环次数为负数\n");

    for (auto i = 0; i < maxLoopTime; ++i)
    {
        // 先存储每一个循环需要的值，避免重复计算
        CalculateUpdateData();

        UpdateInverseRadiusSqrare();
        UpdateDirection();
        UpdateCenter();
    }
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::CalculateUpdateData()
{
    updateData.clear();

    for (const auto& point : points)
    {
        updateData.emplace_back(point, center, axis);
    }
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateInverseRadiusSqrare() noexcept(g_Assert < 2 || g_MathematicsAssert < 2)
{
    auto deltaCrossAxisLengthSquaredSum = Math::GetValue(0);
    auto deltaCrossAxisLengthQuarticSum = Math::GetValue(0);

    for (const auto& data : updateData)
    {
        auto deltaCrossAxisLengthQuartic = data.GetDeltaCrossAxisLengthQuartic();
        deltaCrossAxisLengthSquaredSum += deltaCrossAxisLengthQuartic;
        deltaCrossAxisLengthQuarticSum += deltaCrossAxisLengthQuartic * deltaCrossAxisLengthQuartic;
    }

    inverseRadiusSqrare = deltaCrossAxisLengthSquaredSum / deltaCrossAxisLengthQuarticSum;
    exactly = Math::GetValue(1) - inverseRadiusSqrare * deltaCrossAxisLengthSquaredSum / static_cast<Real>(updateData.size());

    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= exactly && exactly <= Math::GetValue(1), "误差值错误！");
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateDirection()
{
    // 计算的最快下降的方向。
    Vector3 descentDirection{};
    auto aMean = Math::GetValue(0);
    auto aaMean = Math::GetValue(0);

    for (const auto& data : updateData)
    {
        const auto delta = data.GetDelta();
        auto a = inverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        aMean += a;
        aaMean += a * a;
        descentDirection += a * data.GetDescentDirection();
    }

    auto inverseNumPoints = Math::GetValue(1) / static_cast<Real>(points.size());

    aMean *= inverseNumPoints;
    aaMean *= inverseNumPoints;
    if (descentDirection.IsZero(epsilon))
    {
        exactly = aaMean;
        MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= exactly && exactly <= Math::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    auto abMean = Math::GetValue(0);
    auto acMean = Math::GetValue(0);
    auto bbMean = Math::GetValue(0);
    auto bcMean = Math::GetValue(0);
    auto ccMean = Math::GetValue(0);
    for (const auto& data : updateData)
    {
        const auto delta = data.GetDelta();
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        const auto deltaCrossDescentDirection = Vector3Tools<Real>::CrossProduct(delta, descentDirection);
        auto a = inverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        auto b = inverseRadiusSqrare * Vector3Tools<Real>::DotProduct(deltaCrossAxis, deltaCrossDescentDirection);
        auto c = inverseRadiusSqrare * Vector3Tools<Real>::GetLengthSquared(deltaCrossDescentDirection);
        abMean += a * b;
        acMean += a * c;
        bbMean += b * b;
        bcMean += b * c;
        ccMean += c * c;
    }

    abMean *= inverseNumPoints;
    acMean *= inverseNumPoints;
    bbMean *= inverseNumPoints;
    bcMean *= inverseNumPoints;
    ccMean *= inverseNumPoints;

    std::vector<Real> tuple{ aaMean,
                             Math::GetValue(-4) * abMean,
                             (Math::GetValue(2) * acMean + Math::GetValue(4) * bbMean),
                             Math::GetValue(-4) * bcMean,
                             ccMean };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }

    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(Math::GetValue(0));
    auto minIndex = -1;
    for (auto i = 0; i < count; ++i)
    {
        auto value = polynomial(polynomialRoots.GetRoot(i));
        if (value < min)
        {
            min = value;
            minIndex = i;
        }
    }

    exactly = min;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= exactly && exactly <= Math::GetValue(1), "误差值错误！");

    if (0 <= minIndex)
    {
        axis -= polynomialRoots.GetRoot(minIndex) * descentDirection;
        auto length = Vector3Tools<Real>::GetLength(axis);
        axis.Normalize();
        inverseRadiusSqrare *= length * length;
    }
}

// private
template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateCenter()
{
    auto inverseNumPoints = Math::GetValue(1) / static_cast<Real>(updateData.size());

    // 计算的最快下降的方向。
    Vector3 descentDirection{};
    auto aMean = Math::GetValue(0);
    auto aaMean = Math::GetValue(0);

    for (const auto& data : updateData)
    {
        auto delta = data.GetPoint() - center;
        const auto deltaCrossAxis = Vector3Tools<Real>::CrossProduct(delta, axis);
        auto a = inverseRadiusSqrare * Vector3Tools<Real>::GetLength(deltaCrossAxis) - Math::GetValue(1);

        aMean += a;
        aaMean += a * a;

        // 确保|axis| = 1
        descentDirection += (delta - axis * Vector3Tools<Real>::DotProduct(axis, delta)) * a;
    }

    aMean *= inverseNumPoints;
    aaMean *= inverseNumPoints;

    if (descentDirection.IsZero(epsilon))
    {
        exactly = aaMean;
        MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= exactly && exactly <= Math::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    const auto descentDirectionCrossAxis = Vector3Tools<Real>::CrossProduct(descentDirection, axis);
    auto c = Vector3Tools<Real>::GetLength(descentDirectionCrossAxis) * inverseNumPoints * inverseRadiusSqrare;
    auto bMean = Math::GetValue(0);
    auto abMean = Math::GetValue(0);
    auto bbMean = Math::GetValue(0);

    for (const auto& data : updateData)
    {
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        auto a = inverseRadiusSqrare * data.GetDeltaCrossAxisLengthQuartic() - Math::GetValue(1);
        auto b = inverseRadiusSqrare * (Vector3Tools<Real>::DotProduct(deltaCrossAxis, descentDirectionCrossAxis));
        bMean += b;
        abMean += a * b;
        bbMean += b * b;
    }
    bMean *= inverseNumPoints;
    abMean *= inverseNumPoints;
    bbMean *= inverseNumPoints;

    std::vector<Real> tuple{ aaMean,
                             Math::GetValue(4) * abMean,
                             Math::GetValue(2) * c * aMean + Math::GetValue(4) * bbMean,
                             Math::GetValue(4) * c * bMean,
                             c * c };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }
    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(Math::GetValue(0));
    auto minIndex = -1;
    for (auto i = 0; i < count; ++i)
    {
        auto value = polynomial(polynomialRoots.GetRoot(i));
        if (value < min)
        {
            min = value;
            minIndex = i;
        }
    }

    exactly = min;
    MATHEMATICS_ASSERTION_2(Math::GetValue(0) <= exactly && exactly <= Math::GetValue(1), "误差值错误！");

    if (0 <= minIndex)
    {
        center -= polynomialRoots.GetRoot(minIndex) * descentDirection;
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::CylinderFit3Update<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::GetValue(0) <= inverseRadiusSqrare && Math::GetValue(0) <= exactly && Math::GetValue(0) <= epsilon && axis.IsNormalize(epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::CylinderFit3Update<Real>::GetExactly() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return exactly;
}

template <typename Real>
typename Mathematics::CylinderFit3Update<Real>::Vector3 Mathematics::CylinderFit3Update<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
typename Mathematics::CylinderFit3Update<Real>::Vector3 Mathematics::CylinderFit3Update<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis;
}

template <typename Real>
Real Mathematics::CylinderFit3Update<Real>::GetInverseRadiusSqrare() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return inverseRadiusSqrare;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H
