///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 15:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_ACHIEVE_H

#include "DistancePoint3Circle3.h"
#include "DistanceLine3Circle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

template <typename Real>
Mathematics::DistanceLine3Circle3<Real>::DistanceLine3Circle3(const Line3& line, const Circle3& circle) noexcept
    : ParentType{}, m_Line{ line }, m_Circle{ circle }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Circle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DistanceLine3Circle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::DistanceLine3Circle3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
typename const Mathematics::DistanceLine3Circle3<Real>::DistanceResult Mathematics::DistanceLine3Circle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedOrigin = m_Line.GetMove(t, lhsVelocity);
    const auto movedCenter = m_Circle.GetMove(t, rhsVelocity);

    ClassType distance{ movedOrigin, movedCenter };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
typename const Mathematics::DistanceLine3Circle3<Real>::DistanceResult Mathematics::DistanceLine3Circle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = m_Line.GetOrigin() - m_Circle.GetCenter();

    using ClosestPoints = typename DistanceResult::ClosestPoints;

    auto sqrDistance = Math::GetValue(0);
    ClosestPoints closestLine{};
    ClosestPoints closestCircle{};

    const auto lineCrossNormal = Vector3DTools::CrossProduct(m_Line.GetDirection(), m_Circle.GetNormal());
    auto dot = Vector3DTools::DotProduct(lineCrossNormal, lineCrossNormal);
    if (Math::GetValue(0) < dot)
    {
        auto dotSqrt = Math::Sqrt(dot);
        auto radiusMultiplyDotSqrt = m_Circle.GetRadius() * dotSqrt;
        auto diffCrossNormal = Vector3DTools::CrossProduct(diff, m_Circle.GetNormal());
        auto lambda = Vector3DTools::DotProduct(-lineCrossNormal, diffCrossNormal) / dot;
        diff += lambda * m_Line.GetDirection();
        diffCrossNormal += lambda * lineCrossNormal;
        auto lineDotDiff = Vector3DTools::DotProduct(m_Line.GetDirection(), diff);
        auto diffCrossNormalDot = Vector3DTools::DotProduct(diffCrossNormal, diffCrossNormal);
        if (Math::GetValue(0) < diffCrossNormalDot)
        {
            auto diffCrossNormalDotSqrt = Math::Sqrt(diffCrossNormalDot);
            auto radiusMultiplyDot = m_Circle.GetRadius() * dot;
            if (diffCrossNormalDotSqrt < radiusMultiplyDot)
            {
                constexpr auto twoThirds = Math::GetRational(2, 3);
                auto sHat = Math::Sqrt(Math::Pow(radiusMultiplyDot * diffCrossNormalDot, twoThirds) - diffCrossNormalDot) / dotSqrt;
                auto gHat = radiusMultiplyDot * sHat / Math::Sqrt(dot * sHat * sHat + diffCrossNormalDot);
                auto cutoff = gHat - sHat;
                if (lineDotDiff <= -cutoff)
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff, -lineDotDiff + radiusMultiplyDotSqrt);

                    auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();

                    auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.m_SqrDistance;

                    auto closestCircle0 = distanceInfo.m_ClosestCircle;
                    if (Math::Approximate(lineDotDiff, -cutoff))
                    {
                        auto closestLine1 = m_Line.GetOrigin() + (-sHat + lambda) * m_Line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.m_ClosestCircle;
                        if (distanceInfo.m_SqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.m_SqrDistance;

                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle1);
                        }
                        else
                        {
                            closestLine.emplace_back(closestLine0);
                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle0);
                            closestCircle.emplace_back(closestCircle1);
                        }
                    }
                    else
                    {
                        closestLine.emplace_back(closestLine0);

                        closestCircle.emplace_back(closestCircle0);
                    }
                }
                else if (cutoff <= lineDotDiff)
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -lineDotDiff);

                    auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                    auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.m_SqrDistance;

                    auto closestCircle0 = distanceInfo.m_ClosestCircle;
                    if (Math::Approximate(lineDotDiff, cutoff))
                    {
                        auto closestLine1 = m_Line.GetOrigin() + (+sHat + lambda) * m_Line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.m_ClosestCircle;
                        if (distanceInfo.m_SqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.m_SqrDistance;

                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle1);
                        }
                        else
                        {
                            closestLine.emplace_back(closestLine0);
                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle0);
                            closestCircle.emplace_back(closestCircle1);
                        }
                    }
                    else
                    {
                        closestLine.emplace_back(closestLine0);

                        closestCircle.emplace_back(closestCircle0);
                    }
                }
                else
                {
                    if (lineDotDiff <= Math::GetValue(0))
                    {
                        auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff, -lineDotDiff + radiusMultiplyDotSqrt);

                        auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                        auto distanceInfo = SqrDistancePointCircle(closestLine0);
                        sqrDistance = distanceInfo.m_SqrDistance;

                        auto closestCircle0 = distanceInfo.m_ClosestCircle;
                        bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -sHat);
                        auto closestLine1 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.m_ClosestCircle;
                        if (distanceInfo.m_SqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.m_SqrDistance;

                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle1);
                        }
                        else
                        {
                            closestLine.emplace_back(closestLine0);
                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle0);
                            closestCircle.emplace_back(closestCircle1);
                        }
                    }
                    else
                    {
                        auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -lineDotDiff);

                        auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                        auto distanceInfo = SqrDistancePointCircle(closestLine0);
                        sqrDistance = distanceInfo.m_SqrDistance;

                        auto closestCircle0 = distanceInfo.m_ClosestCircle;
                        bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, sHat, -lineDotDiff + radiusMultiplyDotSqrt);
                        auto closestLine1 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.m_ClosestCircle;
                        if (distanceInfo.m_SqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.m_SqrDistance;

                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle1);
                        }
                        else
                        {
                            closestLine.emplace_back(closestLine0);
                            closestLine.emplace_back(closestLine1);

                            closestCircle.emplace_back(closestCircle0);
                            closestCircle.emplace_back(closestCircle1);
                        }
                    }
                }
            }
            else
            {
                if (lineDotDiff < Math::GetValue(0))
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff, -lineDotDiff + radiusMultiplyDotSqrt);

                    auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.m_SqrDistance;

                    auto closestCircle0 = distanceInfo.m_ClosestCircle;

                    closestLine.emplace_back(closestLine0);

                    closestCircle.emplace_back(closestCircle0);
                }
                else if (Math::GetValue(0) < lineDotDiff)
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -lineDotDiff);

                    auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.m_SqrDistance;

                    auto closestCircle0 = distanceInfo.m_ClosestCircle;

                    closestLine.emplace_back(closestLine0);

                    closestCircle.emplace_back(closestCircle0);
                }
                else
                {
                    auto closestLine0 = m_Line.GetOrigin() + lambda * m_Line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.m_SqrDistance;

                    auto closestCircle0 = distanceInfo.m_ClosestCircle;

                    closestLine.emplace_back(closestLine0);

                    closestCircle.emplace_back(closestCircle0);
                }
            }
        }
        else
        {
            if (lineDotDiff < Math::GetValue(0))
            {
                auto bisect = -lineDotDiff + radiusMultiplyDotSqrt;

                auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.m_SqrDistance;

                auto closestCircle0 = distanceInfo.m_ClosestCircle;

                closestLine.emplace_back(closestLine0);

                closestCircle.emplace_back(closestCircle0);
            }
            else if (Math::GetValue(0) < lineDotDiff)
            {
                auto bisect = -lineDotDiff - radiusMultiplyDotSqrt;

                auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.m_SqrDistance;

                auto closestCircle0 = distanceInfo.m_ClosestCircle;

                closestLine.emplace_back(closestLine0);

                closestCircle.emplace_back(closestCircle0);
            }
            else
            {
                auto bisect = -lineDotDiff + radiusMultiplyDotSqrt;
                auto closestLine0 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.m_SqrDistance;

                auto closestCircle0 = distanceInfo.m_ClosestCircle;
                bisect = -lineDotDiff - radiusMultiplyDotSqrt;
                auto closestLine1 = m_Line.GetOrigin() + (bisect + lambda) * m_Line.GetDirection();
                distanceInfo = SqrDistancePointCircle(closestLine1);
                sqrDistance = distanceInfo.m_SqrDistance;

                auto closestCircle1 = distanceInfo.m_ClosestCircle;

                closestLine.emplace_back(closestLine0);
                closestLine.emplace_back(closestLine1);

                closestCircle.emplace_back(closestCircle0);
                closestCircle.emplace_back(closestCircle1);
            }
        }
    }
    else
    {
        auto closestLine0 = m_Line.GetOrigin() - Vector3DTools::DotProduct(m_Circle.GetNormal(), diff) * m_Circle.GetNormal();
        const auto distanceInfo = SqrDistancePointCircle(closestLine0);
        sqrDistance = distanceInfo.m_SqrDistance;

        auto closestCircle0 = distanceInfo.m_ClosestCircle;

        closestLine.emplace_back(closestLine0);

        closestCircle.emplace_back(closestCircle0);
    }

    return DistanceResult{ sqrDistance, Math::GetValue(0), closestLine, closestCircle };
}

