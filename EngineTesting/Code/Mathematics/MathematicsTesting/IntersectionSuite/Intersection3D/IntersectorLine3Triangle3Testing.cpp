///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:54)

#include "IntersectorLine3Triangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorLine3Triangle3Detail.h"

#include <random>

using System::operator*;
using System::operator-;

namespace Mathematics
{
    template class StaticFindIntersectorLine3Triangle3<float>;
    template class StaticFindIntersectorLine3Triangle3<double>;
    template class StaticTestIntersectorLine3Triangle3<float>;
    template class StaticTestIntersectorLine3Triangle3<double>;
}

Mathematics::IntersectorLine3Triangle3Testing::IntersectorLine3Triangle3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntersectorLine3Triangle3Testing)

void Mathematics::IntersectorLine3Triangle3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntersectorLine3Triangle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FindTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectTest);
}

void Mathematics::IntersectorLine3Triangle3Testing::FindTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D origin(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        Vector3D direction(randomDistribution(generator),
                           randomDistribution(generator),
                           randomDistribution(generator));

        direction.Normalize();

        const Line3D line(origin, direction);

        const Vector3D point0(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Vector3D point1(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Vector3D point2(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Triangle3D triangle(point0, point1, point2);

        StaticFindIntersectorLine3Triangle3<double> intersector(line, triangle);

        const IntersectionType intersectionType = intersector.GetIntersectionType();

        if (intersectionType == IntersectionType::Point)
            ASSERT_TRUE(intersector.IsIntersection());
        else
            ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetLine().GetDirection(),
                                               direction, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetLine().GetOrigin(),
                                               origin, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(0),
                                               point0, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(1),
                                               point1, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(2),
                                               point2, 1e-10));

        // 值测试
        const Vector3D lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
        const Vector3D edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
        const Vector3D edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
        const Vector3D normal = Vector3ToolsD::CrossProduct(edge1, edge2);

        double directionDotNormal = Vector3ToolsD::DotProduct(line.GetDirection(), normal);

        if (MathD::FAbs(directionDotNormal) <= MathD::GetZeroTolerance())
        {
            ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
        }
        else
        {
            NumericalValueSymbol sign = NumericalValueSymbol::Zero;
            if (MathD::GetZeroTolerance() < directionDotNormal)
            {
                sign = NumericalValueSymbol::Positive;
            }
            else if (directionDotNormal < MathD::GetZeroTolerance())
            {
                sign = NumericalValueSymbol::Negative;
                directionDotNormal = -directionDotNormal;
            }

            const Vector3D originCrossEdge2 = Vector3ToolsD::CrossProduct(lineOrigin, edge2);
            const double directionDotOriginCrossEdge2 = sign * Vector3ToolsD::DotProduct(line.GetDirection(), originCrossEdge2);
            if (0.0 <= directionDotOriginCrossEdge2)
            {
                const Vector3D edge1CrossOrigin = Vector3ToolsD::CrossProduct(edge1, lineOrigin);
                const double directionDotEdge1CrossOrigin = sign * Vector3ToolsD::DotProduct(line.GetDirection(), edge1CrossOrigin);

                if (0.0 <= directionDotEdge1CrossOrigin)
                {
                    if (directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin <= directionDotNormal)
                    {
                        ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Point);
                        const double originDotNormal = -sign * Vector3ToolsD::DotProduct(lineOrigin, normal);

                        const double lineParameter = originDotNormal / directionDotNormal;
                        const double triangleBary1 = directionDotOriginCrossEdge2 / directionDotNormal;
                        const double triangleBary2 = directionDotEdge1CrossOrigin / directionDotNormal;
                        const double triangleBary0 = 1.0 - triangleBary1 - triangleBary2;

                        ASSERT_APPROXIMATE(lineParameter, intersector.GetLineParameter(), 1e-10);
                        ASSERT_APPROXIMATE(triangleBary0, intersector.GetTriangleBary0(), 1e-10);
                        ASSERT_APPROXIMATE(triangleBary1, intersector.GetTriangleBary1(), 1e-10);
                        ASSERT_APPROXIMATE(triangleBary2, intersector.GetTriangleBary2(), 1e-10);
                    }
                    else
                    {
                        ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
                    }
                }
                else
                {
                    ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
                }
            }
            else
            {
                ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
            }
        }
    }
}

void Mathematics::IntersectorLine3Triangle3Testing::IntersectTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3F origin(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3F direction(randomDistribution0(generator),
                           randomDistribution0(generator),
                           randomDistribution0(generator));

        direction.Normalize();

        const Line3F line(origin, direction);

        const Vector3F point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3F point1(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3F point2(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Triangle3F triangle(point0, point1, point2);

        StaticTestIntersectorLine3Triangle3<float> intersector(line, triangle);

        const IntersectionType intersectionType = intersector.GetIntersectionType();

        if (intersectionType == IntersectionType::Point)
            ASSERT_TRUE(intersector.IsIntersection());
        else
            ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetLine().GetDirection(),
                                               direction, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetLine().GetOrigin(),
                                               origin, 1e-8f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(0),
                                               point0, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(1),
                                               point1, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(2),
                                               point2, 1e-8f));

        // 值测试
        const Vector3F lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
        const Vector3F edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
        const Vector3F edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
        const Vector3F normal = Vector3ToolsF::CrossProduct(edge1, edge2);

        float directionDotNormal = Vector3ToolsF::DotProduct(line.GetDirection(), normal);

        if (MathF::FAbs(directionDotNormal) <= MathF::GetZeroTolerance())
        {
            ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
        }
        else
        {
            NumericalValueSymbol sign = NumericalValueSymbol::Zero;
            if (MathF::GetZeroTolerance() < directionDotNormal)
            {
                sign = NumericalValueSymbol::Positive;
            }
            else if (directionDotNormal < MathF::GetZeroTolerance())
            {
                sign = NumericalValueSymbol::Negative;
                directionDotNormal = -directionDotNormal;
            }

            const Vector3F originCrossEdge2 = Vector3ToolsF::CrossProduct(lineOrigin, edge2);
            const float directionDotOriginCrossEdge2 = sign * Vector3ToolsF::DotProduct(line.GetDirection(), originCrossEdge2);
            if (0.0 <= directionDotOriginCrossEdge2)
            {
                const Vector3F edge1CrossOrigin = Vector3ToolsF::CrossProduct(edge1, lineOrigin);
                const float directionDotEdge1CrossOrigin = sign * Vector3ToolsF::DotProduct(line.GetDirection(), edge1CrossOrigin);

                if (0.0 <= directionDotEdge1CrossOrigin)
                {
                    if (directionDotNormal <= directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin)
                    {
                        ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Point);
                    }
                    else
                    {
                        ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
                    }
                }
                else
                {
                    ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
                }
            }
            else
            {
                ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Empty);
            }
        }
    }
}
