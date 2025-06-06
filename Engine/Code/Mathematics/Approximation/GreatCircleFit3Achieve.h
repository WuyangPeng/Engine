///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:13)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_ACHIEVE_H

#include "GreatCircleFit3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::GreatCircleFit3<Real>::GreatCircleFit3(const Points& points)
    : normal{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::GreatCircleFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::GreatCircleFit3<Real>::GetNormal() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <typename Real>
void Mathematics::GreatCircleFit3<Real>::Calculate(const Points& points)
{
    // 计算向量的协方差矩阵。
    auto sumXX = MathType::GetValue(0);
    auto sumXY = MathType::GetValue(0);
    auto sumXZ = MathType::GetValue(0);
    auto sumYY = MathType::GetValue(0);
    auto sumYZ = MathType::GetValue(0);
    auto sumZZ = MathType::GetValue(0);
    const auto numPoints = boost::numeric_cast<Real>(points.size());

    for (const auto& point : points)
    {
        sumXX += point.GetX() * point.GetX();
        sumXY += point.GetX() * point.GetY();
        sumXZ += point.GetX() * point.GetZ();
        sumYY += point.GetY() * point.GetY();
        sumYZ += point.GetY() * point.GetZ();
        sumZZ += point.GetZ() * point.GetZ();
    }

    sumXX /= numPoints;
    sumXY /= numPoints;
    sumXZ /= numPoints;
    sumYY /= numPoints;
    sumYZ /= numPoints;
    sumZZ /= numPoints;

    // 建立 eigensolver.
    EigenDecomposition<Real> eigenSystem{ 3 };
    eigenSystem(0, 0) = sumXX;
    eigenSystem(0, 1) = sumXY;
    eigenSystem(0, 2) = sumXZ;
    eigenSystem(1, 0) = eigenSystem(0, 1);
    eigenSystem(1, 1) = sumYY;
    eigenSystem(1, 2) = sumYZ;
    eigenSystem(2, 0) = eigenSystem(0, 2);
    eigenSystem(2, 1) = eigenSystem(1, 2);
    eigenSystem(2, 2) = sumZZ;

    // 计算特征值，最小的特征值处于最后的位置。
    eigenSystem.Solve(false);

    // 最佳拟合大圆单位长度方向。
    normal = eigenSystem.GetEigenvector3(2);
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_CIRCLE_FIT3_ACHIEVE_H
