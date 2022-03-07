// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/30 13:07)

#include "DistanceCircle3Circle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistanceCircle3Circle3Detail.h"
#include "Mathematics/Objects3D/Circle3Detail.h"
#include <random>

using std::swap;

namespace Mathematics
{
    template class DistanceCircle3Circle3<float>;
    template class DistanceCircle3Circle3<double>;
}
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceCircle3Circle3Testing)

void Mathematics::DistanceCircle3Circle3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    // ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    // ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    //   ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    //  ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistanceCircle3Circle3Testing ::BaseTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3F lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        float lhsRadius(MathF::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisF lhsBasis = Vector3ToolsF::GenerateOrthonormalBasis(lhsDirection);

        Vector3F rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3F rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        float rhsRadius(MathF::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisF rhsBasis = Vector3ToolsF::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3F distance(Circle3F(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3F(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(MathF::epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), MathF::epsilon, 1e-8f);

        typedef bool (*ApproximateFunction)(const Circle3F& lhs, const Circle3F& rhs, const float epsilon);
        ApproximateFunction approximate = Approximate<float>;

        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetLhsCircle(), Circle3F(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(approximate, distance.GetRhsCircle(), Circle3F(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius), 1e-8f);
    }
}

void Mathematics::DistanceCircle3Circle3Testing ::StaticTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        double lhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD lhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(lhsDirection);

        Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        double rhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD rhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3D distance(Circle3D(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3D(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));

        DistanceResult3D squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);

        DistanceResult3D result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);

        ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
    }
}

void Mathematics::DistanceCircle3Circle3Testing ::DynamicTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        double lhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD lhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(lhsDirection);

        Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        double rhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD rhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3D distance(Circle3D(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3D(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), Vector3ToolsD::DistanceSquared(squaredResult.GetLhsClosestPoint(), squaredResult.GetRhsClosestPoint()), 1e-8);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);

        DistanceResult3D result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetLhsClosestPoint(), result.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);

        ASSERT_APPROXIMATE(result.GetDistance(), MathD::Sqrt(squaredResult.GetDistance()), 1e-10);
    }
}

void Mathematics::DistanceCircle3Circle3Testing ::DerivativeTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        double lhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD lhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(lhsDirection);

        Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        double rhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD rhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3D distance(Circle3D(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3D(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));

        double t = MathD::FAbs(randomDistribution(generator));
        Vector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        Vector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DistanceResult3D funcPlus = distance.Get(t + distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult3D funcMinus = distance.Get(t - distance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        double derivativeApproximation =
            0.5 / distance.GetDifferenceStep() * (funcPlus.GetDistance() - funcMinus.GetDistance());

        double derivativeResult = distance.GetDerivative(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(derivativeResult, derivativeApproximation, 1e-10);

        double squaredDerivativeResult = distance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult3D distanceResult = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredDerivativeResult, distanceResult.GetDistance() * derivativeApproximation * 2.0, 1e-10);
    }
}

void Mathematics::DistanceCircle3Circle3Testing ::IntervalTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D lhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D lhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsDirection.Normalize();
        double lhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD lhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(lhsDirection);

        Vector3D rhsOrigin(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        Vector3D rhsDirection(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsDirection.Normalize();
        double rhsRadius(MathD::FAbs(randomDistribution(generator)));
        Vector3OrthonormalBasisD rhsBasis = Vector3ToolsD::GenerateOrthonormalBasis(rhsDirection);

        DistanceCircle3Circle3D distance(Circle3D(lhsOrigin, lhsBasis.GetUVector(), lhsBasis.GetVVector(), lhsBasis.GetWVector(), lhsRadius),
                                         Circle3D(rhsOrigin, rhsBasis.GetUVector(), rhsBasis.GetVVector(), rhsBasis.GetWVector(), rhsRadius));
        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

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

            ASSERT_LESS_EQUAL(result.GetDistance(), tResult.GetDistance() + 0.2);
            ASSERT_LESS_EQUAL(squaredResult.GetDistance(), tResultSquared.GetDistance() + 0.3);
        }
    }
}
