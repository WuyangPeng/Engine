///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:44)

#include "DistancePoint3Box3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Box3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"

#include <random>

namespace Mathematics
{
    template class DistancePoint3Box3<float>;
    template class DistancePoint3Box3<double>;
}

Mathematics::DistancePoint3Box3Testing::DistancePoint3Box3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistancePoint3Box3Testing)

void Mathematics::DistancePoint3Box3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistancePoint3Box3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistancePoint3Box3Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3F point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        const Vector3F center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const float extent0(MathF::FAbs(randomDistribution(generator)));
        const float extent1(MathF::FAbs(randomDistribution(generator)));
        const float extent2(MathF::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector3OrthonormalBasisF basis = Vector3ToolsF::GenerateOrthonormalBasis(axis0);

        DistancePoint3Box3F distance(point, Box3F(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, distance.GetPoint(), point, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetBox(), Box3F(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2), 1e-8f);
    }
}

void Mathematics::DistancePoint3Box3Testing::StaticTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        const Vector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));
        const double extent2(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint3Box3D distance(point, Box3D(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        DistanceResult3D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8);

        DistanceResult3D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint3Box3Testing::DynamicTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const Vector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));
        const double extent2(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint3Box3D distance(point, Box3D(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        const double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::GetLengthSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);

        DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::GetLength(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint3Box3Testing::DerivativeTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        const Vector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));
        const double extent2(MathD::FAbs(randomDistribution(generator)));
        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint3Box3D distance(point, Box3D(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

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

void Mathematics::DistancePoint3Box3Testing::IntervalTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        const Vector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        const double extent0(MathD::FAbs(randomDistribution(generator)));
        const double extent1(MathD::FAbs(randomDistribution(generator)));
        const double extent2(MathD::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);

        DistancePoint3Box3D distance(point, Box3D(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        double tMin = MathD::FAbs(randomDistribution(generator));
        double tMax = MathD::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            std::swap(tMin, tMax);
        }

        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-2);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
