// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 18:51)

#include "StaticFindIntersectorLine2Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Line2Detail.h"
#include <random>

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, StaticFindIntersectorLine2Line2Testing)

void Mathematics::StaticFindIntersectorLine2Line2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::StaticFindIntersectorLine2Line2Testing ::LineTest()
{
    std::default_random_engine generator;
    std::uniform_real<float> randomDistribution(-10.0f, 10.0f);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        FloatVector2D lhsOrigin(randomDistribution(generator),
                                randomDistribution(generator));
        FloatVector2D lhsDirection(randomDistribution(generator),
                                   randomDistribution(generator));
        FloatVector2D rhsOrigin(randomDistribution(generator),
                                randomDistribution(generator));
        FloatVector2D rhsDirection(randomDistribution(generator),
                                   randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        FloatStaticFindIntersectorLine2Line2 firstClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2(lhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        FloatStaticFindIntersectorLine2Line2 secondClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2(rhsOrigin, lhsDirection));

        ASSERT_ENUM_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondClassify);

        FloatStaticFindIntersectorLine2Line2 thirdClassify(FloatLine2(lhsOrigin, lhsDirection), FloatLine2(rhsOrigin, rhsDirection));

        ASSERT_ENUM_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        FloatVector2D firstPoint = thirdClassify.GetPoint() - thirdClassify.GetLhsLine().GetOrigin();
        FloatVector2D secondPoint = thirdClassify.GetPoint() - thirdClassify.GetRhsLine().GetOrigin();

        firstPoint.Normalize();
        secondPoint.Normalize();

        ASSERT_TRUE(FloatVector2DTools::Approximate(firstPoint, thirdClassify.GetLhsLine().GetDirection(), 1e-4f) ||
                    FloatVector2DTools::Approximate(-firstPoint, thirdClassify.GetLhsLine().GetDirection(), 1e-4f));

        ASSERT_TRUE(FloatVector2DTools::Approximate(secondPoint, thirdClassify.GetRhsLine().GetDirection(), 1e-4f) ||
                    FloatVector2DTools::Approximate(-secondPoint, thirdClassify.GetRhsLine().GetDirection(), 1e-4f));
    }
}

void Mathematics::StaticFindIntersectorLine2Line2Testing ::ExceptionTest(const StaticFindIntersectorLine2Line2<float>& intersector)
{
    [[maybe_unused]] auto value = intersector.GetPoint();
}
