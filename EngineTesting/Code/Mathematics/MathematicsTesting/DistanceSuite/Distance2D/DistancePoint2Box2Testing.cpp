///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 11:34)

#include "DistancePoint2Box2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Box2Detail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

#include <random>

using std::default_random_engine;
using std::swap;
using std::uniform_real;

namespace Mathematics
{
    template class DistancePoint2Box2<float>;
    template class DistancePoint2Box2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint2Box2Testing)

void Mathematics::DistancePoint2Box2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistancePoint2Box2Testing::BaseTest()
{
    default_random_engine generator;
    const uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F point(randomDistribution(generator), randomDistribution(generator));

        const Vector2F center(randomDistribution(generator), randomDistribution(generator));
        Vector2F axis0(randomDistribution(generator), randomDistribution(generator));
        const float extent0(MathF::FAbs(randomDistribution(generator)));
        const float extent1(MathF::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector2OrthonormalBasisF basis = Vector2ToolsF::GenerateOrthonormalBasis(axis0);

        DistancePoint2Box2F distance(point, Box2F(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1));

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
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetBox(), Box2F(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1), 1e-8f);
    }
}

void Mathematics::DistancePoint2Box2Testing::StaticTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 center(randomDistribution(generator), randomDistribution(generator));
        Vector2 axis0(randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint2Box2D distance(point, Box2D(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1));

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

void Mathematics::DistancePoint2Box2Testing::DynamicTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));
        const Vector2 center(randomDistribution(generator), randomDistribution(generator));
        Vector2 axis0(randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint2Box2D distance(point, Box2D(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1));

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);

        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint2Box2Testing::DerivativeTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 center(randomDistribution(generator), randomDistribution(generator));
        Vector2 axis0(randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint2Box2D distance(point, Box2D(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1));

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

void Mathematics::DistancePoint2Box2Testing::IntervalTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 point(randomDistribution(generator), randomDistribution(generator));

        const Vector2 center(randomDistribution(generator), randomDistribution(generator));
        Vector2 axis0(randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint2Box2D distance(point, Box2D(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1));

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

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-2);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
