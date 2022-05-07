// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/30 10:47)

#include "DistanceLine2Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_real;

namespace Mathematics
{
    template class DistanceLine2Line2<float>;
    template class DistanceLine2Line2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceLine2Line2Testing)

void Mathematics::DistanceLine2Line2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::DistanceLine2Line2Testing ::BaseTest()
{
    default_random_engine generator;
    uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        Vector2F rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceLine2Line2<float> distance(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, rhsDirection));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetLhsLine(), Line2F(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetRhsLine(), Line2F(rhsOrigin, rhsDirection), 1e-8f);
    }
}

void Mathematics::DistanceLine2Line2Testing ::StaticTest()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceLine2Line2<double> distance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));

        DistanceResult2D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);

        Vector2 lhsDifference = lhsOrigin - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) || Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        Vector2 rhsDifference = rhsOrigin - squaredResult.GetRhsClosestPoint();
        rhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-10) || Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-10));

        DistanceResult2D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine2Line2<double> equalDistance(Line2D(lhsOrigin, lhsDirection), Line2D(lhsOrigin + lhsDirection, lhsDirection));

        squaredResult = equalDistance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);

        lhsDifference = lhsOrigin - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        rhsDifference = lhsOrigin + lhsDirection - squaredResult.GetRhsClosestPoint();
        ASSERT_TRUE(rhsDifference.IsZero());

        result = equalDistance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine2Line2<double> parallelDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, lhsDirection));

        squaredResult = parallelDistance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

        lhsDifference = lhsOrigin - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        rhsDifference = rhsOrigin - squaredResult.GetRhsClosestPoint();
        ASSERT_TRUE(rhsDifference.IsZero());

        result = parallelDistance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistanceLine2Line2Testing ::DynamicTest()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceLine2Line2<double> distance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);

        Vector2 lhsDifference = lhsOrigin + t * lhsVelocity - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        Vector2 rhsDifference = rhsOrigin + t * rhsVelocity - squaredResult.GetRhsClosestPoint();
        rhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-10));

        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine2Line2<double> equalDistance(Line2D(lhsOrigin, lhsDirection), Line2D(lhsOrigin + lhsDirection, lhsDirection));

        squaredResult = equalDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

        lhsDifference = lhsOrigin + t * lhsVelocity - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        rhsDifference = lhsOrigin + lhsDirection + t * rhsVelocity - squaredResult.GetRhsClosestPoint();
        ASSERT_TRUE(rhsDifference.IsZero());

        result = equalDistance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);

        DistanceLine2Line2<double> parallelDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, lhsDirection));

        squaredResult = parallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

        lhsDifference = lhsOrigin + t * lhsVelocity - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        rhsDifference = rhsOrigin + t * rhsVelocity - squaredResult.GetRhsClosestPoint();
        ASSERT_TRUE(rhsDifference.IsZero());

        result = parallelDistance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistanceLine2Line2Testing ::DerivativeTest()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceLine2Line2<double> distance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult2D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        double derivativeApproximation = 0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult2D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistanceLine2Line2Testing ::IntervalTest()
{
    default_random_engine generator;
    uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceLine2Line2<double> distance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));

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

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }

        DistanceLine2Line2<double> equalDistance(Line2D(lhsOrigin, lhsDirection), Line2D(lhsOrigin + lhsDirection, lhsDirection));

        squaredResult = equalDistance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-9);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), tMin, 1e-10);

        Vector2 lhsDifference = lhsOrigin + tMin * lhsVelocity - squaredResult.GetLhsClosestPoint();
        lhsDifference.Normalize();
        ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                    Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));

        Vector2 rhsDifference = lhsOrigin + lhsDirection + tMin * rhsVelocity - squaredResult.GetRhsClosestPoint();
        ASSERT_TRUE(rhsDifference.IsZero());

        result = equalDistance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), tMin, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}