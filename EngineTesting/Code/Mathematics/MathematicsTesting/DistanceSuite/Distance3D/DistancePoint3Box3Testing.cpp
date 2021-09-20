// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 13:09)

#include "DistancePoint3Box3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Box3Detail.h"
#include "Mathematics/Objects3D/Box3Detail.h"
#include <random>

using std::swap;

namespace Mathematics
{
    template class DistancePoint3Box3<float>;
    template class DistancePoint3Box3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint3Box3Testing)

void Mathematics::DistancePoint3Box3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalTest);
}

void Mathematics::DistancePoint3Box3Testing ::BaseTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        FloatVector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        FloatVector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        float extent0(FloatMath::FAbs(randomDistribution(generator)));
        float extent1(FloatMath::FAbs(randomDistribution(generator)));
        float extent2(FloatMath::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        FloatVector3DOrthonormalBasis basis = FloatVector3DTools::GenerateOrthonormalBasis(axis0);

        FloatDistancePoint3Box3 distance(point, FloatBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-3f, 1e-8f);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 8);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::GetZeroTolerance(), 1e-8f);

        distance.SetDifferenceStep(1e-4f);
        ASSERT_APPROXIMATE(distance.GetDifferenceStep(), 1e-4f, 1e-8f);

        distance.SetMaximumIterations(10);
        ASSERT_EQUAL(distance.GetMaximumIterations(), 10);

        distance.SetZeroThreshold(FloatMath::sm_Epsilon);
        ASSERT_APPROXIMATE(distance.GetZeroThreshold(), FloatMath::sm_Epsilon, 1e-8f);

        ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distance.GetPoint(), point, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, distance.GetBox(), FloatBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2), 1e-8f);
    }
}

void Mathematics::DistancePoint3Box3Testing ::StaticTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DoubleVector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        double extent0(DoubleMath::FAbs(randomDistribution(generator)));
        double extent1(DoubleMath::FAbs(randomDistribution(generator)));
        double extent2(DoubleMath::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        DoubleVector3DOrthonormalBasis basis = DoubleVector3DTools::GenerateOrthonormalBasis(axis0);

        DoubleDistancePoint3Box3 distance(point, DoubleBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        DoubleDistanceResult3 squaredResult = distance.GetSquared();
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), point, 1e-8);

        DoubleDistanceResult3 result = distance.Get();
        ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(point - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint3Box3Testing ::DynamicTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        double extent0(DoubleMath::FAbs(randomDistribution(generator)));
        double extent1(DoubleMath::FAbs(randomDistribution(generator)));
        double extent2(DoubleMath::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        DoubleVector3DOrthonormalBasis basis = DoubleVector3DTools::GenerateOrthonormalBasis(axis0);

        DoubleDistancePoint3Box3 distance(point, DoubleBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        double t = DoubleMath::FAbs(randomDistribution(generator));
        DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DoubleDistanceResult3 squaredResult = distance.GetSquared(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(squaredResult.GetDistance(), DoubleVector3DTools::VectorMagnitudeSquared(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-7);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(), point + t * lhsVelocity, 1e-8);

        DoubleDistanceResult3 result = distance.Get(t, lhsVelocity, rhsVelocity);
        ASSERT_APPROXIMATE(result.GetDistance(), DoubleVector3DTools::VectorMagnitude(point + t * lhsVelocity - squaredResult.GetRhsClosestPoint()), 1e-10);
        ASSERT_APPROXIMATE(result.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, result.GetLhsClosestPoint(), squaredResult.GetLhsClosestPoint(), 1e-8);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(), result.GetRhsClosestPoint(), 1e-8);
    }
}

void Mathematics::DistancePoint3Box3Testing ::DerivativeTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DoubleVector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        double extent0(DoubleMath::FAbs(randomDistribution(generator)));
        double extent1(DoubleMath::FAbs(randomDistribution(generator)));
        double extent2(DoubleMath::FAbs(randomDistribution(generator)));
        axis0.Normalize();

        DoubleVector3DOrthonormalBasis basis = DoubleVector3DTools::GenerateOrthonormalBasis(axis0);

        DoubleDistancePoint3Box3 distance(point, DoubleBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

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

void Mathematics::DistancePoint3Box3Testing ::IntervalTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-10.0, 10.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector3D point(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        DoubleVector3D center(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        DoubleVector3D axis0(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        double extent0(DoubleMath::FAbs(randomDistribution(generator)));
        double extent1(DoubleMath::FAbs(randomDistribution(generator)));
        double extent2(DoubleMath::FAbs(randomDistribution(generator)));

        axis0.Normalize();

        DoubleVector3DOrthonormalBasis basis = DoubleVector3DTools::GenerateOrthonormalBasis(axis0);

        DoubleDistancePoint3Box3 distance(point, DoubleBox3(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2));

        distance.SetMaximumIterations(20);
        distance.SetZeroThreshold(1e-6);

        double tMin = DoubleMath::FAbs(randomDistribution(generator));
        double tMax = DoubleMath::FAbs(randomDistribution(generator));
        if (tMax < tMin)
        {
            swap(tMin, tMax);
        }

        DoubleVector3D lhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        lhsVelocity.Normalize();
        DoubleVector3D rhsVelocity(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));
        rhsVelocity.Normalize();

        DoubleDistanceResult3 squaredResult = distance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);
        DoubleDistanceResult3 result = distance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(DoubleMath::Sqrt(squaredResult.GetDistance()), result.GetDistance(), 1e-5);
        ASSERT_APPROXIMATE(squaredResult.GetContactTime(), result.GetContactTime(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-2);
        ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, squaredResult.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-2);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DoubleDistanceResult3 tResult = distance.Get(t, lhsVelocity, rhsVelocity);
            DoubleDistanceResult3 tResultSquared = distance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(squaredResult.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
