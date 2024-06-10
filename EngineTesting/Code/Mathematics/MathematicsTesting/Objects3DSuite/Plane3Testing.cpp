///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:17)

#include "Plane3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"

#include <random>

namespace Mathematics
{
    template class Plane3<float>;
    template class Plane3<double>;
}

Mathematics::Plane3Testing::Plane3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Plane3Testing)

void Mathematics::Plane3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Plane3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
}

void Mathematics::Plane3Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D normal(randomDistribution0(generator),
                        randomDistribution0(generator),
                        randomDistribution0(generator));

        normal.Normalize();

        double constant(randomDistribution0(generator));

        const Plane3D plane(normal, constant);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, plane.GetNormal()));
        ASSERT_APPROXIMATE(constant, plane.GetConstant(), 1e-10);

        const Vector3D point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Plane3D secondPlane(normal, point0);

        constant = Vector3ToolsD::DotProduct(normal, point0);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, secondPlane.GetNormal()));
        ASSERT_APPROXIMATE(constant, secondPlane.GetConstant(), 1e-10);

        const Vector3D point1(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D point2(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        auto edge1 = point1 - point0;
        auto edge2 = point2 - point0;
        normal = Vector3ToolsD::UnitCrossProduct(edge1, edge2);
        constant = Vector3ToolsD::DotProduct(normal, point0);

        const Plane3D thirdPlane(point0, point1, point2);

        ASSERT_TRUE(Vector3ToolsD::Approximate(normal, thirdPlane.GetNormal()));
        ASSERT_APPROXIMATE(constant, thirdPlane.GetConstant(), 1e-10);
    }
}

void Mathematics::Plane3Testing::DistanceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Vector3D point1(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Vector3D point2(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Plane3D plane(point0, point1, point2);

        ASSERT_APPROXIMATE(plane.DistanceTo(point0), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(point1), 0.0, 1e-10);
        ASSERT_APPROXIMATE(plane.DistanceTo(point2), 0.0, 1e-10);

        ASSERT_EQUAL(plane.WhichSide(point0), NumericalValueSymbol::Zero);
        ASSERT_EQUAL(plane.WhichSide(point1), NumericalValueSymbol::Zero);
        ASSERT_EQUAL(plane.WhichSide(point2), NumericalValueSymbol::Zero);

        const Vector3D fourthPoint(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        auto distance = plane.DistanceTo(fourthPoint);

        if (MathD::GetZeroTolerance() < distance)
            ASSERT_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Positive);
        else if (distance < MathD::GetZeroTolerance())
            ASSERT_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Negative);
        else
            ASSERT_EQUAL(plane.WhichSide(fourthPoint), NumericalValueSymbol::Zero);
    }
}
