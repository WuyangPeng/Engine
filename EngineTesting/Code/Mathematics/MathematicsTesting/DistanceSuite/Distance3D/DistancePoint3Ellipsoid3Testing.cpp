///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:45)

#include "DistancePoint3Ellipsoid3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Ellipsoid3Detail.h"
#include "Mathematics/NumericalAnalysis/Equation.h"

#include <random>

Mathematics::DistancePoint3Ellipsoid3Testing::DistancePoint3Ellipsoid3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistancePoint3Ellipsoid3Testing)

void Mathematics::DistancePoint3Ellipsoid3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistancePoint3Ellipsoid3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalDistanceTest);
}

void Mathematics::DistancePoint3Ellipsoid3Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const Vector3D center(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis1(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis2(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));
        const double extent2(randomDistribution1(generator));

        axis0.Normalize();
        axis1.Normalize();
        axis2.Normalize();

        const Ellipsoid3D firstEllipsoid(center, axis0, axis1, axis2, extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(point0, firstEllipsoid);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-3, 1e-10);

        firstDistance.SetDifferenceStep(1e-1);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-1, 1e-10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 8);

        firstDistance.SetMaximumIterations(10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 10);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), MathD::GetZeroTolerance(), 1e-10);

        firstDistance.SetZeroThreshold(1e-2);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), 1e-2, 1e-10);

        const Vector3D point1 = firstDistance.GetPoint();
        const Ellipsoid3D secondEllipse = firstDistance.GetEllipsoid();

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, point0, point1, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetCenter(), firstEllipsoid.GetCenter(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis0(), firstEllipsoid.GetAxis0(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis1(), firstEllipsoid.GetAxis1(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, secondEllipse.GetAxis2(), firstEllipsoid.GetAxis2(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent0(), firstEllipsoid.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent1(), firstEllipsoid.GetExtent1(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent2(), firstEllipsoid.GetExtent2(), 1e-10);
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing::StaticDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 50.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const Vector3D center(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));
        const double extent2(randomDistribution1(generator));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        const Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(point0, firstEllipsoid);

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
                                        point0, 1e-10);

        const double distance = Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        const double xMin = (center - basis.GetUVector()).GetX() - extent0;
        const double xMax = (center + basis.GetUVector()).GetX() + extent0;

        for (double x = xMin; x < xMax; x += 1.0)
        {
            const double yMin = (center - basis.GetVVector()).GetY() - extent1;
            const double yMax = (center + basis.GetVVector()).GetY() + extent1;

            for (double y = yMin; y < yMax; y += 1.0)
            {
                const double constantUX = basis.GetUVector().GetX() * (x - center.GetX());
                const double constantUY = basis.GetUVector().GetY() * (y - center.GetY());
                const double constantUZ = basis.GetUVector().GetZ() * (-center.GetZ());
                const double constantVX = basis.GetVVector().GetX() * (x - center.GetX());
                const double constantVY = basis.GetVVector().GetY() * (y - center.GetY());
                const double constantVZ = basis.GetVVector().GetZ() * (-center.GetZ());
                const double constantWX = basis.GetWVector().GetX() * (x - center.GetX());
                const double constantWY = basis.GetWVector().GetY() * (y - center.GetY());
                const double constantWZ = basis.GetWVector().GetZ() * (-center.GetZ());

                const double secondary = (basis.GetUVector().GetZ() * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                         (basis.GetVVector().GetZ() * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                         (basis.GetWVector().GetZ() * basis.GetWVector().GetZ()) / (extent2 * extent2);
                const double once = (2.0 * (constantUX + constantUY + constantUZ) * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                    (2.0 * (constantVX + constantVY + constantVZ) * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                    (2.0 * (constantWX + constantWY + constantWZ) * basis.GetWVector().GetZ()) / (extent2 * extent2);
                const double constant = (constantUX + constantUY + constantUZ) * (constantUX + constantUY + constantUZ) / (extent0 * extent0) +
                                        (constantVX + constantVY + constantVZ) * (constantVX + constantVY + constantVZ) / (extent1 * extent1) +
                                        (constantWX + constantWY + constantWZ) * (constantWX + constantWY + constantWZ) / (extent2 * extent2) - 1.0;

                Equation equation(constant, once, secondary);

                for (Equation::RealConstIterator iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
                {
                    const Vector3D eachPoint(x, y, *iter);

                    const double distance2 = Vector3ToolsD::Distance(eachPoint, point0);

                    ASSERT_TRUE(result.GetDistance() <= distance2);

                    ASSERT_TRUE(firstEllipsoid.Contains(eachPoint));
                }
            }
        }
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing::DynamicDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 50.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const Vector3D center(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));
        const double extent2(randomDistribution1(generator));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        const Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(point0, firstEllipsoid);

        Vector3D lhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D rhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        const double t = randomDistribution1(generator);

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

        const Ellipsoid3D secondEllipse(center + t * rhsVelocity, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2, 1e-4);

        ASSERT_TRUE(secondEllipse.Contains(resultSquared.GetRhsClosestPoint()));
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        point0 + t * lhsVelocity, 1e-10);

        const double distance = Vector3ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        const double xMin = (secondEllipse.GetCenter() - basis.GetUVector()).GetX() - extent0;
        const double xMax = (secondEllipse.GetCenter() + basis.GetUVector()).GetX() + extent0;

        for (double x = xMin; x < xMax; x += 1.0)
        {
            const double yMin = (secondEllipse.GetCenter() - basis.GetVVector()).GetY() - extent1;
            const double yMax = (secondEllipse.GetCenter() + basis.GetVVector()).GetY() + extent1;

            for (double y = yMin; y < yMax; y += 1.0)
            {
                const double constantUX = basis.GetUVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                const double constantUY = basis.GetUVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                const double constantUZ = basis.GetUVector().GetZ() * (-secondEllipse.GetCenter().GetZ());
                const double constantVX = basis.GetVVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                const double constantVY = basis.GetVVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                const double constantVZ = basis.GetVVector().GetZ() * (-secondEllipse.GetCenter().GetZ());
                const double constantWX = basis.GetWVector().GetX() * (x - secondEllipse.GetCenter().GetX());
                const double constantWY = basis.GetWVector().GetY() * (y - secondEllipse.GetCenter().GetY());
                const double constantWZ = basis.GetWVector().GetZ() * (-secondEllipse.GetCenter().GetZ());

                const double secondary = (basis.GetUVector().GetZ() * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                         (basis.GetVVector().GetZ() * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                         (basis.GetWVector().GetZ() * basis.GetWVector().GetZ()) / (extent2 * extent2);
                const double once = (2.0 * (constantUX + constantUY + constantUZ) * basis.GetUVector().GetZ()) / (extent0 * extent0) +
                                    (2.0 * (constantVX + constantVY + constantVZ) * basis.GetVVector().GetZ()) / (extent1 * extent1) +
                                    (2.0 * (constantWX + constantWY + constantWZ) * basis.GetWVector().GetZ()) / (extent2 * extent2);
                const double constant = (constantUX + constantUY + constantUZ) * (constantUX + constantUY + constantUZ) / (extent0 * extent0) +
                                        (constantVX + constantVY + constantVZ) * (constantVX + constantVY + constantVZ) / (extent1 * extent1) +
                                        (constantWX + constantWY + constantWZ) * (constantWX + constantWY + constantWZ) / (extent2 * extent2) - 1.0;

                Equation equation(constant, once, secondary);

                for (Equation::RealConstIterator iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
                {
                    const Vector3D eachPoint(x, y, *iter);

                    const double distance2 = Vector3ToolsD::Distance(eachPoint, resultSquared.GetLhsClosestPoint());

                    ASSERT_TRUE(result.GetDistance() <= distance2);

                    ASSERT_TRUE(secondEllipse.Contains(eachPoint));
                }
            }
        }
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing::DerivativeDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 50.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const Vector3D center(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));
        const double extent2(randomDistribution1(generator));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        const Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(point0, firstEllipsoid);

        Vector3D lhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D rhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        const double t = randomDistribution1(generator);

        const double result = firstDistance.GetDerivative(t, lhsVelocity, rhsVelocity);
        const double resultSquared = firstDistance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult3D funcp = firstDistance.Get(t + firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult3D funcm = firstDistance.Get(t - firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        const double derApprox = 0.5 / firstDistance.GetDifferenceStep() * (funcp.GetDistance() - funcm.GetDistance());

        ASSERT_APPROXIMATE(derApprox, result, 1e-10);

        DistanceResult3D distance = firstDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(distance.GetDistance() * result * 2.0, resultSquared, 1e-10);
    }
}

void Mathematics::DistancePoint3Ellipsoid3Testing::IntervalDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 20.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const Vector3D center(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D axis0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));
        const double extent2(randomDistribution1(generator));

        axis0.Normalize();

        const Vector3OrthonormalBasisD basis = Vector3ToolsD::GenerateOrthonormalBasis(axis0);
        const Ellipsoid3D firstEllipsoid(center, basis.GetUVector(), basis.GetVVector(), basis.GetWVector(), extent0, extent1, extent2);

        DistancePoint3Ellipsoid3D firstDistance(point0, firstEllipsoid);
        firstDistance.SetMaximumIterations(20);

        Vector3D lhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));
        Vector3D rhsVelocity(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        const double tMin = randomDistribution1(generator);
        const double tMax = tMin + randomDistribution1(generator);

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
