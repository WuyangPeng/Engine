///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:46)

#include "DistanceRay3Ray3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Line3Detail.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Ray3Detail.h"

#include <random>

Mathematics::DistanceRay3Ray3Testing::DistanceRay3Ray3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistanceRay3Ray3Testing)

void Mathematics::DistanceRay3Ray3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistanceRay3Ray3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceRay3Ray3Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3F lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3F rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceRay3Ray3F distance(Ray3F(lhsOrigin, lhsDirection), Ray3F(rhsOrigin, rhsDirection));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        typedef bool (*ApproximateFunction)(const Ray3F& lhs, const Ray3F& rhs, const float epsilon);

        ApproximateFunction approximate = Approximate<float>;
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsRay(), Ray3F(lhsOrigin, lhsDirection), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsRay(), Ray3F(rhsOrigin, rhsDirection), 1e-8f);
    }
}

void Mathematics::DistanceRay3Ray3Testing::StaticTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceRay3Ray3D distance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));

        DistanceResult3D squaredResult = distance.GetSquared();
        DistanceResult3D result = distance.Get();

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared();

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - lhsOrigin;
        lhsDifference.Normalize();
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - rhsOrigin;
        rhsDifference.Normalize();

        if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最小值为两个射线内部点。
            Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            lhsDifference2.Normalize();
            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            rhsDifference2.Normalize();

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, lhsDifference2, lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference2, rhsDirection, 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            ASSERT_TRUE(rhsDifference2.IsZero());

            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            if (lhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(lhsOrigin - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + distance.GetZeroThreshold() * lhsDirection - rhsOrigin));
            }
            else
            {
                // 最小值为第二个射线的原点到第一个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));
            }
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8) &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            ASSERT_TRUE(lhsDifference2.IsZero());

            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            if (rhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(lhsOrigin - rhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(rhsOrigin + distance.GetZeroThreshold() * rhsDirection - lhsOrigin));
            }
            else
            {
                // 最小值为第一个射线的原点到第二个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - lhsOrigin),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - lhsOrigin), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - lhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - lhsOrigin));
            }
        }
        else
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, lhsDifference, -lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin - rhsOrigin));
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - lhsOrigin) + 1e-8);
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - rhsOrigin) + 1e-8);

            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - lhsOrigin;
            if (!lhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - rhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - rhsOrigin));
            }
            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - rhsOrigin;
            if (!rhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - lhsOrigin));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - lhsOrigin));
            }
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);

        DistanceRay3Ray3D firstEqualDistance(Ray3D(lhsOrigin, lhsDirection), Ray3D(lhsOrigin + lhsDirection, lhsDirection));

        squaredResult = firstEqualDistance.GetSquared();
        result = firstEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

        DistanceRay3Ray3D secondEqualDistance(Ray3D(lhsOrigin, lhsDirection), Ray3D(lhsOrigin + lhsDirection, -lhsDirection));

        squaredResult = firstEqualDistance.GetSquared();
        result = firstEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), 0.0, 1e-7);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), lhsOrigin + lhsDirection, 1e-8);

        DistanceRay3Ray3D thirdEqualDistance(Ray3D(lhsOrigin, lhsDirection), Ray3D(lhsOrigin - lhsDirection, -lhsDirection));

        squaredResult = thirdEqualDistance.GetSquared();
        result = thirdEqualDistance.Get();

        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(lhsDirection), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), lhsOrigin - lhsDirection, 1e-8);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(lhsDirection), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), lhsOrigin - lhsDirection, 1e-8);

        DistanceRay3Ray3D firstParallelDistance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, lhsDirection));

        squaredResult = firstParallelDistance.GetSquared();
        result = firstParallelDistance.Get();
        double lhsDistanceSquared = Vector3ToolsD::GetLengthSquared(lhsOrigin - squaredResult.GetRhsClosestPoint());
        double rhsDistanceSquared = Vector3ToolsD::GetLengthSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());

        if (lhsDistanceSquared < rhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), lhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(lhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(rhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }

        DistanceRay3Ray3D secondParallelDistance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, -lhsDirection));

        squaredResult = secondParallelDistance.GetSquared();
        result = secondParallelDistance.Get();
        lhsDistanceSquared = Vector3ToolsD::GetLengthSquared(lhsOrigin - squaredResult.GetRhsClosestPoint());
        rhsDistanceSquared = Vector3ToolsD::GetLengthSquared(rhsOrigin - squaredResult.GetLhsClosestPoint());
        const double originDistanceSquared = Vector3ToolsD::GetLengthSquared(rhsOrigin - lhsOrigin);

        if (originDistanceSquared <= rhsDistanceSquared && originDistanceSquared <= lhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), originDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(originDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }
        else if (lhsDistanceSquared <= originDistanceSquared && lhsDistanceSquared <= rhsDistanceSquared)
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), lhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(lhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin, 1e-8);
        }
        else
        {
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), rhsDistanceSquared, 1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin, 1e-8);
            ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(rhsDistanceSquared), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), rhsOrigin, 1e-8);
        }
    }
}

