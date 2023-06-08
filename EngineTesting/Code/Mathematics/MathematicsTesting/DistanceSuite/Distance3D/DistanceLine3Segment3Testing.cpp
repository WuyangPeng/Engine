///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 16:51)

#include "DistanceLine3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Segment3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"
#include <random>
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::swap;

namespace Mathematics
{
    template class DistanceLine3Segment3<float>;
    template class DistanceLine3Segment3<double>;
}

Mathematics::DistanceLine3Segment3Testing::DistanceLine3Segment3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistanceLine3Segment3Testing)

void Mathematics::DistanceLine3Segment3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistanceLine3Segment3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceLine3Segment3Testing::BaseTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3F lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3F rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const float rhsExtent = MathF::FAbs(randomDistribution(generator));

        DistanceLine3Segment3F distance(Line3F(lhsOrigin, lhsDirection), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        typedef bool (*SegmentApproximateFunction)(const Segment3F& lhs, const Segment3F& rhs, const float epsilon);
        SegmentApproximateFunction segmentApproximate = Approximate<float>;

        typedef bool (*LineApproximateFunction)(const Line3F& lhs, const Line3F& rhs, const float epsilon);
        LineApproximateFunction lineApproximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(lineApproximate, distance.GetLine(), Line3F(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(segmentApproximate, distance.GetSegment(), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
    }
}

void Mathematics::DistanceLine3Segment3Testing::StaticTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine3Segment3D distance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult3D squaredResult = distance.GetSquared();
        DistanceResult3D result = distance.Get();

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared();

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

        const double rhsLength = Vector3ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (rhsLength <= rhsExtent)
        {
            // 最小值为线段内部点。

            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            const double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        }
        else if (rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()));
        }
        else
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_TRUE(rhsExtent < rhsLength);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint(), 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()));
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine3Segment3D firstParallelDistance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceLine3Segment3D secondParallelDistance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceLine3Segment3Testing::DynamicTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine3Segment3D distance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult3D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;

        const double rhsLength = Vector3ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (rhsLength <= rhsExtent)
        {
            // 最小值为线段内部点。

            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
            const double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-10));
            ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        }
        else if (rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在lhs上某个点和rhs终点
            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetEndPoint() + t * rhsVelocity, 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity));
        }
        else
        {
            // 最近点在lhs上某个点和rhs起始点
            ASSERT_TRUE(rhsExtent < rhsLength);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), distance.GetSegment().GetBeginPoint() + t * rhsVelocity, 1e-8);

            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
            ASSERT_TRUE(squaredResult.GetDistance() <=
                        Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity));
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceLine3Segment3D firstParallelDistance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceLine3Segment3D secondParallelDistance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetLine().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceLine3Segment3Testing::DerivativeTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine3Segment3D distance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

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

void Mathematics::DistanceLine3Segment3Testing::IntervalTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceLine3Segment3D distance(Line3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-5);
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
