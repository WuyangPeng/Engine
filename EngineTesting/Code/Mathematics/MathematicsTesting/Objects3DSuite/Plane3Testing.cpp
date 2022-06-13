///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/30 11:31)

#include "Plane3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Plane3<float>;
    template class Plane3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Plane3Testing)

void Mathematics::Plane3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
}

void Mathematics::Plane3Testing::ConstructionTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D normal(firstRandomDistribution(generator),
                        firstRandomDistribution(generator),
                        firstRandomDistribution(generator));

        normal.Normalize();

        double constant(firstRandomDistribution(generator));

        const Plane3D plane(normal, constant);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, plane.GetNormal()));
        ASSERT_APPROXIMATE(constant, plane.GetConstant(), 1e-10);

        const Vector3D firstPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        const Plane3D secondPlane(normal, firstPoint);

        constant = Vector3ToolsD::DotProduct(normal, firstPoint);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, secondPlane.GetNormal()));
        ASSERT_APPROXIMATE(constant, secondPlane.GetConstant(), 1e-10);

        const Vector3D secondPoint(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Vector3D thirdPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        auto edge1 = secondPoint - firstPoint;
        auto edge2 = thirdPoint - firstPoint;
        normal = Vector3ToolsD::UnitCrossProduct(edge1, edge2);
        constant = Vector3ToolsD::DotProduct(normal, firstPoint);

        const Plane3D thirdPlane(firstPoint, secondPoint, thirdPoint);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, thirdPlane.GetNormal()));
        ASSERT_APPROXIMATE(constant, thirdPlane.GetConstant(), 1e-10);
    }
}

void Mathematics::Plane3Testing::DistanceTest()
{
    default_random_engine generator{};

    const uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D firstPoint(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const Vector3D secondPoint(randomDistribution(generator),
                                   randomDistribution(generator),
                                   randomDistribution(generator));

        const Vector3D thirdPoint(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const Plane3D plane(firstPoint, secondPoint, thirdPoint);

        ASSERT_APPROXIMATE(plane.DistanceTo(firstPoint), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(secondPoint), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(thirdPoint), 0.0, 1e-10);

        ASSERT_ENUM_EQUAL(plane.WhichSide(firstPoint), NumericalValueSymbol::Zero);
        ASSERT_ENUM_EQUAL(plane.WhichSide(secondPoint), NumericalValueSymbol::Zero);
        ASSERT_ENUM_EQUAL(plane.WhichSide(thirdPoint), NumericalValueSymbol::Zero);

        const Vector3D fourthPoint(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        auto distance = plane.DistanceTo(fourthPoint);

        if (MathD::GetZeroTolerance() < distance)
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Positive);
        else if (distance < MathD::GetZeroTolerance())
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Negative);
        else
            ASSERT_ENUM_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Zero);
    }
}
