///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 14:07)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_ACHIEVE_H

#include "GaussPointsFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::GaussPointsFit3<Real>::GaussPointsFit3(const PointsType& points)
    : m_Box{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GaussPointsFit3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::GaussPointsFit3<Real>::GetBox3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Box;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::GaussPointsFit3<Real>::Calculate(const PointsType& points)
{
    const auto numPoints = static_cast<Real>(points.size());

    // ������ƽ��ֵ��
    Vector3D center{};
    for (const auto& point : points)
    {
        center += point;
    }

    center /= numPoints;

    // ������Э�������
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    auto sumXZ = Math::GetValue(0);
    auto sumYZ = Math::GetValue(0);
    auto sumZZ = Math::GetValue(0);

    for (const auto& point : points)
    {
        auto diff = point - center;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumXZ += diff.GetX() * diff.GetZ();
        sumYY += diff.GetY() * diff.GetY();
        sumYZ += diff.GetY() * diff.GetZ();
        sumZZ += diff.GetZ() * diff.GetZ();
    }

    sumXX /= numPoints;
    sumXY /= numPoints;
    sumYY /= numPoints;
    sumXZ /= numPoints;
    sumYZ /= numPoints;
    sumZZ /= numPoints;

    // ���� eigensolver.
    constexpr const auto size = 3;

    EigenDecomposition<Real> eigenSystem{ size };

    eigenSystem(0, 0) = sumXX;
    eigenSystem(0, 1) = sumXY;
    eigenSystem(0, 2) = sumXZ;
    eigenSystem(1, 0) = sumXY;
    eigenSystem(1, 1) = sumYY;
    eigenSystem(1, 2) = sumYZ;
    eigenSystem(2, 0) = sumXZ;
    eigenSystem(2, 1) = sumYZ;
    eigenSystem(2, 2) = sumZZ;

    eigenSystem.Solve(true);

    std::array<Real, size> extent{};
    std::array<Vector3D, size> axis{};

    for (auto i = 0; i < size; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        extent[i] = eigenSystem.GetEigenvalue(i);
        axis[i] = eigenSystem.GetEigenvector3(i);
    }

    return Box3{ center, axis[0], axis[1], axis[2], extent[0], extent[1], extent[2] };

#include STSTEM_WARNING_POP
}

#endif  // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_ACHIEVE_H