///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 13:43)

#ifndef MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_ACHIEVE_H

#include "HeightLineFit2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::HeightLineFit2<Real>::HeightLineFit2(const Points& points)
    : coeffA{}, coeffB{}, isFit2Success{ false }
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::HeightLineFit2<Real>::Calculate(const Points& points)
{
    // 你至少需要两个点确定线就行了
    // 即使这样，如果点在一条垂直线，没有最小平方拟合的“高度”的感觉。
    // 这将陷入由系数矩阵存在（几乎）零的行列式。

    // 计算线性系统的总和。
    Real sumX{};
    Real sumY{};
    Real sumXX{};
    Real sumXY{};

    const auto numPoints = static_cast<Real>(points.size());
    for (const auto& point : points)
    {
        sumX += point.GetX();
        sumY += point.GetY();
        sumXX += point.GetX() * point.GetX();
        sumXY += point.GetX() * point.GetY();
    }

    using Vector = typename LinearSystem<Real>::Vector2;
    using Matrix2 = typename LinearSystem<Real>::Matrix2;

    Matrix2 matrix{ Vector{ sumXX, sumX }, Vector{ sumX, numPoints } };

    const Vector inputVector{ sumXY, sumY };

    try
    {
        const LinearSystem<Real> linearSystem{};

        auto outputVector = linearSystem.Solve2(matrix, inputVector);

        coeffA = outputVector.at(0);
        coeffB = outputVector.at(1);
        isFit2Success = true;
    }
    catch (CoreTools::Error&)
    {
        isFit2Success = false;
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightLineFit2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::HeightLineFit2<Real>::IsFit2Success() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isFit2Success;
}

template <typename Real>
Real Mathematics::HeightLineFit2<Real>::GetCoeffA() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (IsFit2Success())
    {
        return coeffA;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("拟合失败"s));
    }
}

template <typename Real>
Real Mathematics::HeightLineFit2<Real>::GetCoeffB() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (IsFit2Success())
    {
        return coeffB;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("拟合失败"s));
    }
}

#endif  // MATHEMATICS_APPROXIMATION_HEIGHT_LINT_FIT2_ACHIEVE_H