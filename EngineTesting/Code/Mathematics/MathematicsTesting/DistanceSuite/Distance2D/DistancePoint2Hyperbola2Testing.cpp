///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:37)

#include "DistancePoint2Hyperbola2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Hyperbola2Detail.h"

#include <random>

namespace Mathematics
{
    template class DistancePoint2Hyperbola2<float>;
    template class DistancePoint2Hyperbola2<double>;
}

Mathematics::DistancePoint2Hyperbola2Testing::DistancePoint2Hyperbola2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistancePoint2Hyperbola2Testing)

void Mathematics::DistancePoint2Hyperbola2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistancePoint2Hyperbola2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistancePoint2Hyperbola2Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F point(randomDistribution(generator), randomDistribution(generator));

        const Vector2F extent(MathF::FAbs(randomDistribution(generator)),
                              MathF::FAbs(randomDistribution(generator)));

        DistancePoint2Hyperbola2F distance(point, extent);

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
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsF::Approximate, distance.GetExtent(), extent, 1e-8f);
    }
}

void Mathematics::DistancePoint2Hyperbola2Testing::StaticTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 extent(MathD::FAbs(randomDistribution(generator)),
                             MathD::FAbs(randomDistribution(generator)));

        DistancePoint2Hyperbola2D distance(point, extent);

        DistanceResult2D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8);

        DistanceResult2D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint2Hyperbola2Testing::DynamicTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 extent(MathD::FAbs(randomDistribution(generator)),
                             MathD::FAbs(randomDistribution(generator)));

        DistancePoint2Hyperbola2D distance(point, extent);

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);

        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint2Hyperbola2Testing::DerivativeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 extent(MathD::FAbs(randomDistribution(generator)),
                             MathD::FAbs(randomDistribution(generator)));

        DistancePoint2Hyperbola2D distance(point, extent);

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult2D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        const double derivativeApproximation = 0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        const double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        const double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult2D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistancePoint2Hyperbola2Testing::IntervalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-10.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 extent(MathD::FAbs(randomDistribution(generator)),
                             MathD::FAbs(randomDistribution(generator)));

        DistancePoint2Hyperbola2D distance(point, extent);
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            std::swap(tMin, tMax);
        }

        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        const Vector2D rhsVelocity;

        DistanceResult2D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-2);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e0);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e0);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e0);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_LESS_EQUAL(result.GetDistance(), tResult.GetDistance() + 1e-3);
            ASSERT_LESS_EQUAL(squaredResult.GetDistance(), tResultSquared.GetDistance() + 1e-3);
        }
    }
}
