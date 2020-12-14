///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/11/30 17:51)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H

#include "CircleFit2.h"
#include "QuadraticCircleFit2Detail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::CircleFit2<Real>::CircleFit2(const PointType& points, int maxIterations, bool initialCenterIsAverage)
    : m_Circle{}
{
    Calculate(points, maxIterations, initialCenterIsAverage);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::CircleFit2<Real>::Calculate(const PointType& points, int maxIterations, bool initialCenterIsAverage)
{
    // �������ݵ��ƽ��ֵ��
    const auto average = GetAveragePoint(points);

    // �²��ʼ���ġ�
    if (initialCenterIsAverage)
    {
        m_Circle.SetCircle(average, Math::GetValue(0));
    }
    else
    {
        const QuadraticCircleFit2<Real> fit2{ points };

        m_Circle.SetCircle(fit2.GetCenter(), fit2.GetRadius());
    }

    for (auto loop = 0; loop < maxIterations; ++loop)
    {
        const auto current = m_Circle.GetCenter();

        // ���µ���
        Iteration(points, average);

        auto circleDifference = m_Circle.GetCenter() - current;

        if (Math::FAbs(circleDifference[0]) <= Math::GetZeroTolerance() &&
            Math::FAbs(circleDifference[1]) <= Math::GetZeroTolerance())
        {
            return;
        }

        MATHEMATICS_ASSERTION_4(loop + 1 != maxIterations, "��������������");
    }
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::CircleFit2<Real>::GetAveragePoint(const PointType& points)
{
    MATHEMATICS_ASSERTION_0(!points.empty(), "����������СΪ�㣡");

    Vector2D average{};

    for (const auto& value : points)
    {
        average += value;
    }

    average /= boost::numeric_cast<Real>(points.size());

    return average;
}

template <typename Real>
void Mathematics::CircleFit2<Real>::Iteration(const PointType& points, const Vector2D& average)
{
    // ����ƽ��ֵL, dL/da, dL/db��
    auto lengthAverage = Math::GetValue(0);
    Vector2D derLenghtAverage{};

    for (const auto& value : points)
    {
        auto difference = value - m_Circle.GetCenter();

        auto length = Vector2DTools<Real>::VectorMagnitude(difference);
        if (Math::GetZeroTolerance() < length)
        {
            lengthAverage += length;
            derLenghtAverage -= difference / length;
        }
    }

    lengthAverage /= boost::numeric_cast<Real>(points.size());
    derLenghtAverage /= boost::numeric_cast<Real>(points.size());

    m_Circle.SetCircle(average + lengthAverage * derLenghtAverage, lengthAverage);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::CircleFit2<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::CircleFit2<Real>::Circle2 Mathematics::CircleFit2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Circle;
}

#endif  // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_ACHIEVE_H
