// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.0.2 (2019/08/30 13:10)

#include "DistanceRay3Ray3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Ray3Detail.h"

#include <random>

using std::swap;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceRay3Ray3Testing)

void Mathematics::DistanceRay3Ray3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceRay3Ray3Testing ::BaseTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        FloatVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        FloatVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        FloatVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        FloatDistanceRay3Ray3 distance(FloatRay3(lhsOrigin, lhsDirection), FloatRay3(rhsOrigin, rhsDirection));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(FloatMath::sm_Epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

        typedef bool (*ApproximateFunction)(const FloatRay3& lhs, const FloatRay3& rhs, const float epsilon);

        ApproximateFunction approximate = Approximate<float>;
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsRay(), FloatRay3(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsRay(), FloatRay3(rhsOrigin, rhsDirection), 1e-8f);
    }
}

void Mathematics::DistanceRay3Ray3Testing ::StaticTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DoubleDistanceRay3Ray3 distance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, rhsDirection));

        DoubleDistanceResult3 squaredResult = distance.GetSquared();
        DoubleDistanceResult3 result = distance.Get();

        DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin, rhsDirection));
        DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared();

        DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        lhsDifference.Normalize();
        DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;
        rhsDifference.Normalize();

        if (DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最小值为两个射线内部点。
            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            lhsDifference2.Normalize();
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            rhsDifference2.Normalize();

            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, lhsDifference2, lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference2, rhsDirection, 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            ASSERT_TRUE(rhsDifference2.IsZero());

            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            if (lhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(lhsOrigin - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin + distance.GetZeroThreshold() * lhsDirection - rhsOrigin));
            }
            else
            {
                // 最小值为第二个射线的原点到第一个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));
            }
        }
        else if (DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-8) &&
                 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            ASSERT_TRUE(lhsDifference2.IsZero());

            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            if (rhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(lhsOrigin - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin + distance.GetZeroThreshold() * rhsDirection - lhsOrigin));
            }
            else
            {
                // 最小值为第一个射线的原点到第二个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - lhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - lhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - lhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - lhsOrigin));
            }
        }
        else
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, lhsDifference, -lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - rhsOrigin));
            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - lhsOrigin) + 1e-8);
            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin) + 1e-8);

            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            if (!lhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));
            }
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            if (!rhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - lhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - lhsOrigin));
            }
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DoubleDistanceRay3Ray3 firstEqualDistance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(lhsOrigin + lhsDirection, lhsDirection));

        squaredResult = firstEqualDistance.GetSquared();
        result = firstEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

        DoubleDistanceRay3Ray3 secondEqualDistance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(lhsOrigin + lhsDirection, -lhsDirection));

        squaredResult = firstEqualDistance.GetSquared();
        result = firstEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

        DoubleDistanceRay3Ray3 thirdEqualDistance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(lhsOrigin - lhsDirection, -lhsDirection));

        squaredResult = thirdEqualDistance.GetSquared();
        result = thirdEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(lhsDirection), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin - lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(lhsDirection), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), lhsOrigin - lhsDirection, 1e-8);

        DoubleDistanceRay3Ray3 firstParallelDistance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();
        double lhsDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - squaredResult.GetRhsClosestPoint());
        double rhsDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());

        if (lhsDistanceSquared < rhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), lhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(lhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(rhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }

        DoubleDistanceRay3Ray3 secondParallelDistance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();
        lhsDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin - squaredResult.GetRhsClosestPoint());
        rhsDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());
        double originDistanceSquared = DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin - lhsOrigin);

        if (originDistanceSquared <= rhsDistanceSquared && originDistanceSquared <= lhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), originDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(originDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }
        else if (lhsDistanceSquared <= originDistanceSquared && lhsDistanceSquared <= rhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), lhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(lhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleMath::Sqrt(rhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }
    }
}

void Mathematics::DistanceRay3Ray3Testing ::DynamicTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DoubleDistanceRay3Ray3 distance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, rhsDirection));

        double t = DoubleMath::FAbs(randomDistribution(generator));
        DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DoubleDistanceResult3 squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DoubleDistanceResult3 result = distance.Get(t, lhsVelocity, rhsVelocity);

        DoubleDistanceLine3Line3 lineDistance(DoubleLine3(lhsOrigin, lhsDirection), DoubleLine3(rhsOrigin, rhsDirection));
        DoubleDistanceResult3 lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        DoubleVector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
        lhsDifference.Normalize();
        DoubleVector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
        rhsDifference.Normalize();

        if (DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最小值为两个射线内部点。
            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            lhsDifference2.Normalize();
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            rhsDifference2.Normalize();

            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, lhsDifference2, lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference2, rhsDirection, 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (DoubleVector3DTools::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 DoubleVector3DTools::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            ASSERT_TRUE(rhsDifference2.IsZero());

            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            if (lhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin + t * rhsVelocity - (lhsOrigin + t * lhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(rhsOrigin + t * rhsVelocity - (lhsOrigin + t * lhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin + t * lhsVelocity + distance.GetZeroThreshold() * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
            else
            {
                // 最小值为第二个射线的原点到第一个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), (rhsOrigin + t * rhsVelocity), 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
        }
        else if (DoubleVector3DTools::Approximate(lhsDifference, -lhsDirection, 1e-8) &&
                 DoubleVector3DTools::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            ASSERT_TRUE(lhsDifference2.IsZero());

            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            if (rhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared((lhsOrigin + t * lhsVelocity) - (rhsOrigin + t * rhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude((lhsOrigin + t * lhsVelocity) - (rhsOrigin + t * rhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(rhsOrigin + t * rhsVelocity + distance.GetZeroThreshold() * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
            else
            {
                // 最小值为第一个射线的原点到第二个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
        }
        else
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, lhsDifference, -lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)) + 1e-8);
            ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)) + 1e-8);

            DoubleVector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            if (!lhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
            DoubleVector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            if (!rhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= DoubleVector3DTools::VectorMagnitudeSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistanceRay3Ray3Testing ::DerivativeTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DoubleDistanceRay3Ray3 distance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, rhsDirection));

        double t = DoubleMath::FAbs(randomDistribution(generator));
        DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DoubleDistanceResult3 funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DoubleDistanceResult3 funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        double derivativeApproximation =
            0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DoubleDistanceResult3 distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistanceRay3Ray3Testing ::IntervalTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        DoubleVector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double tMin = DoubleMath::FAbs(randomDistribution(generator));
        double tMax = DoubleMath::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        DoubleDistanceRay3Ray3 distance(DoubleRay3(lhsOrigin, lhsDirection), DoubleRay3(rhsOrigin, rhsDirection));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DoubleDistanceResult3 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DoubleDistanceResult3 result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-3);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-3);
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