template <typename Real>
Mathematics::DistanceLine3Circle3<Real>::DistanceInfo::DistanceInfo(Real sqrDistance, int numClosestCircle, const Vector3D& closestCircle) noexcept
    : m_SqrDistance{ sqrDistance }, m_NumClosestCircle{ numClosestCircle }, m_ClosestCircle{ closestCircle }
{
}

template <typename Real>
typename Mathematics::DistanceLine3Circle3<Real>::DistanceInfo Mathematics::DistanceLine3Circle3<Real>::SqrDistancePointCircle(const Vector3D& closestLine) const
{
    Vector3D closestCircle{};
    auto numClosestCircle = 0;
    auto lineMinusCenter = closestLine - m_Circle.GetCenter();
    auto dot = lineMinusCenter - Vector3DTools::DotProduct(m_Circle.GetNormal(), lineMinusCenter) * m_Circle.GetNormal();
    auto dotLength = Vector3DTools::VectorMagnitude(dot);
    if (Math::GetValue(0) < dotLength)
    {
        numClosestCircle = 1;
        closestCircle = m_Circle.GetCenter() + m_Circle.GetRadius() * dot / dotLength;
    }
    else
    {
        // 所有圆点都与P等距。返回其中一个。
        numClosestCircle = std::numeric_limits<int>::max();
        closestCircle = m_Circle.GetCenter() + m_Circle.GetRadius() * m_Circle.GetDirection0();
    }

    auto diff = closestLine - closestCircle;

    return DistanceInfo{ Vector3DTools::DotProduct(diff, diff), numClosestCircle, closestCircle };
}

template <typename Real>
Real Mathematics::DistanceLine3Circle3<Real>::BisectF(Real lineDotDiff, Real radiusMultiplyDot, Real dot, Real diffCrossNormalDot, Real smin, Real smax)
{
    auto s = Math::GetValue(0);
    constexpr auto maximumIterations = 1024;

    for (auto i = 0; i < maximumIterations; ++i)
    {
        s = (Math::GetRational(1, 2)) * (smin + smax);
        auto f = s + lineDotDiff - radiusMultiplyDot * s / Math::Sqrt(dot * s * s + diffCrossNormalDot);
        if (Math::Approximate(f, Math::GetValue(0)) || Math::Approximate(s, smin) || Math::Approximate(s, smax))
        {
            return s;
        }

        if (Math::GetValue(0) < f)
        {
            smax = s;
        }
        else
        {
            smin = s;
        }
    }

    MATHEMATICS_ASSERTION_0(false, "超过最大迭代次数。");

    return s;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_ACHIEVE_H