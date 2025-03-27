///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:07)

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
Mathematics::CylinderFit3Update<Real>::CylinderFit3Update(Points points, const Vector3& guessCenter, const Vector3& guessAxis, const Real epsilon) noexcept
    : points{ std::move(points) },
      inverseRadiusSquare{ MathType::GetValue(1) },
      axis{ guessAxis },
      center{ guessCenter },
      exactly{ MathType::maxReal },
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

        UpdateInverseRadiusSquare();
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

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateInverseRadiusSquare() noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    auto deltaCrossAxisLengthSquaredSum = MathType::GetValue(0);
    auto deltaCrossAxisLengthQuarticSum = MathType::GetValue(0);

    for (const auto& data : updateData)
    {
        auto deltaCrossAxisLengthQuartic = data.GetDeltaCrossAxisLengthQuartic();
        deltaCrossAxisLengthSquaredSum += deltaCrossAxisLengthQuartic;
        deltaCrossAxisLengthQuarticSum += deltaCrossAxisLengthQuartic * deltaCrossAxisLengthQuartic;
    }

    inverseRadiusSquare = deltaCrossAxisLengthSquaredSum / deltaCrossAxisLengthQuarticSum;
    exactly = MathType::GetValue(1) - inverseRadiusSquare * deltaCrossAxisLengthSquaredSum / static_cast<Real>(updateData.size());

    MATHEMATICS_ASSERTION_2(MathType::GetValue(0) <= exactly && exactly <= MathType::GetValue(1), "误差值错误！");
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateDirection()
{
    // 计算的最快下降的方向。
    Vector3 descentDirection{};
    auto aMean = MathType::GetValue(0);
    auto aaMean = MathType::GetValue(0);

    for (const auto& data : updateData)
    {
        const auto delta = data.GetDelta();
        auto a = inverseRadiusSquare * data.GetDeltaCrossAxisLengthQuartic() - MathType::GetValue(1);
        aMean += a;
        aaMean += a * a;
        descentDirection += a * data.GetDescentDirection();
    }

    auto inverseNumPoints = MathType::GetValue(1) / static_cast<Real>(points.size());

    aMean *= inverseNumPoints;
    aaMean *= inverseNumPoints;
    if (descentDirection.IsZero(epsilon))
    {
        exactly = aaMean;
        MATHEMATICS_ASSERTION_2(MathType::GetValue(0) <= exactly && exactly <= MathType::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    auto abMean = MathType::GetValue(0);
    auto acMean = MathType::GetValue(0);
    auto bbMean = MathType::GetValue(0);
    auto bcMean = MathType::GetValue(0);
    auto ccMean = MathType::GetValue(0);
    for (const auto& data : updateData)
    {
        const auto delta = data.GetDelta();
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        const auto deltaCrossDescentDirection = Vector3Tools<Real>::CrossProduct(delta, descentDirection);
        auto a = inverseRadiusSquare * data.GetDeltaCrossAxisLengthQuartic() - MathType::GetValue(1);
        auto b = inverseRadiusSquare * Vector3Tools<Real>::DotProduct(deltaCrossAxis, deltaCrossDescentDirection);
        auto c = inverseRadiusSquare * Vector3Tools<Real>::GetLengthSquared(deltaCrossDescentDirection);
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
                             MathType::GetValue(-4) * abMean,
                             (MathType::GetValue(2) * acMean + MathType::GetValue(4) * bbMean),
                             MathType::GetValue(-4) * bcMean,
                             ccMean };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }

    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(MathType::GetValue(0));
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
    MATHEMATICS_ASSERTION_2(MathType::GetValue(0) <= exactly && exactly <= MathType::GetValue(1), "误差值错误！");

    if (0 <= minIndex)
    {
        axis -= polynomialRoots.GetRoot(minIndex) * descentDirection;
        auto length = Vector3Tools<Real>::GetLength(axis);
        axis.Normalize();
        inverseRadiusSquare *= length * length;
    }
}

template <typename Real>
void Mathematics::CylinderFit3Update<Real>::UpdateCenter()
{
    auto inverseNumPoints = MathType::GetValue(1) / static_cast<Real>(updateData.size());

    // 计算的最快下降的方向。
    Vector3 descentDirection{};
    auto aMean = MathType::GetValue(0);
    auto aaMean = MathType::GetValue(0);

    for (const auto& data : updateData)
    {
        auto delta = data.GetPoint() - center;
        const auto deltaCrossAxis = Vector3Tools<Real>::CrossProduct(delta, axis);
        auto a = inverseRadiusSquare * Vector3Tools<Real>::GetLength(deltaCrossAxis) - MathType::GetValue(1);

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
        MATHEMATICS_ASSERTION_2(MathType::GetValue(0) <= exactly && exactly <= MathType::GetValue(1), "误差值错误！");

        return;
    }

    // 计算用于最快下降的线的四次多项式。
    const auto descentDirectionCrossAxis = Vector3Tools<Real>::CrossProduct(descentDirection, axis);
    auto c = Vector3Tools<Real>::GetLength(descentDirectionCrossAxis) * inverseNumPoints * inverseRadiusSquare;
    auto bMean = MathType::GetValue(0);
    auto abMean = MathType::GetValue(0);
    auto bbMean = MathType::GetValue(0);

    for (const auto& data : updateData)
    {
        const auto deltaCrossAxis = data.GetDeltaCrossAxis();
        auto a = inverseRadiusSquare * data.GetDeltaCrossAxisLengthQuartic() - MathType::GetValue(1);
        auto b = inverseRadiusSquare * (Vector3Tools<Real>::DotProduct(deltaCrossAxis, descentDirectionCrossAxis));
        bMean += b;
        abMean += a * b;
        bbMean += b * b;
    }
    bMean *= inverseNumPoints;
    abMean *= inverseNumPoints;
    bbMean *= inverseNumPoints;

    std::vector<Real> tuple{ aaMean,
                             MathType::GetValue(4) * abMean,
                             MathType::GetValue(2) * c * aMean + MathType::GetValue(4) * bbMean,
                             MathType::GetValue(4) * c * bMean,
                             c * c };

    Polynomial<Real> polynomial{ tuple };

    auto derivativePolynomial = polynomial.GetDerivative();

    PolynomialRoots<Real> polynomialRoots{ epsilon };
    if (!polynomialRoots.FindAlgebraic(derivativePolynomial[0], derivativePolynomial[1], derivativePolynomial[2], derivativePolynomial[3]))
    {
        return;
    }
    const auto count = polynomialRoots.GetCount();

    auto min = polynomial(MathType::GetValue(0));
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
    MATHEMATICS_ASSERTION_2(MathType::GetValue(0) <= exactly && exactly <= MathType::GetValue(1), "误差值错误！");

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
        if (MathType::GetValue(0) <= inverseRadiusSquare && MathType::GetValue(0) <= exactly && MathType::GetValue(0) <= epsilon && axis.IsNormalize(epsilon))
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
Real Mathematics::CylinderFit3Update<Real>::GetInverseRadiusSquare() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return inverseRadiusSquare;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DETAIL_H
