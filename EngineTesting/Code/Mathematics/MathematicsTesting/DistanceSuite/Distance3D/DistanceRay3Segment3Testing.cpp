///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:46)

#include "DistanceRay3Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Segment3Detail.h"

#include <random>

namespace Mathematics
{
    template class DistanceRay3Segment3<float>;
    template class DistanceRay3Segment3<double>;
}

Mathematics::DistanceRay3Segment3Testing::DistanceRay3Segment3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistanceRay3Segment3Testing)

void Mathematics::DistanceRay3Segment3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistanceRay3Segment3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceRay3Segment3Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

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

        DistanceRay3Segment3F distance(Ray3F(lhsOrigin, lhsDirection), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f));

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

        typedef bool (*RayApproximateFunction)(const Ray3F& lhs, const Ray3F& rhs, const float epsilon);
        RayApproximateFunction rayApproximateFunction = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(rayApproximateFunction, distance.GetRay(), Ray3F(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(segmentApproximate, distance.GetSegment(), Segment3F(rhsExtent, rhsOrigin, rhsDirection, 1e-5f), 1e-8f);
    }
}

void Mathematics::DistanceRay3Segment3Testing::StaticTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

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

        DistanceRay3Segment3D distance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult3D squaredResult = distance.GetSquared();
        DistanceResult3D result = distance.Get();

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared();

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;

        const double rhsLength = Vector3ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            rhsLength <= rhsExtent)
        {
            // 最小值为线段和射线内部点。
            Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            const double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
            lhsDifference2.Normalize();
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10));
            ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在射线上某个点和rhs终点
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
                            Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint()) ||
                        Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin(), 1e-8));
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            // 最近点在射线上某个点和rhs起始点
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
                            Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint()) ||
                        Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin(), 1e-8));
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), squaredResult.GetDistance(), 1e-10);

            const double distanceSquared = squaredResult.GetDistance();
            double testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - distance.GetSegment().GetBeginPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - distance.GetSegment().GetEndPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceRay3Segment3D firstParallelDistance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceRay3Segment3D secondParallelDistance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceRay3Segment3Testing::DynamicTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

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

        DistanceRay3Segment3D distance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

        DistanceResult3D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;

        const double rhsLength = Vector3ToolsD::GetLength(rhsDifference);
        lhsDifference.Normalize();
        rhsDifference.Normalize();

        if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            rhsLength <= rhsExtent)
        {
            // 最小值为线段和射线内部点。
            Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin - t * lhsVelocity;
            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin - t * rhsVelocity;
            const double rhsLength2 = Vector3ToolsD::GetLength(rhsDifference2);
            lhsDifference2.Normalize();
            rhsDifference2.Normalize();

            ASSERT_TRUE(rhsLength2 <= rhsExtent);

            ASSERT_TRUE(Vector3ToolsD::Approximate(lhsDifference2, lhsDirection, 1e-10));
            ASSERT_TRUE(Vector3ToolsD::Approximate(rhsDifference2, rhsDirection, 1e-10) ||
                        Vector3ToolsD::Approximate(rhsDifference2, -rhsDirection, 1e-10));
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最近点在射线上某个点和rhs终点
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
                            Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetEndPoint() - t * rhsVelocity) ||
                        Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin() + t * lhsVelocity, 1e-8));
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) && rhsExtent < rhsLength &&
                 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            // 最近点在射线上某个点和rhs起始点
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
                            Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.01 * lhsDirection - distance.GetSegment().GetBeginPoint() - t * rhsVelocity) ||
                        Vector3ToolsD::Approximate(squaredResult.GetLhsClosestPoint(), distance.GetRay().GetOrigin() + t * lhsVelocity, 1e-8));
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), squaredResult.GetDistance(), 1e-10);

            const double distanceSquared = squaredResult.GetDistance();
            double testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - distance.GetSegment().GetBeginPoint() - t * rhsVelocity);
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - distance.GetSegment().GetEndPoint() - t * rhsVelocity);
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(distance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetBeginPoint() - t * rhsVelocity);
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - distance.GetSegment().GetEndPoint() - t * rhsVelocity);
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

            testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
            ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceRay3Segment3D firstParallelDistance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = firstParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        double distanceSquared = squaredResult.GetDistance();
        double testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(firstParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - firstParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        DistanceRay3Segment3D secondParallelDistance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared(t, lhsVelocity, rhsVelocity);
        result = secondParallelDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(result.GetRhsClosestPoint() - result.GetLhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        distanceSquared = squaredResult.GetDistance();
        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(secondParallelDistance.GetRay().GetOrigin() + t * lhsVelocity - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetBeginPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - secondParallelDistance.GetSegment().GetEndPoint() - t * rhsVelocity);
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);

        testDistanceSquared = Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - squaredResult.GetRhsClosestPoint());
        ASSERT_TRUE(distanceSquared <= testDistanceSquared + 1e-10);
    }
}

void Mathematics::DistanceRay3Segment3Testing::DerivativeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

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

        DistanceRay3Segment3D distance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));

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

void Mathematics::DistanceRay3Segment3Testing::IntervalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-10.0, 10.0);

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
            std::swap(tMin, tMax);
        }

        const double rhsExtent = MathD::FAbs(randomDistribution(generator));

        DistanceRay3Segment3D distance(Ray3D(lhsOrigin, lhsDirection), Segment3D(rhsExtent, rhsOrigin, rhsDirection));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-4);
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
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance() + 1e-5);
        }
    }
}
