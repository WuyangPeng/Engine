///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:22)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_ACHIEVE_H

#include "QuadraticSphereFit3.h"
#include "SphereFit3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::SphereFit3<Real>::SphereFit3(const Points& points, int maxIterations, bool initialCenterIsAverage)
    : sphere{}
{
    Calculate(points, maxIterations, initialCenterIsAverage);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SphereFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::SphereFit3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
void Mathematics::SphereFit3<Real>::Calculate(const Points& points, int maxIterations, bool initialCenterIsAverage)
{
    const auto average = GetAveragePoint(points);

    // �²��ʼ���ġ�
    if (initialCenterIsAverage)
    {
        sphere.SetSphere(average, Math::GetValue(0));
    }
    else
    {
        const QuadraticSphereFit3<Real> fit3{ points };

        sphere.SetSphere(fit3.GetCenter(), fit3.GetRadius());
    }

    for (auto loop = 0; loop < maxIterations; ++loop)
    {
        const auto current = sphere.GetCenter();

        // ���µ���
        Iteration(points, average);

        const auto circleDifference = sphere.GetCenter() - current;

        if (Math::FAbs(circleDifference[0]) <= Math::GetZeroTolerance() &&
            Math::FAbs(circleDifference[1]) <= Math::GetZeroTolerance())
        {
            return;
        }

        MATHEMATICS_ASSERTION_4(loop + 1 != maxIterations, "��������������");
    }
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::SphereFit3<Real>::GetAveragePoint(const Points& points)
{
    MATHEMATICS_ASSERTION_0(!points.empty(), "����������СΪ�㣡");

    // �������ݵ��ƽ��ֵ��
    Vector3 average{};

    const auto numPoints = boost::numeric_cast<Real>(points.size());

    for (const auto& point : points)
    {
        average += point;
    }

    average /= numPoints;

    return average;
}

template <typename Real>
void Mathematics::SphereFit3<Real>::Iteration(const Points& points, const Vector3& average)
{
    auto numPoints = boost::numeric_cast<Real>(points.size());

    // ����ƽ��ֵL, dL/da, dL/db, dL/dc��
    auto lengthAverage = Math::GetValue(0);
    Vector3 derLengthAverage{};

    for (const auto& point : points)
    {
        auto difference = point - sphere.GetCenter();

        auto length = Vector3Tools<Real>::GetLength(difference);
        if (Math::GetZeroTolerance() < length)
        {
            lengthAverage += length;
            derLengthAverage -= difference / length;
        }
    }

    lengthAverage /= numPoints;
    derLengthAverage /= numPoints;

    sphere.SetSphere(average + lengthAverage * derLengthAverage, lengthAverage);
}

#endif  // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_ACHIEVE_H