void Mathematics::DistanceRay3Ray3Testing::DynamicTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceRay3Ray3D distance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);

        DistanceLine3Line3D lineDistance(Line3D(lhsOrigin, lhsDirection), Line3D(rhsOrigin, rhsDirection));
        DistanceResult3D lineSquaredResult = lineDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        Vector3D lhsDifference = lineSquaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
        lhsDifference.Normalize();
        Vector3D rhsDifference = lineSquaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
        rhsDifference.Normalize();

        if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
            Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            // 最小值为两个射线内部点。
            Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            lhsDifference2.Normalize();
            Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            rhsDifference2.Normalize();

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, lhsDifference2, lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference2, rhsDirection, 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetRhsClosestPoint(), squaredResult.GetRhsClosestPoint(), 1e-8);
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, lhsDirection, 1e-8) &&
                 Vector3ToolsD::Approximate(rhsDifference, -rhsDirection, 1e-8))
        {
            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            ASSERT_TRUE(rhsDifference2.IsZero());

            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            if (lhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(rhsOrigin + t * rhsVelocity - (lhsOrigin + t * lhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(rhsOrigin + t * rhsVelocity - (lhsOrigin + t * lhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + t * lhsVelocity + distance.GetZeroThreshold() * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
            else
            {
                // 最小值为第二个射线的原点到第一个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), (rhsOrigin + t * rhsVelocity), 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
        }
        else if (Vector3ToolsD::Approximate(lhsDifference, -lhsDirection, 1e-8) &&
                 Vector3ToolsD::Approximate(rhsDifference, rhsDirection, 1e-8))
        {
            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            ASSERT_TRUE(lhsDifference2.IsZero());

            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            if (rhsDifference2.IsZero())
            {
                // 最小值为两个射线的原点距离。
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared((lhsOrigin + t * lhsVelocity) - (rhsOrigin + t * rhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength((lhsOrigin + t * lhsVelocity) - (rhsOrigin + t * rhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), rhsOrigin + t * rhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(rhsOrigin + t * rhsVelocity + distance.GetZeroThreshold() * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
            else
            {
                // 最小值为第一个射线的原点到第二个射线
                ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                                   Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)),
                                   1e-10);
                ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)), 1e-10);
                ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
                ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), lhsOrigin + t * lhsVelocity, 1e-8);

                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
        }
        else
        {
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, lhsDifference, -lhsDirection, 1e-8);
            ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, rhsDifference, -rhsDirection, 1e-8);

            ASSERT_APPROXIMATE(squaredResult.GetDistance(),
                               Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()),
                               1e-10);
            ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
            ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(squaredResult.GetRhsClosestPoint() - squaredResult.GetLhsClosestPoint()), 1e-10);
            ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(lhsOrigin + t * lhsVelocity - (rhsOrigin + t * rhsVelocity)));
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - (lhsOrigin + t * lhsVelocity)) + 1e-8);
            ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - (rhsOrigin + t * rhsVelocity)) + 1e-8);

            const Vector3D lhsDifference2 = squaredResult.GetLhsClosestPoint() - (lhsOrigin + t * lhsVelocity);
            if (!lhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() + 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetLhsClosestPoint() - 0.1 * lhsDirection - (rhsOrigin + t * rhsVelocity)));
            }
            const Vector3D rhsDifference2 = squaredResult.GetRhsClosestPoint() - (rhsOrigin + t * rhsVelocity);
            if (!rhsDifference2.IsZero())
            {
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() + 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
                ASSERT_TRUE(squaredResult.GetDistance() <= Vector3ToolsD::GetLengthSquared(squaredResult.GetRhsClosestPoint() - 0.1 * rhsDirection - (lhsOrigin + t * lhsVelocity)));
            }
        }

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistanceRay3Ray3Testing::DerivativeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();

        const Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();

        DistanceRay3Ray3D distance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));

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

void Mathematics::DistanceRay3Ray3Testing::IntervalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution(-10.0, 10.0);

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

        DistanceRay3Ray3D distance(Ray3D(lhsOrigin, lhsDirection), Ray3D(rhsOrigin, rhsDirection));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-3);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance() + 1e-3);
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
