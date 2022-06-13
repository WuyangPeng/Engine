///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 15:38)

#include "DistanceSegment2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Distance/Distance2D/DistanceSegment2Segment2Detail.h"

#include <random>

using std::swap;

namespace Mathematics
{
    template class DistanceSegment2Segment2<float>;
    template class DistanceSegment2Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceSegment2Segment2Testing)

void Mathematics::DistanceSegment2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceSegment2Segment2Testing::BaseTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2F lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2F rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const float lhsExtent = MathF::FAbs(randomDistribution(generator));
        const float rhsExtent = MathF::FAbs(randomDistribution(generator));

        DistanceSegment2Segment2F distance(Segment2F(lhsExtent, lhsOrigin, lhsDirection, 1e-5f), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        typedef bool (*ApproximateFunction)(const Segment2F& lhs, const Segment2F& rhs, const float epsilon);

        ApproximateFunction approximate = Approximate<float>;
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsSegment(), Segment2F(lhsExtent, lhsOrigin, lhsDirection, 1e-5f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsSegment(), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
    }
}

void Mathematics::DistanceSegment2Segment2Testing::StaticTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double lhsExtent = MathD::FAbs(randomDistribution(generator));
        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceSegment2Segment2D distance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult2D squaredResult = distance.GetSquared();
        DistanceResult2D result = distance.Get();

        DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));
        DistanceResult2D lineSquaredResult = lineDistance.GetSquared();

        Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

        const double lhsLength = Vector2ToolsD::GetLength(lhsDifference);
        const double rhsLength = Vector2ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
        {
            // 最小值为两个线段内部点。
            Vector2 lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            const double lhsLength2 = Vector2ToolsD::GetLength(lhsDifference2);
            const double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
            lhsDifference2.Normalize();
            rhsDifference2.Normalize();

            ASSERT_TRUE(lhsLength2 <= lhsExtent);
            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(lhsDifference2, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
                 Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetEndPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
        }
        else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
                 Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetRhsSegment().GetBeginPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8));
        }
        else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
                 Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8))
        {
            // 最近点在rhs上某个点和lhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetEndPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
        }
        else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
                 Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8))
        {
            // 最近点在rhs上某个点和lhs起点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetBeginPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint(), 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - distance.GetLhsSegment().GetBeginPoint()) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint(), 1e-8));
        }
        else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
        {
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), squaredResult.GetDistance(), 1e-10);

            const double distanceSquared = squaredResult.GetDistance();
            double testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetBeginPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - distance.GetRhsSegment().GetEndPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetBeginPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - distance.GetRhsSegment().GetEndPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetBeginPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetRhsSegment().GetEndPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceSegment2Segment2D firstParallelDistance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceSegment2Segment2D secondParallelDistance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceSegment2Segment2Testing::DynamicTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double lhsExtent = MathD::FAbs(randomDistribution(generator));
        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceSegment2Segment2D distance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);

        DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));
        DistanceResult2D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
        Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);

        const double lhsLength = Vector2ToolsD::GetLength(lhsDifference);
        const double rhsLength = Vector2ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (lhsLength <= lhsExtent && rhsLength <= rhsExtent)
        {
            // 最小值为两个线段内部点。
            Vector2 lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            const double lhsLength2 = Vector2ToolsD::GetLength(lhsDifference2);
            const double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
            lhsDifference2.Normalize();
            rhsDifference2.Normalize();

            ASSERT_TRUE(lhsLength2 <= lhsExtent);
            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(lhsDifference2, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
                 Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
        }
        else if (lhsLength <= lhsExtent && rhsExtent < rhsLength &&
                 Vector2ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + +t * rhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity, 1e-8));
        }
        else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
                 Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8))
        {
            // 最近点在rhs上某个点和lhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - distance.GetLhsSegment().GetEndPoint() - t * lhsVelocity),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity, 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
        }
        else if (rhsLength <= rhsExtent && lhsExtent < lhsLength &&
                 Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8))
        {
            // 最近点在rhs上某个点和lhs起点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity, 1e-8));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                            Vector2ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.01 * rhsDirection - (distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity)) ||
                        Vector2ToolsD::Approximate(squaredResult.GetRhsClosestPoint(), distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity, 1e-8));
        }
        else if (rhsExtent < rhsLength && lhsExtent < lhsLength)
        {
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), squaredResult.GetDistance(), 1e-10);

            const double distanceSquared = squaredResult.GetDistance();
            double testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(distance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetBeginPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (distance.GetRhsSegment().GetEndPoint() + t * rhsVelocity));
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceSegment2Segment2D firstParallelDistance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceSegment2Segment2D secondParallelDistance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetBeginPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLhsSegment().GetEndPoint() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetRhsSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceSegment2Segment2Testing::DerivativeTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        const double lhsExtent = MathD::FAbs(randomDistribution(generator));
        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceSegment2Segment2D distance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

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

void Mathematics::DistanceSegment2Segment2Testing::IntervalTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        const double lhsExtent = MathD::FAbs(randomDistribution(generator));
        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceSegment2Segment2D distance(Segment2D(lhsExtent, lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult2D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult2D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult2D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
