///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/18 13:49)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H

#include "OrthogonalLineFit2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
Mathematics::OrthogonalLineFit2<Real>::OrthogonalLineFit2(const Points& points)
    : line{ Calculate(points) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::OrthogonalLineFit2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::OrthogonalLineFit2<Real>::GetLine2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

// static
template <typename Real>
typename Mathematics::OrthogonalLineFit2<Real>::Line2 Mathematics::OrthogonalLineFit2<Real>::Calculate(const Points& points)
{
    // ������ƽ��ֵ��
    Vector2 origin{};
    for (const auto& point : points)
    {
        origin += point;
    }

    origin /= boost::numeric_cast<Real>(points.size());

    // ������Э�������
    auto sumXX = Math::GetValue(0);
    auto sumXY = Math::GetValue(0);
    auto sumYY = Math::GetValue(0);
    for (const auto& point : points)
    {
        auto diff = point - origin;
        sumXX += diff.GetX() * diff.GetX();
        sumXY += diff.GetX() * diff.GetY();
        sumYY += diff.GetY() * diff.GetY();
    }

    sumXX /= boost::numeric_cast<Real>(points.size());
    sumXY /= boost::numeric_cast<Real>(points.size());
    sumYY /= boost::numeric_cast<Real>(points.size());

    // ���� eigensolver.
    EigenDecomposition<Real> eigenSystem{ 2 };
    eigenSystem(0, 0) = sumYY;
    eigenSystem(0, 1) = -sumXY;
    eigenSystem(1, 0) = -sumXY;
    eigenSystem(1, 1) = sumXX;

    // ��������ֵ����С��������������λ�á�
    eigenSystem.Solve(false);

    // �����������ߵĵ�λ���ȷ���
    const auto direction = eigenSystem.GetEigenvector2(1);

    return Line2{ origin, direction };
}

#endif  // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_ACHIEVE_H
