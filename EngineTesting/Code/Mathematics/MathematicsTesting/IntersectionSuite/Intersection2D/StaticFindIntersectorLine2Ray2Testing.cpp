// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:51)

#include "StaticFindIntersectorLine2Ray2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Ray2Detail.h"

#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorLine2Classify.h"
#include <random>

#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Ray2Testing)

void Mathematics::StaticFindIntersectorLine2Ray2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RayTest);
}

void Mathematics::StaticFindIntersectorLine2Ray2Testing ::RayTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2F lhsOrigin(randomDistribution(generator),
                           randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator),
                              randomDistribution(generator));
        Vector2F rhsOrigin(randomDistribution(generator),
                           randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator),
                              randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        StaticFindIntersectorLine2Ray2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Ray2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Ray2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin, -lhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Ray2<float> fourthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin + lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fourthClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(fourthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Ray2<float> fifthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(lhsOrigin - lhsDirection, -lhsDirection));

        ASSERT_ENUM_EQUAL(fifthClassify.GetIntersectionType(), IntersectionType::Ray);
        ASSERT_EQUAL(fifthClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Ray2<float> sixthClassify(Line2F(lhsOrigin, lhsDirection), Ray2F(rhsOrigin, rhsDirection));

        StaticTestIntersectorLine2Classify<float> seventhClassify(lhsOrigin, lhsDirection, rhsOrigin, rhsDirection,
                                                                  true);

        if (0.0f <= seventhClassify.GetParameter1())
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Point);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 1);

            Vector2F firstPoint = sixthClassify.GetPoint() - lhsOrigin;
            Vector2F secondPoint = sixthClassify.GetPoint() - rhsOrigin;

            firstPoint.Normalize();
            secondPoint.Normalize();

            ASSERT_TRUE(Vector2ToolsF::Approximate(firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-firstPoint, sixthClassify.GetLine().GetDirection(), 1e-4f));

            ASSERT_TRUE(Vector2ToolsF::Approximate(secondPoint, sixthClassify.GetRay().GetDirection(), 1e-4f) ||
                        Vector2ToolsF::Approximate(-secondPoint, sixthClassify.GetRay().GetDirection(), 1e-4f));
        }
        else
        {
            ASSERT_ENUM_EQUAL(sixthClassify.GetIntersectionType(), IntersectionType::Empty);
            ASSERT_EQUAL(sixthClassify.GetQuantity(), 0);
            ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);
        }
    }
}

void Mathematics::StaticFindIntersectorLine2Ray2Testing ::ExceptionTest(const StaticFindIntersectorLine2Ray2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetPoint();
}
