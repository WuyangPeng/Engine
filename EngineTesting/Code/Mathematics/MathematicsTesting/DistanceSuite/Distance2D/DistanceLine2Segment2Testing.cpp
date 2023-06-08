///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 11:28)

#include "DistanceLine2Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Line2Detail.h"
#include "Mathematics/Distance/Distance2D/DistanceLine2Segment2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"
#include <random>
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::default_random_engine;
using std::swap;
using std::uniform_real;

namespace Mathematics
{
    template class DistanceLine2Segment2<float>;
    template class DistanceLine2Segment2<double>;
}

Mathematics::DistanceLine2Segment2Testing::DistanceLine2Segment2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistanceLine2Segment2Testing)

void Mathematics::DistanceLine2Segment2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistanceLine2Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceLine2Segment2Testing::BaseTest()
{
    default_random_engine generator;
    const uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2F rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const float rhsExtent = MathF::FAbs(randomDistribution(generator));

        DistanceLine2Segment2F distance(Line2F(lhsOrigin, lhsDirection), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        using SegmentApproximateFunction = bool (*)(const Segment2F& lhs, const Segment2F& rhs, const float epsilon);
        SegmentApproximateFunction segmentApproximate = Approximate<float>;

        using LineApproximateFunction = bool (*)(const Line2F& lhs, const Line2F& rhs, const float epsilon);
        LineApproximateFunction lineApproximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(lineApproximate, distance.GetLine(), Line2F(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(segmentApproximate, distance.GetSegment(), Segment2F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
    }
}

void Mathematics::DistanceLine2Segment2Testing::StaticTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine2Segment2D distance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult2D squaredResult = distance.GetSquared();
        DistanceResult2D result = distance.Get();

        DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));
        DistanceResult2D lineSquaredResult = lineDistance.GetSquared();

        Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

        const double rhsLength = Vector2ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (rhsLength <= rhsExtent)
        {
            // 最小值为线段内部点。

            Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            const double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (rhsExtent < rhsLength && Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <= Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
        }
        else
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_TRUE(rhsExtent < rhsLength);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <= Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine2Segment2D firstParallelDistance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceLine2Segment2D secondParallelDistance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceLine2Segment2Testing::DynamicTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector2 lhsVelocity(randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector2 rhsVelocity(randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine2Segment2D distance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult2D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DistanceResult2D result = distance.Get(t, lhsVelocity, rhsVelocity);

        DistanceLine2Line2D lineDistance(Line2D(lhsOrigin, lhsDirection), Line2D(rhsOrigin, rhsDirection));
        DistanceResult2D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        Vector2 lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;
        Vector2 rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;

        const double rhsLength = Vector2ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (rhsLength <= rhsExtent)
        {
            // 最小值为线段内部点。

            Vector2 rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
            const double rhsLength2 = Vector2ToolsD::GetLength(rhsDifference2);
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector2ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector2ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector2ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, result.GetLhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (rhsExtent < rhsLength &&
                 Vector2ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint() + t * rhsVelocity, 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
        }
        else
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_TRUE(rhsExtent < rhsLength);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint() + t * rhsVelocity, 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine2Segment2D firstParallelDistance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceLine2Segment2D secondParallelDistance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector2ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector2ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceLine2Segment2Testing::DerivativeTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 lhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 lhsDirection(randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector2 rhsOrigin(randomDistribution(generator), randomDistribution(generator));
        Vector2 rhsDirection(randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine2Segment2D distance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));

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

void Mathematics::DistanceLine2Segment2Testing::IntervalTest()
{
    default_random_engine generator;
    const uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
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

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine2Segment2D distance(Line2D(lhsOrigin, lhsDirection), Segment2D(rhsExtent, rhsOrigin, rhsDirection));
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
