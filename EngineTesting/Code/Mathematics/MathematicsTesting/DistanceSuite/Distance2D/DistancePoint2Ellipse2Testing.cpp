///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:36)

#include "DistancePoint2Ellipse2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Ellipse2Detail.h"
#include "Mathematics/NumericalAnalysis/Equation.h"

#include <random>

namespace Mathematics
{
    template class DistancePoint2Ellipse2<float>;
    template class DistancePoint2Ellipse2<double>;
}

Mathematics::DistancePoint2Ellipse2Testing::DistancePoint2Ellipse2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, DistancePoint2Ellipse2Testing)

void Mathematics::DistancePoint2Ellipse2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::DistancePoint2Ellipse2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StaticDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DerivativeDistanceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntervalDistanceTest);
}

void Mathematics::DistancePoint2Ellipse2Testing::BaseTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point0(randomDistribution0(generator), randomDistribution0(generator));
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 axis1(randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));

        axis0.Normalize();
        axis1.Normalize();

        const Ellipse2D firstEllipse(center, axis0, axis1, extent0, extent1);

        DistancePoint2Ellipse2D firstDistance(point0, firstEllipse);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-3, 1e-10);

        firstDistance.SetDifferenceStep(1e-1);

        ASSERT_APPROXIMATE(firstDistance.GetDifferenceStep(), 1e-1, 1e-10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 8);

        firstDistance.SetMaximumIterations(10);

        ASSERT_EQUAL(firstDistance.GetMaximumIterations(), 10);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), MathD::GetZeroTolerance(), 1e-10);

        firstDistance.SetZeroThreshold(1e-2);

        ASSERT_APPROXIMATE(firstDistance.GetZeroThreshold(), 1e-2, 1e-10);

        const Vector2 point1 = firstDistance.GetPoint();
        const Ellipse2D secondEllipse = firstDistance.GetEllipse();

        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, point0, point1, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, secondEllipse.GetCenter(), firstEllipse.GetCenter(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, secondEllipse.GetAxis0(), firstEllipse.GetAxis0(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, secondEllipse.GetAxis1(), firstEllipse.GetAxis1(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent0(), firstEllipse.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(secondEllipse.GetExtent1(), firstEllipse.GetExtent1(), 1e-10);
    }
}

void Mathematics::DistancePoint2Ellipse2Testing::StaticDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-10.0, 10.0);
    const std::uniform_real<double> randomDistribution1(0.0, 10.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point0(randomDistribution0(generator), randomDistribution0(generator));
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        const Ellipse2D firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1, 1e-6);

        DistancePoint2Ellipse2D firstDistance(point0, firstEllipse);

        DistanceResult2D result = firstDistance.Get();
        DistanceResult2D resultSquared = firstDistance.GetSquared();

        ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), 0.0, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);
        ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

        ASSERT_TRUE(firstEllipse.Contains(resultSquared.GetRhsClosestPoint()));
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetLhsClosestPoint(), point0, 1e-10);

        const double distance = Vector2ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        const double xMin = (center - basis.GetUVector()).GetX() - extent0;
        const double xMax = (center + basis.GetUVector()).GetX() + extent0;

        for (double value = xMin; value < xMax; value += 1.0)
        {
            const double constantU = (basis.GetUVector().GetX() * (value - center.GetX()) - basis.GetUVector().GetY() * center.GetY());
            const double secondaryU = basis.GetUVector().GetY();
            const double constantV = (basis.GetVVector().GetX() * (value - center.GetX()) - basis.GetVVector().GetY() * center.GetY());
            const double secondaryV = basis.GetVVector().GetY();

            const double secondary = (secondaryU * secondaryU) / (extent0 * extent0) + (secondaryV * secondaryV) / (extent1 * extent1);
            const double once = (2.0 * secondaryU * constantU) / (extent0 * extent0) + (2.0 * secondaryV * constantV) / (extent1 * extent1);
            const double constant = (constantU * constantU) / (extent0 * extent0) + (constantV * constantV) / (extent1 * extent1) - 1.0;

            Equation equation(constant, once, secondary);

            for (Equation::RealConstIterator iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
            {
                const Vector2 eachPoint(value, *iter);

                const double distance2 = Vector2ToolsD::Distance(eachPoint, point0);

                ASSERT_TRUE(result.GetDistance() <= distance2);

                ASSERT_TRUE(firstEllipse.Contains(eachPoint));
            }
        }
    }
}

