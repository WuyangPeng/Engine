// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 13:09)

#include "DistancePoint3Ellipsoid3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Ellipsoid3Detail.h"
#include "Mathematics/NumericalAnalysis/Equation.h"

#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistancePoint3Ellipsoid3Testing)
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::DistancePoint3Ellipsoid3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalDistanceTest);
}

void Mathematics::DistancePoint3Ellipsoid3Testing ::BaseTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    std::uniform_real<double> secondRandomDistribution(0.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D center(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis1(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis2(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        double extent0(secondRandomDistribution(generator));
        double extent1(secondRandomDistribution(generator));
        double extent2(secondRandomDistribution(generator));

        axis0.Normalize();
        axis1.Normalize();
        axis2.Normalize();

        Ellipsoid3D firstEllipsoid(center, axis0, axis1, axis2, extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(firstPoint, firstEllipsoid);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-3, 1e-10);

        firstDistance.SetDifferenceStep(1e-1);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-1, 1e-10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 8);

        firstDistance.SetMaximumIterations(10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 10);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), MathD::GetZeroTolerance(), 1e-10);

        firstDistance.SetZeroThreshold(1e-2);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), 1e-2, 1e-10);

        Vector3D secondPoint = firstDistance.GetPoint();
        Ellipsoid3D secondEllipse = firstDistance.GetEllipsoid();

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, firstPoint, secondPoint, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetCenter(), firstEllipsoid.GetCenter(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis0(), firstEllipsoid.GetAxis0(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis1(), firstEllipsoid.GetAxis1(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis2(), firstEllipsoid.GetAxis2(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent0(), firstEllipsoid.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent1(), firstEllipsoid.GetExtent1(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent2(), firstEllipsoid.GetExtent2(), 1e-10);
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing ::StaticDistanceTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    std::uniform_real<double> secondRandomDistribution(0.0, 50.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D center(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        double extent0(secondRandomDistribution(generator));
        double extent1(secondRandomDistribution(generator));
        double extent2(secondRandomDistribution(generator));

        axis0.Normalize();

        Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(firstPoint, firstEllipsoid);

        DistanceResult3D result = firstDistance.Get();
        DistanceResult3D resultSquared = firstDistance.GetSquared();

        ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);
        ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

        ASSERT_TRUE(firstEllipsoid.Contains(resultSquared.GetRhsClosestPoint()));
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        firstPoint, 1e-10);

        double distance = Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        double xMin = (center - basis.GetUVector()).GetX() - extent0;
        double xMax = (center + basis.GetUVector()).GetX() + extent0;

        for (double x = xMin; x < xMax; x += 1.0)
        {
            double yMin = (center - basis.GetVVector()).GetY() - extent1;
            double yMax = (center + basis.GetVVector()).GetY() + extent1;

            for (double y = yMin; y < yMax; y += 1.0)
            {
                double constantUX = basis.GetUVector().GetX() * (x - center.GetX());
                double constantUY = basis.GetUVector().GetY() * (y - center.GetY());
                double constantUZ = basis.GetUVector().GetZ() * (-center.GetZ());
                double constantVX = basis.GetVVector().GetX() * (x - center.GetX());
                double constantVY = basis.GetVVector().GetY() * (y - center.GetY());
                double constantVZ = basis.GetVVector().GetZ() * (-center.GetZ());
                double constantWX = basis.GetWVector().GetX() * (x - center.GetX());
                double constantWY = basis.GetWVector().GetY() * (y - center.GetY());
                double constantWZ = basis.GetWVector().GetZ() * (-center.GetZ());

                double secondary = (basis.GetUVector().GetZ() * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                   (basis.GetVVector().GetZ() * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                   (basis.GetWVector().GetZ() * basis.GetWVector().GetZ()) / (extent2 * extent2);
                double once = (2.0 * (constantUX + constantUY + constantUZ) * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                              (2.0 * (constantVX + constantVY + constantVZ) * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                              (2.0 * (constantWX + constantWY + constantWZ) * basis.GetWVector().GetZ()) / (extent2 * extent2);
                double constant = (constantUX + constantUY + constantUZ) * (constantUX + constantUY + constantUZ) / (extent0 * extent0) +
                                  (constantVX + constantVY + constantVZ) * (constantVX + constantVY + constantVZ) / (extent1 * extent1) +
                                  (constantWX + constantWY + constantWZ) * (constantWX + constantWY + constantWZ) / (extent2 * extent2) - 1.0;

                Equation equation(constant, once, secondary);

                for (Equation::RealConstIterator iter = equation.GetRealBegin(), end = equation.GetRealEnd();
                     iter != end; ++iter)
                {
                    Vector3D eachPoint(x, y, *iter);

                    double distance2 = Vector3ToolsD::Distance(eachPoint, firstPoint);

                    ASSERT_TRUE(result.GetDistance() <= distance2);

                    ASSERT_TRUE(firstEllipsoid.Contains(eachPoint));
                }
            }
        }
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing ::DynamicDistanceTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    std::uniform_real<double> secondRandomDistribution(0.0, 50.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D center(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        double extent0(secondRandomDistribution(generator));
        double extent1(secondRandomDistribution(generator));
        double extent2(secondRandomDistribution(generator));

        axis0.Normalize();

        Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(firstPoint, firstEllipsoid);

        Vector3D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        double t = secondRandomDistribution(generator);

        DistanceResult3D result = firstDistance.Get(t, lhsVelocity, rhsVelocity);
        DistanceResult3D resultSquared = firstDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);
        ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

        Ellipsoid3D secondEllipse(center + t * rhsVelocity, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2, 1e-4);

        ASSERT_TRUE(secondEllipse.Contains(resultSquared.GetRhsClosestPoint()));
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        firstPoint + t * lhsVelocity, 1e-10);

        double distance = Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        double xMin = (secondEllipse.GetCenter() - basis.GetUVector()).GetX() - extent0;
        double xMax = (secondEllipse.GetCenter() + basis.GetUVector()).GetX() + extent0;

        for (double x = xMin; x < xMax; x += 1.0)
        {
            double yMin = (secondEllipse.GetCenter() - basis.GetVVector()).GetY() - extent1;
            double yMax = (secondEllipse.GetCenter() + basis.GetVVector()).GetY() + extent1;

            for (double y = yMin; y < yMax; y += 1.0)
            {
                double constantUX = basis.GetUVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                double constantUY = basis.GetUVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                double constantUZ = basis.GetUVector().GetZ() * (-secondEllipse.GetCenter().GetZ());
                double constantVX = basis.GetVVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                double constantVY = basis.GetVVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                double constantVZ = basis.GetVVector().GetZ() * (-secondEllipse.GetCenter().GetZ());
                double constantWX = basis.GetWVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                double constantWY = basis.GetWVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                double constantWZ = basis.GetWVector().GetZ() * (-secondEllipse.GetCenter().GetZ());

                double secondary = (basis.GetUVector().GetZ() * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                   (basis.GetVVector().GetZ() * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                   (basis.GetWVector().GetZ() * basis.GetWVector().GetZ()) / (extent2 * extent2);
                double once = (2.0 * (constantUX + constantUY + constantUZ) * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                              (2.0 * (constantVX + constantVY + constantVZ) * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                              (2.0 * (constantWX + constantWY + constantWZ) * basis.GetWVector().GetZ()) / (extent2 * extent2);
                double constant = (constantUX + constantUY + constantUZ) * (constantUX + constantUY + constantUZ) / (extent0 * extent0) +
                                  (constantVX + constantVY + constantVZ) * (constantVX + constantVY + constantVZ) / (extent1 * extent1) +
                                  (constantWX + constantWY + constantWZ) * (constantWX + constantWY + constantWZ) / (extent2 * extent2) - 1.0;

                Equation equation(constant, once, secondary);

                for (Equation::RealConstIterator iter = equation.GetRealBegin(), end = equation.GetRealEnd();
                     iter != end; ++iter)
                {
                    Vector3D eachPoint(x, y, *iter);

                    double distance2 = Vector3ToolsD::Distance(eachPoint, resultSquared.GetLhsClosestPoint());

                    ASSERT_TRUE(result.GetDistance() <= distance2);

                    ASSERT_TRUE(secondEllipse.Contains(eachPoint));
                }
            }
        }
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing ::DerivativeDistanceTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    std::uniform_real<double> secondRandomDistribution(0.0, 50.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D center(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        double extent0(secondRandomDistribution(generator));
        double extent1(secondRandomDistribution(generator));
        double extent2(secondRandomDistribution(generator));

        axis0.Normalize();

        Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(firstPoint, firstEllipsoid);

        Vector3D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        double t = secondRandomDistribution(generator);

        double result = firstDistance.GetDerivative(t, lhsVelocity, rhsVelocity);
        double resultSquared = firstDistance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult3D funcp = firstDistance.Get(t + firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult3D funcm = firstDistance.Get(t - firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        double derApprox = 0.5 / firstDistance.GetDifferenceStep() * (funcp.GetDistance() - funcm.GetDistance());

        ASSERT_APPROXIMATE(derApprox, result, 1e-10);

        DistanceResult3D distance = firstDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(distance.GetDistance() * result * 2.0, resultSquared, 1e-10);
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing ::IntervalDistanceTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    std::uniform_real<double> secondRandomDistribution(0.0, 20.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D center(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D axis0(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        double extent0(secondRandomDistribution(generator));
        double extent1(secondRandomDistribution(generator));
        double extent2(secondRandomDistribution(generator));

        axis0.Normalize();

        Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(firstPoint, firstEllipsoid);
        firstDistance.SetMaximumIterations(20);

        Vector3D lhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
        Vector3D rhsVelocity(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        double tMin = secondRandomDistribution(generator);
        double tMax = tMin + secondRandomDistribution(generator);

        DistanceResult3D result = firstDistance.GetInterval(tMin, tMax, lhsVelocity, rhsVelocity);
        DistanceResult3D resultSquared = firstDistance.GetIntervalSquared(tMin, tMax, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(MathD::Sqrt(resultSquared.GetDistance()), result.GetDistance(), 1e-3);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-1);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-1);
        ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

        for (double t = tMin; t < tMax; t += 0.1)
        {
            DistanceResult3D tResult = firstDistance.Get(t, lhsVelocity, rhsVelocity);
            DistanceResult3D tResultSquared = firstDistance.GetSquared(t, lhsVelocity, rhsVelocity);

            ASSERT_TRUE(result.GetDistance() <= tResult.GetDistance());
            ASSERT_TRUE(resultSquared.GetDistance() <= tResultSquared.GetDistance());
        }
    }
}
