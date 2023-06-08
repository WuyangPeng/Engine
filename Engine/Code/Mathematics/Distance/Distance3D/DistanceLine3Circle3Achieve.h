///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 18:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_CIRCLE3_ACHIEVE_H

#include "DistanceLine3Circle3.h"
#include "DistancePoint3Circle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRoots.h"

template <typename Real>
Mathematics::DistanceLine3Circle3<Real>::DistanceLine3Circle3(const Line3& line, const Circle3& circle) noexcept
    : ParentType{}, line{ line }, circle{ circle }
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
Mathematics::Line3<Real> Mathematics::DistanceLine3Circle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::DistanceLine3Circle3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
typename Mathematics::DistanceLine3Circle3<Real>::DistanceResult Mathematics::DistanceLine3Circle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedOrigin = line.GetMove(t, lhsVelocity);
    const auto movedCenter = circle.GetMove(t, rhsVelocity);

    ClassType distance{ movedOrigin, movedCenter };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
typename Mathematics::DistanceLine3Circle3<Real>::DistanceResult Mathematics::DistanceLine3Circle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto diff = line.GetOrigin() - circle.GetCenter();

    using ClosestPoints = typename DistanceResult::ClosestPoints;

    Real sqrDistance{};
    ClosestPoints closestLine{};
    ClosestPoints closestCircle{};

    const auto lineCrossNormal = Vector3Tools::CrossProduct(line.GetDirection(), circle.GetNormal());
    const auto dot = Vector3Tools::DotProduct(lineCrossNormal, lineCrossNormal);
    if (Math::GetValue(0) < dot)
    {
        const auto dotSqrt = Math::Sqrt(dot);
        const auto radiusMultiplyDotSqrt = circle.GetRadius() * dotSqrt;
        auto diffCrossNormal = Vector3Tools::CrossProduct(diff, circle.GetNormal());
        const auto lambda = Vector3Tools::DotProduct(-lineCrossNormal, diffCrossNormal) / dot;
        diff += lambda * line.GetDirection();
        diffCrossNormal += lambda * lineCrossNormal;
        const auto lineDotDiff = Vector3Tools::DotProduct(line.GetDirection(), diff);
        const auto diffCrossNormalDot = Vector3Tools::DotProduct(diffCrossNormal, diffCrossNormal);
        if (Math::GetValue(0) < diffCrossNormalDot)
        {
            const auto diffCrossNormalDotSqrt = Math::Sqrt(diffCrossNormalDot);
            const auto radiusMultiplyDot = circle.GetRadius() * dot;
            if (diffCrossNormalDotSqrt < radiusMultiplyDot)
            {
                constexpr auto twoThirds = Math::GetRational(2, 3);
                auto sHat = Math::Sqrt(Math::Pow(radiusMultiplyDot * diffCrossNormalDot, twoThirds) - diffCrossNormalDot) / dotSqrt;
                auto gHat = radiusMultiplyDot * sHat / Math::Sqrt(dot * sHat * sHat + diffCrossNormalDot);
                auto cutoff = gHat - sHat;
                if (lineDotDiff <= -cutoff)
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff, -lineDotDiff + radiusMultiplyDotSqrt);

                    auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();

                    auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.sqrDistance;

                    auto closestCircle0 = distanceInfo.closestCircle;
                    if (Math::Approximate(lineDotDiff, -cutoff))
                    {
                        auto closestLine1 = line.GetOrigin() + (-sHat + lambda) * line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.closestCircle;
                        if (distanceInfo.sqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.sqrDistance;

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

                    auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                    auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.sqrDistance;

                    auto closestCircle0 = distanceInfo.closestCircle;
                    if (Math::Approximate(lineDotDiff, cutoff))
                    {
                        auto closestLine1 = line.GetOrigin() + (+sHat + lambda) * line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.closestCircle;
                        if (distanceInfo.sqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.sqrDistance;

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

                        auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                        auto distanceInfo = SqrDistancePointCircle(closestLine0);
                        sqrDistance = distanceInfo.sqrDistance;

                        auto closestCircle0 = distanceInfo.closestCircle;
                        bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -sHat);
                        auto closestLine1 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.closestCircle;
                        if (distanceInfo.sqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.sqrDistance;

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

                        auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                        auto distanceInfo = SqrDistancePointCircle(closestLine0);
                        sqrDistance = distanceInfo.sqrDistance;

                        auto closestCircle0 = distanceInfo.closestCircle;
                        bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, sHat, -lineDotDiff + radiusMultiplyDotSqrt);
                        auto closestLine1 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                        distanceInfo = SqrDistancePointCircle(closestLine1);

                        auto closestCircle1 = distanceInfo.closestCircle;
                        if (distanceInfo.sqrDistance < sqrDistance)
                        {
                            sqrDistance = distanceInfo.sqrDistance;

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

                    auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.sqrDistance;

                    auto closestCircle0 = distanceInfo.closestCircle;

                    closestLine.emplace_back(closestLine0);

                    closestCircle.emplace_back(closestCircle0);
                }
                else if (Math::GetValue(0) < lineDotDiff)
                {
                    auto bisect = BisectF(lineDotDiff, radiusMultiplyDot, dot, diffCrossNormalDot, -lineDotDiff - radiusMultiplyDotSqrt, -lineDotDiff);

                    auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.sqrDistance;

                    auto closestCircle0 = distanceInfo.closestCircle;

                    closestLine.emplace_back(closestLine0);

                    closestCircle.emplace_back(closestCircle0);
                }
                else
                {
                    auto closestLine0 = line.GetOrigin() + lambda * line.GetDirection();
                    const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                    sqrDistance = distanceInfo.sqrDistance;

                    auto closestCircle0 = distanceInfo.closestCircle;

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

                auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.sqrDistance;

                auto closestCircle0 = distanceInfo.closestCircle;

                closestLine.emplace_back(closestLine0);

                closestCircle.emplace_back(closestCircle0);
            }
            else if (Math::GetValue(0) < lineDotDiff)
            {
                auto bisect = -lineDotDiff - radiusMultiplyDotSqrt;

                auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                const auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.sqrDistance;

                auto closestCircle0 = distanceInfo.closestCircle;

                closestLine.emplace_back(closestLine0);

                closestCircle.emplace_back(closestCircle0);
            }
            else
            {
                auto bisect = -lineDotDiff + radiusMultiplyDotSqrt;
                auto closestLine0 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                auto distanceInfo = SqrDistancePointCircle(closestLine0);
                sqrDistance = distanceInfo.sqrDistance;

                auto closestCircle0 = distanceInfo.closestCircle;
                bisect = -lineDotDiff - radiusMultiplyDotSqrt;
                auto closestLine1 = line.GetOrigin() + (bisect + lambda) * line.GetDirection();
                distanceInfo = SqrDistancePointCircle(closestLine1);
                sqrDistance = distanceInfo.sqrDistance;

                auto closestCircle1 = distanceInfo.closestCircle;

                closestLine.emplace_back(closestLine0);
                closestLine.emplace_back(closestLine1);

                closestCircle.emplace_back(closestCircle0);
                closestCircle.emplace_back(closestCircle1);
            }
        }
    }
    else
    {
        auto closestLine0 = line.GetOrigin() - Vector3Tools::DotProduct(circle.GetNormal(), diff) * circle.GetNormal();
        const auto distanceInfo = SqrDistancePointCircle(closestLine0);
        sqrDistance = distanceInfo.sqrDistance;

        auto closestCircle0 = distanceInfo.closestCircle;

        closestLine.emplace_back(closestLine0);

        closestCircle.emplace_back(closestCircle0);
    }

    return DistanceResult{ sqrDistance, Math::GetValue(0), closestLine, closestCircle };
}

template <typename Real>
Mathematics::DistanceLine3Circle3<Real>::DistanceInfo::DistanceInfo(Real sqrDistance, int numClosestCircle, const Vector3& closestCircle) noexcept
    : sqrDistance{ sqrDistance }, numClosestCircle{ numClosestCircle }, closestCircle{ closestCircle }
{
}

template <typename Real>
typename Mathematics::DistanceLine3Circle3<Real>::DistanceInfo Mathematics::DistanceLine3Circle3<Real>::SqrDistancePointCircle(const Vector3& closestLine) const
{
    Vector3 closestCircle{};
    auto numClosestCircle = 0;
    auto lineMinusCenter = closestLine - circle.GetCenter();
    auto dot = lineMinusCenter - Vector3Tools::DotProduct(circle.GetNormal(), lineMinusCenter) * circle.GetNormal();
    auto dotLength = Vector3Tools::GetLength(dot);
    if (Math::GetValue(0) < dotLength)
    {
        numClosestCircle = 1;
        closestCircle = circle.GetCenter() + circle.GetRadius() * dot / dotLength;
    }
    else
    {
        // 所有圆点都与P等距。返回其中一个。
        numClosestCircle = std::numeric_limits<int>::max();
        closestCircle = circle.GetCenter() + circle.GetRadius() * circle.GetDirection0();
    }

    const auto diff = closestLine - closestCircle;

    return DistanceInfo{ Vector3Tools::DotProduct(diff, diff), numClosestCircle, closestCircle };
}

template <typename Real>
Real Mathematics::DistanceLine3Circle3<Real>::BisectF(Real lineDotDiff, Real radiusMultiplyDot, Real dot, Real diffCrossNormalDot, Real smin, Real smax)
{
    Real s{};
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