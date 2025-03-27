///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 14:08)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H

#include "CircleFit2.h"
#include "QuadraticCircleFit2Detail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::CircleFit2<Real>::CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage)
    : circle{}
{
    Calculate(points, maxIterations, initialCenterIsAverage);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::CircleFit2<Real>::Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage)
{
    // �������ݵ��ƽ��ֵ��
    const auto average = GetAveragePoint(points);

    // �²��ʼ���ġ�
    if (initialCenterIsAverage)
    {
        circle.SetCircle(average, MathType::GetValue(0));
    }
    else
    {
        const QuadraticCircleFit2<Real> fit2{ points };

        circle.SetCircle(fit2.GetCenter(), fit2.GetRadius());
    }

    for (auto loop = 0; loop < maxIterations; ++loop)
    {
        const auto current = circle.GetCenter();

        // ���µ���
        Iteration(points, average);

        const auto circleDifference = circle.GetCenter() - current;

        if (MathType::FAbs(circleDifference[0]) <= MathType::GetZeroTolerance() &&
            MathType::FAbs(circleDifference[1]) <= MathType::GetZeroTolerance())
        {
            return;
        }

        MATHEMATICS_ASSERTION_4(loop + 1 != maxIterations, "��������������");
    }
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::CircleFit2<Real>::GetAveragePoint(const PointType& points)
{
    MATHEMATICS_ASSERTION_0(!points.empty(), "����������СΪ�㣡");

    Vector2Type average{};

    for (const auto& value : points)
    {
        average += value;
    }

    average /= boost::numeric_cast<Real>(points.size());

    return average;
}

template <typename Real>
void Mathematics::CircleFit2<Real>::Iteration(const PointType& points, const Vector2Type& average)
{
    // ����ƽ��ֵL, dL/da, dL/db��
    auto lengthAverage = MathType::GetValue(0);
    Vector2Type derLengthAverage{};

    for (const auto& value : points)
    {
        auto difference = value - circle.GetCenter();

        auto length = Vector2Tools<Real>::GetLength(difference);
        if (MathType::GetZeroTolerance() < length)
        {
            lengthAverage += length;
            derLengthAverage -= difference / length;
        }
    }

    lengthAverage /= boost::numeric_cast<Real>(points.size());
    derLengthAverage /= boost::numeric_cast<Real>(points.size());

    circle.SetCircle(average + lengthAverage * derLengthAverage, lengthAverage);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::CircleFit2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::CircleFit2<Real>::Circle2Type Mathematics::CircleFit2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return circle;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H
