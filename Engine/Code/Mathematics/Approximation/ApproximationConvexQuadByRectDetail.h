/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 16:51)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_DETAIL_H

#include "ApproximationConvexQuadByRect.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationConvexQuadByRect<Real>::ApproximationConvexQuadByRect() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationConvexQuadByRect<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationConvexQuadByRect<Real>::OrientedBox2 Mathematics::ApproximationConvexQuadByRect<Real>::Fit(const std::array<Vector2, 4>& p)
{
    OrientedBox2 rectangle{};

    rectangle.SetCenter(Math::GetRational(1, 4) * (p.at(0) + p.at(1) + p.at(2) + p.at(3)));

    std::array<Vector2, 4> q{};
    for (auto i = 0; i < 4; ++i)
    {
        q.at(i) = p.at(i) - rectangle.GetCenter();
    }

    auto q0MQ2 = q.at(0) - q.at(2);
    auto q1MQ3 = q.at(1) - q.at(3);
    auto k0 = q1MQ3[0] * q0MQ2[1] + q0MQ2[0] * q1MQ3[1];
    auto k1 = q1MQ3[0] * q0MQ2[0] - q1MQ3[1] * q0MQ2[1];
    auto theta = Math::GetRational(1, 2) * std::atan2(k0, k1);
    const auto cosTheta = std::cos(theta);
    const auto sinTheta = std::sin(theta);
    rectangle.SetAxis(0, { cosTheta, sinTheta });
    rectangle.SetAxis(1, { -sinTheta, cosTheta });

    auto s0Ms2 = Dot(rectangle.GetAxis(0), q0MQ2);
    auto s1Ms3 = Dot(rectangle.GetAxis(0), q1MQ3);
    auto t0Mt2 = Dot(rectangle.GetAxis(1), q0MQ2);
    auto t1Mt3 = Dot(rectangle.GetAxis(1), q1MQ3);
    auto gDer2Test = s0Ms2 * s1Ms3 - t0Mt2 * t1Mt3;
    if (gDer2Test < Real{})
    {
        rectangle.SetAxis(0, { -sinTheta, cosTheta });
        rectangle.SetAxis(1, { -cosTheta, -sinTheta });
        auto oldT0Mt2 = t0Mt2;
        auto oldT1Mt3 = t1Mt3;
        t0Mt2 = -s0Ms2;
        t1Mt3 = -s1Ms3;
        s0Ms2 = oldT0Mt2;
        s1Ms3 = oldT1Mt3;
    }
    rectangle.SetExtent(0, Math::GetRational(1, 4) * (s0Ms2 + s1Ms3));
    rectangle.SetExtent(1, Math::GetRational(1, 4) * (t0Mt2 - t1Mt3));

    return rectangle;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONVEX_QUAD_BY_RECT_DETAIL_H
