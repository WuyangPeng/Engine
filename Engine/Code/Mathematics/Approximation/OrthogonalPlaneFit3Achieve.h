///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/18 14:52)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_ACHIEVE_H

#include "OrthogonalPlaneFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::OrthogonalPlaneFit3<Real>::OrthogonalPlaneFit3(const Points& points)
    : plane3{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::OrthogonalPlaneFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::OrthogonalPlaneFit3<Real>::GetPlane3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane3;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::OrthogonalPlaneFit3<Real>::Calculate(const Points& points)
{
    // 计算点的平均值。
    Vector3 origin{};
    for (const auto& point : points)
    {
        origin += point;
    }

    const auto numPoints = boost::numeric_cast<Real>(points.size());
    origin /= numPoints;

    // 计算产品总和
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumXZ = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    auto sumYZ = Math::GetValue(0);
    auto sumZZ = Math::GetValue(0);

    for (const auto& point : points)
    {
        auto diff = point - origin;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumXZ += diff.GetX() * diff.GetZ();
        sumYY += diff.GetY() * diff.GetY();
        sumYZ += diff.GetY() * diff.GetZ();
        sumZZ += diff.GetZ() * diff.GetZ();
    }

    sumXX /= numPoints;
    sumXY /= numPoints;
    sumXZ /= numPoints;
    sumYY /= numPoints;
    sumYZ /= numPoints;
    sumZZ /= numPoints;

    // 建立 eigensolver.
    EigenDecomposition<Real> esystem{ 3 };
    esystem(0, 0) = sumXX;
    esystem(0, 1) = sumXY;
    esystem(0, 2) = sumXZ;
    esystem(1, 0) = sumXY;
    esystem(1, 1) = sumYY;
    esystem(1, 2) = sumYZ;
    esystem(2, 0) = sumXZ;
    esystem(2, 1) = sumYZ;
    esystem(2, 2) = sumZZ;

    // 计算特征值，最小的特征值是在最后的位置。
    esystem.Solve(false);

    // 获取平面法线
    const auto normal = esystem.GetEigenvector3(2);

    // 最小能量
    return Plane3{ normal, origin };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_ACHIEVE_H
