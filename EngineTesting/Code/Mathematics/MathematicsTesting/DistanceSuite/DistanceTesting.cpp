///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 11:00)

#include "DistanceTesting.h"
#include "Detail/DistanceTestDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class DistanceTest<float, Vector2F>;
    template class DistanceTest<double, Vector2D>;
    template class DistanceTest<float, Vector3F>;
    template class DistanceTest<double, Vector3D>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceTesting)

void Mathematics::DistanceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BeginIntervalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EndIntervalTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IterationIntervalTest);
}

void Mathematics::DistanceTesting::BaseTest()
{
    default_random_engine generator;
    const uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DistanceTest<float, Vector2F> distance(Vector2F(randomDistribution(generator), randomDistribution(generator)), Vector2F(randomDistribution(generator), randomDistribution(generator)));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);
    }
}

void Mathematics::DistanceTesting::StaticTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DistanceTest<double, Vector2D> distance(Vector2(randomDistribution(generator), randomDistribution(generator)),
                                                Vector2(randomDistribution(generator), randomDistribution(generator)));

        const double distanceSquared = Vector2ToolsD::DistanceSquared(distance.GetLhs(), distance.GetRhs());

        DistanceResult2D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), distanceSquared, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhs(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhs(), 1e-10);

        DistanceResult2D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(distanceSquared), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), distance.GetLhs(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetRhsClosestPoint(), distance.GetRhs(), 1e-10);
    }
}

void Mathematics::DistanceTesting::DynamicTest()
{
    default_random_engine generator;
    const uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DistanceTest<float, Vector3F> distance(Vector3F(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)),
                                               Vector3F(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)));

        const float t = MathF::FAbs(randomDistribution(generator));
        Vector3F lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3F rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        const double distanceSquared = Vector3ToolsD::DistanceSquared(distance.GetLhs() + lhsVelocity * t, distance.GetRhs() + rhsVelocity * t);

        DistanceResult3F squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), distanceSquared, 1e-4f);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhs() + lhsVelocity * t, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhs() + rhsVelocity * t, 1e-8f);

        DistanceResult3F result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(distanceSquared), 1e-5f);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), distance.GetLhs() + lhsVelocity * t, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), distance.GetRhs() + rhsVelocity * t, 1e-8f);
    }
}

void Mathematics::DistanceTesting::DerivativeTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceTest<double, Vector3D> distance(Vector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)),
                                                Vector3D(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator)));

        DistanceResult3D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult3D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        const double derivativeApproximation = 0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        const double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        const double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult3D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistanceTesting::IntervalTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DistanceTest<double, Vector2D> distance(Vector2(randomDistribution(generator), randomDistribution(generator)),
                                                Vector2(randomDistribution(generator), randomDistribution(generator)));
        distance.SetMaximumIterations(10);

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

        DistanceResult2D resultSquared = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-4);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_LESS_EQUAL(result.GetDistance(), tResult.GetDistance() + 0.0001);
            ASSERT_LESS_EQUAL(resultSquared.GetDistance(), tResultSquared.GetDistance());
        }
    }
}

void Mathematics::DistanceTesting::BeginIntervalTest()
{
    // 测试距离为有效值零。对象是在最初位置接触。
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DistanceTest<double, Vector3D> distance(point, point);

        constexpr double tMin = 0.0;
        const double tMax = MathD::FAbs(randomDistribution(generator));

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D resultSquared = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(MathD::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(0.0, result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}

void Mathematics::DistanceTesting::EndIntervalTest()
{
    // 测试距离为有效值零。对象是在最终位置接触。
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DistanceTest<double, Vector3D> distance(point - tMax * lhsVelocity, point - tMax * rhsVelocity);

        DistanceResult3D resultSquared = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(MathD::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(tMax, result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}

void Mathematics::DistanceTesting::IterationIntervalTest()
{
    // 测试牛顿法过程中返回的情况
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        constexpr double tMin = 0.0;
        const double tMax = MathD::FAbs(randomDistribution(generator));

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DistanceTest<double, Vector3D> distance(point - tMax / 2.0 * lhsVelocity, point - tMax / 2.0 * rhsVelocity);
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        DistanceResult3D resultSquared = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(0.0, result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(MathD::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(tMax / 2.0, result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), point, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-2);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}