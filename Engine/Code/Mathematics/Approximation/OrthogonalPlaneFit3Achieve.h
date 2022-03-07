///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 14:52)

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
    // ������ƽ��ֵ��
    Vector3 origin{};
    for (const auto& point : points)
    {
        origin += point;
    }

    const auto numPoints = boost::numeric_cast<Real>(points.size());
    origin /= numPoints;

    // �����Ʒ�ܺ�
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

    // ���� eigensolver.
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

    // ��������ֵ����С������ֵ��������λ�á�
    esystem.Solve(false);

    // ��ȡƽ�淨��
    const auto normal = esystem.GetEigenvector3(2);

    // ��С����
    return Plane3{ normal, origin };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_PLANE_FIT3_ACHIEVE_H