void Mathematics::DistancePoint2Ellipse2Testing::DynamicDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point0(randomDistribution0(generator), randomDistribution0(generator));
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        const Ellipse2D firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

        DistancePoint2Ellipse2D firstDistance(point0, firstEllipse);

        Vector2 lhsVelocity(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 rhsVelocity(randomDistribution0(generator), randomDistribution0(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        const double t = randomDistribution1(generator);

        DistanceResult2D result = firstDistance.Get(t, lhsVelocity, rhsVelocity);
        DistanceResult2D resultSquared = firstDistance.GetSquared(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(resultSquared.GetDistance(), result.GetDistance() * result.GetDistance(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), result.GetContactTime(), 1e-10);
        ASSERT_APPROXIMATE(resultSquared.GetContactTime(), t, 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        result.GetLhsClosestPoint(), 1e-10);
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetRhsClosestPoint(),
                                        result.GetRhsClosestPoint(), 1e-10);
        ASSERT_EQUAL(resultSquared.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(resultSquared.GetRhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetLhsClosestPointSize(), 1);
        ASSERT_EQUAL(result.GetRhsClosestPointSize(), 1);

        const Ellipse2D secondEllipse(center + t * rhsVelocity, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

        ASSERT_TRUE(secondEllipse.Contains(resultSquared.GetRhsClosestPoint()));
        ASSERT_APPROXIMATE_USE_FUNCTION(Vector2ToolsD::Approximate, resultSquared.GetLhsClosestPoint(),
                                        point0 + t * lhsVelocity, 1e-10);

        const double distance = Vector2ToolsD::Distance(result.GetLhsClosestPoint(), result.GetRhsClosestPoint());
        ASSERT_APPROXIMATE(distance, result.GetDistance(), 1e-10);

        const double xMin = (secondEllipse.GetCenter() - basis.GetUVector()).GetX() - extent0;
        const double xMax = (secondEllipse.GetCenter() + basis.GetUVector()).GetX() + extent0;

        for (double value = xMin; value < xMax; value += 1.0)
        {
            const double constantU = (basis.GetUVector().GetX() * (value - secondEllipse.GetCenter().GetX()) - basis.GetUVector().GetY() * secondEllipse.GetCenter().GetY());
            const double secondaryU = basis.GetUVector().GetY();
            const double constantV = (basis.GetVVector().GetX() * (value - secondEllipse.GetCenter().GetX()) - basis.GetVVector().GetY() * secondEllipse.GetCenter().GetY());
            const double secondaryV = basis.GetVVector().GetY();

            const double secondary = (secondaryU * secondaryU) / (extent0 * extent0) + (secondaryV * secondaryV) / (extent1 * extent1);
            const double once = (2.0 * secondaryU * constantU) / (extent0 * extent0) + (2.0 * secondaryV * constantV) / (extent1 * extent1);
            const double constant = (constantU * constantU) / (extent0 * extent0) + (constantV * constantV) / (extent1 * extent1) - 1.0;

            Equation equation(constant, once, secondary);

            for (Equation::RealConstIterator iter = equation.GetRealBegin(); iter != equation.GetRealEnd(); ++iter)
            {
                const Vector2 eachPoint(value, *iter);

                const double distance2 = Vector2ToolsD::Distance(eachPoint, resultSquared.GetLhsClosestPoint());

                ASSERT_TRUE(result.GetDistance() <= distance2);

                ASSERT_TRUE(secondEllipse.Contains(eachPoint));
            }
        }
    }
}

void Mathematics::DistancePoint2Ellipse2Testing::DerivativeDistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-100.0, 100.0);
    const std::uniform_real<double> randomDistribution1(0.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 point0(randomDistribution0(generator), randomDistribution0(generator));
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 axis0(randomDistribution0(generator), randomDistribution0(generator));
        const double extent0(randomDistribution1(generator));
        const double extent1(randomDistribution1(generator));

        axis0.Normalize();

        const Vector2OrthonormalBasisD basis = Vector2ToolsD::GenerateOrthonormalBasis(axis0);

        const Ellipse2D firstEllipse(center, basis.GetUVector(), basis.GetVVector(), extent0, extent1);

        DistancePoint2Ellipse2D firstDistance(point0, firstEllipse);

        Vector2 lhsVelocity(randomDistribution0(generator), randomDistribution0(generator));
        Vector2 rhsVelocity(randomDistribution0(generator), randomDistribution0(generator));

        lhsVelocity.Normalize();
        rhsVelocity.Normalize();

        const double t = randomDistribution1(generator);

        const double result = firstDistance.GetDerivative(t, lhsVelocity, rhsVelocity);
        const double resultSquared = firstDistance.GetDerivativeSquared(t, lhsVelocity, rhsVelocity);

        DistanceResult2D funcp = firstDistance.Get(t + firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        DistanceResult2D funcm = firstDistance.Get(t - firstDistance.GetDifferenceStep(), lhsVelocity, rhsVelocity);
        const double derApprox = 0.5 / firstDistance.GetDifferenceStep() * (funcp.GetDistance() - funcm.GetDistance());

        ASSERT_APPROXIMATE(derApprox, result, 1e-10);

        DistanceResult2D distance = firstDistance.Get(t, lhsVelocity, rhsVelocity);

        ASSERT_APPROXIMATE(distance.GetDistance() * result * 2.0, resultSquared, 1e-10);
    }
}

void Mathematics::DistancePoint2Ellipse2Testing::IntervalDistanceTest() noexcept
{
}
