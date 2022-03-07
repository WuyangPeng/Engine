// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:54)

#include "IntersectorLine3Triangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorLine3Triangle3Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticFindIntersectorLine3Triangle3<float>;
    template class StaticFindIntersectorLine3Triangle3<double>;
    template class StaticTestIntersectorLine3Triangle3<float>;
    template class StaticTestIntersectorLine3Triangle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntersectorLine3Triangle3Testing)

void Mathematics::IntersectorLine3Triangle3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FindTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectTest);
}
#include SYSTEM_WARNING_DISABLE(26496)
void Mathematics::IntersectorLine3Triangle3Testing ::FindTest()
{
    std::default_random_engine generator;
    std::uniform_real<double> randomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D origin(randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator));

        Vector3D direction(randomDistribution(generator),
                           randomDistribution(generator),
                           randomDistribution(generator));

        direction.Normalize();

        Line3D line(origin, direction);

        Vector3D firstPoint(randomDistribution(generator),
                            randomDistribution(generator),
                            randomDistribution(generator));

        Vector3D secondPoint(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        Vector3D thirdPoint(randomDistribution(generator),
                            randomDistribution(generator),
                            randomDistribution(generator));

        Triangle3D triangle(firstPoint, secondPoint, thirdPoint);

        StaticFindIntersectorLine3Triangle3<double> intersector(line, triangle);

        IntersectionType intersectionType = intersector.GetIntersectionType();

        if (intersectionType == IntersectionType::Point)
            ASSERT_TRUE(intersector.IsIntersection());
        else
            ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetLine().GetDirection(),
                                               direction, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetLine().GetOrigin(),
                                               origin, 1e-10));

        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(0),
                                               firstPoint, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(1),
                                               secondPoint, 1e-10));
        ASSERT_TRUE(Vector3ToolsD::Approximate(intersector.GetTriangle().GetVertex(2),
                                               thirdPoint, 1e-10));

        // ÷µ≤‚ ‘
        Vector3D lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
        Vector3D edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
        Vector3D edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
        Vector3D normal = Vector3ToolsD::CrossProduct(edge1, edge2);

        double directionDotNormal =
            Vector3ToolsD::DotProduct(line.GetDirection(), normal);

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

            Vector3D originCrossEdge2 =
                Vector3ToolsD::CrossProduct(lineOrigin, edge2);
            double directionDotOriginCrossEdge2 =
                sign * Vector3ToolsD::DotProduct(line.GetDirection(),
                                                 originCrossEdge2);
            if (0.0 <= directionDotOriginCrossEdge2)
            {
                Vector3D edge1CrossOrigin =
                    Vector3ToolsD::CrossProduct(edge1, lineOrigin);
                double directionDotEdge1CrossOrigin =
                    sign * Vector3ToolsD::DotProduct(line.GetDirection(),
                                                     edge1CrossOrigin);

                if (0.0 <= directionDotEdge1CrossOrigin)
                {
                    if (directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin <= directionDotNormal)
                    {
                        ASSERT_ENUM_EQUAL(intersectionType, IntersectionType::Point);
                        double originDotNormal =
                            -sign * Vector3ToolsD::DotProduct(lineOrigin, normal);

                        double lineParameter = originDotNormal / directionDotNormal;
                        double triangleBary1 = directionDotOriginCrossEdge2 / directionDotNormal;
                        double triangleBary2 = directionDotEdge1CrossOrigin / directionDotNormal;
                        double triangleBary0 =
                            1.0 - triangleBary1 - triangleBary2;

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

void Mathematics::IntersectorLine3Triangle3Testing ::IntersectTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> firstRandomDistribution(-100.0f, 100.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3F origin(firstRandomDistribution(generator),
                        firstRandomDistribution(generator),
                        firstRandomDistribution(generator));

        Vector3F direction(firstRandomDistribution(generator),
                           firstRandomDistribution(generator),
                           firstRandomDistribution(generator));

        direction.Normalize();

        Line3F line(origin, direction);

        Vector3F firstPoint(firstRandomDistribution(generator),
                            firstRandomDistribution(generator),
                            firstRandomDistribution(generator));

        Vector3F secondPoint(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector3F thirdPoint(firstRandomDistribution(generator),
                            firstRandomDistribution(generator),
                            firstRandomDistribution(generator));

        Triangle3F triangle(firstPoint, secondPoint, thirdPoint);

        StaticTestIntersectorLine3Triangle3<float> intersector(line, triangle);

        IntersectionType intersectionType = intersector.GetIntersectionType();

        if (intersectionType == IntersectionType::Point)
            ASSERT_TRUE(intersector.IsIntersection());
        else
            ASSERT_FALSE(intersector.IsIntersection());

        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetLine().GetDirection(),
                                               direction, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetLine().GetOrigin(),
                                               origin, 1e-8f));

        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(0),
                                               firstPoint, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(1),
                                               secondPoint, 1e-8f));
        ASSERT_TRUE(Vector3ToolsF::Approximate(intersector.GetTriangle().GetVertex(2),
                                               thirdPoint, 1e-8f));

        // ÷µ≤‚ ‘
        Vector3F lineOrigin = line.GetOrigin() - triangle.GetVertex(0);
        Vector3F edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
        Vector3F edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
        Vector3F normal = Vector3ToolsF::CrossProduct(edge1, edge2);

        float directionDotNormal =
            Vector3ToolsF::DotProduct(line.GetDirection(), normal);

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

            Vector3F originCrossEdge2 =
                Vector3ToolsF::CrossProduct(lineOrigin, edge2);
            float directionDotOriginCrossEdge2 =
                sign * Vector3ToolsF::DotProduct(line.GetDirection(),
                                                 originCrossEdge2);
            if (0.0 <= directionDotOriginCrossEdge2)
            {
                Vector3F edge1CrossOrigin =
                    Vector3ToolsF::CrossProduct(edge1, lineOrigin);
                float directionDotEdge1CrossOrigin =
                    sign * Vector3ToolsF::DotProduct(line.GetDirection(),
                                                     edge1CrossOrigin);

                if (0.0 <= directionDotEdge1CrossOrigin)
                {
                    if (directionDotNormal <=
                        directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin)
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
