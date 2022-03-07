// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 12:52)

#include "DistancePoint2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Segment2Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
    template class DistancePoint2Segment2<float>;
    template class DistancePoint2Segment2<double>;
}
#include SYSTEM_WARNING_DISABLE(26496)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint2Segment2Testing)

void Mathematics::DistancePoint2Segment2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistancePoint2Segment2Testing ::BaseTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F point(randomDistribution(generator), randomDistribution(generator));

        Vector2F rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        float rhsExtent = MathF::FAbs(randomDistribution(generator));

        DistancePoint2Segment2F distance(point, Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, distance.GetPoint(), point, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetSegment(), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
    }
}

void Mathematics::DistancePoint2Segment2Testing ::StaticTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 point(randomDistribution(generator), randomDistribution(generator));

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistancePoint2Segment2D distance(point, Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult2D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8);

        Vector2 rhsDifference = rhsOrigin - squaredResult.GetRhsClosestPoint();
        if (!rhsDifference.IsZero())
        {
            ASSERT_TRUE(Vector2ToolsD::GetLength(rhsDifference) <= rhsExtent + 1e-10);
            rhsDifference.Normalize();
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-10));
        }

        DistanceResult2D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint2Segment2Testing ::DynamicTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 point(randomDistribution(generator), randomDistribution(generator));

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistancePoint2Segment2D distance(point, Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);

        Vector2 rhsDifference = rhsOrigin + t * rhsVelocity - squaredResult.GetRhsClosestPoint();
        if (!rhsDifference.IsZero())
        {
            ASSERT_TRUE(Vector2ToolsD::GetLength(rhsDifference) <= rhsExtent + 1e-10);
            rhsDifference.Normalize();
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-10));
        }

        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint2Segment2Testing ::DerivativeTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 point(randomDistribution(generator), randomDistribution(generator));

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistancePoint2Segment2D distance(point, Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult2D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        double derivativeApproximation =
            0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult2D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistancePoint2Segment2Testing ::IntervalTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 point(randomDistribution(generator), randomDistribution(generator));

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistancePoint2Segment2D distance(point, Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-4);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_LESS_EQUAL(result.GetDistance(), tResult.GetDistance() + 1e-5);
            ASSERT_LESS_EQUAL(squaredResult.GetDistance(), tResultSquared.GetDistance());
        }
    }
}
