///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:14)

#include "PlaneTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Plane<float>;
    template class Plane<double>;
}

Mathematics::PlaneTesting::PlaneTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PlaneTesting)

void Mathematics::PlaneTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PlaneTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
}

void Mathematics::PlaneTesting::ConstructionTest()
{
    const PlaneF firstPlane;

    ASSERT_APPROXIMATE(firstPlane.GetConstant(), 0.0f, 1e-8f);
    ASSERT_TRUE(Approximate(firstPlane.GetNormal(), AVectorF::GetUnitX(), 1e-8f));

    AVectorD firstNormal(6.0, 1.0, 3.0);
    firstNormal.Normalize();

    const PlaneD secondPlane(firstNormal[0], firstNormal[1], firstNormal[2], 5.0);
    const AVectorD secondNormal = secondPlane.GetNormal();

    ASSERT_APPROXIMATE(secondPlane.GetConstant(), 5.0, 1e-10);
    ASSERT_TRUE(Approximate(secondNormal, firstNormal, 1e-10));

    const PlaneD thirdPlane(firstNormal, 6.0);
    const AVectorD thirdNormal = thirdPlane.GetNormal();

    ASSERT_APPROXIMATE(thirdPlane.GetConstant(), 6.0, 1e-10);
    ASSERT_TRUE(Approximate(thirdNormal, firstNormal, 1e-10));

    const APointD firstPoint(9.0, 2.0, 3.0);

    const PlaneD fourthPlane(firstNormal, firstPoint);
    ASSERT_APPROXIMATE(fourthPlane.DistanceTo(firstPoint), 0.0, 1e-10);

    const APointD secondPoint(19.0, 22.0, 13.0);
    const APointD thirdPoint(-19.0, -22.0, 3.0);

    const PlaneD fifthPlane(firstPoint, secondPoint, thirdPoint);
    ASSERT_APPROXIMATE(fifthPlane.DistanceTo(firstPoint), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthPlane.DistanceTo(secondPoint), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthPlane.DistanceTo(thirdPoint), 0.0, 1e-10);

    HomogeneousPointD homogeneousPoint(3.0, 5.0, 6.0, 1.0);

    PlaneD sixthPlane(homogeneousPoint, 1e-7);

    const double length = MathD::Sqrt(homogeneousPoint[0] * homogeneousPoint[0] +
                                      homogeneousPoint[1] * homogeneousPoint[1] +
                                      homogeneousPoint[2] * homogeneousPoint[2]);

    ASSERT_APPROXIMATE(sixthPlane[0], 3.0 / length, 1e-10);
    ASSERT_APPROXIMATE(sixthPlane[1], 5.0 / length, 1e-10);
    ASSERT_APPROXIMATE(sixthPlane[2], 6.0 / length, 1e-10);
    ASSERT_APPROXIMATE(sixthPlane[3], 1.0 / length, 1e-10);
}

void Mathematics::PlaneTesting::AccessTest()
{
    AVectorD firstNormal(6.0, 1.0, 3.0);
    firstNormal.Normalize();

    const PlaneD firstPlane(firstNormal, 3.0);

    HomogeneousPointD secondHomogeneousPoint = firstPlane.GetHomogeneousPoint();

    ASSERT_APPROXIMATE(secondHomogeneousPoint[0], firstNormal[0], 1e-10);
    ASSERT_APPROXIMATE(secondHomogeneousPoint[1], firstNormal[1], 1e-10);
    ASSERT_APPROXIMATE(secondHomogeneousPoint[2], firstNormal[2], 1e-10);
    ASSERT_APPROXIMATE(secondHomogeneousPoint[3], -3.0, 1e-10);
}

void Mathematics::PlaneTesting::CompareTest()
{
    AVectorD firstNormal(6.0, 1.0, 3.0);
    firstNormal.Normalize();

    const PlaneD firstPlane(firstNormal, -3.0);
    const PlaneD secondPlane(firstNormal, -13.0);

    ASSERT_TRUE(firstPlane == firstPlane);
    ASSERT_TRUE(secondPlane == secondPlane);
    ASSERT_FALSE(firstPlane == secondPlane);
    ASSERT_TRUE(firstPlane != secondPlane);
    ASSERT_TRUE(firstPlane < secondPlane);
    ASSERT_TRUE(firstPlane <= secondPlane);
    ASSERT_FALSE(firstPlane > secondPlane);
    ASSERT_FALSE(firstPlane >= secondPlane);

    ASSERT_TRUE(Approximate(firstPlane, firstPlane, 1e-10));
    ASSERT_TRUE(Approximate(secondPlane, secondPlane));
    ASSERT_FALSE(Approximate(firstPlane, secondPlane));
}

void Mathematics::PlaneTesting::DistanceTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const APointD firstPoint(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        const APointD secondPoint(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const APointD thirdPoint(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        const PlaneD plane(firstPoint, secondPoint, thirdPoint);

        ASSERT_APPROXIMATE(plane.DistanceTo(firstPoint), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(secondPoint), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(thirdPoint), 0.0, 1e-10);

        ASSERT_ENUM_EQUAL(plane.WhichSide(firstPoint), NumericalValueSymbol::Zero);
        ASSERT_ENUM_EQUAL(plane.WhichSide(secondPoint), NumericalValueSymbol::Zero);
        ASSERT_ENUM_EQUAL(plane.WhichSide(thirdPoint), NumericalValueSymbol::Zero);

        const APointD fourthPoint(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const double distance = plane.DistanceTo(fourthPoint);
        const double epsilon = plane.GetEpsilon();

        if (epsilon < distance)
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Positive);
        else if (distance < epsilon)
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Negative);
        else
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Zero);
    }
}
