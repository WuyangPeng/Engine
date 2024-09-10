///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:52)

#include "StaticFindIntersectorLine2Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorLine2Line2Detail.h"

#include <random>

Mathematics::StaticFindIntersectorLine2Line2Testing::StaticFindIntersectorLine2Line2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticFindIntersectorLine2Line2Testing)

void Mathematics::StaticFindIntersectorLine2Line2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticFindIntersectorLine2Line2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::StaticFindIntersectorLine2Line2Testing::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-10.0f, 10.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F lhsOrigin(randomDistribution(generator),
                                 randomDistribution(generator));
        Vector2F lhsDirection(randomDistribution(generator),
                              randomDistribution(generator));
        const Vector2F rhsOrigin(randomDistribution(generator),
                                 randomDistribution(generator));
        Vector2F rhsDirection(randomDistribution(generator),
                              randomDistribution(generator));

        lhsDirection.Normalize();
        rhsDirection.Normalize();

        StaticFindIntersectorLine2Line2<float> firstClassify(Line2F(lhsOrigin, lhsDirection), Line2F(lhsOrigin, lhsDirection));

        ASSERT_EQUAL(firstClassify.GetIntersectionType(), IntersectionType::Line);
        ASSERT_EQUAL(firstClassify.GetQuantity(), INT_MAX);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, firstClassify);

        StaticFindIntersectorLine2Line2<float> secondClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, lhsDirection));

        ASSERT_EQUAL(secondClassify.GetIntersectionType(), IntersectionType::Empty);
        ASSERT_EQUAL(secondClassify.GetQuantity(), 0);
        ASSERT_THROW_EXCEPTION_1(ExceptionTest, secondClassify);

        StaticFindIntersectorLine2Line2<float> thirdClassify(Line2F(lhsOrigin, lhsDirection), Line2F(rhsOrigin, rhsDirection));

        ASSERT_EQUAL(thirdClassify.GetIntersectionType(), IntersectionType::Point);
        ASSERT_EQUAL(thirdClassify.GetQuantity(), 1);

        Vector2F point0 = thirdClassify.GetPoint() - thirdClassify.GetLhsLine().GetOrigin();
        Vector2F point1 = thirdClassify.GetPoint() - thirdClassify.GetRhsLine().GetOrigin();

        point0.Normalize();
        point1.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(point0, thirdClassify.GetLhsLine().GetDirection(), 1e-4f) ||
                    Vector2ToolsF::Approximate(-point0, thirdClassify.GetLhsLine().GetDirection(), 1e-4f));

        ASSERT_TRUE(Vector2ToolsF::Approximate(point1, thirdClassify.GetRhsLine().GetDirection(), 1e-4f) ||
                    Vector2ToolsF::Approximate(-point1, thirdClassify.GetRhsLine().GetDirection(), 1e-4f));
    }
}

void Mathematics::StaticFindIntersectorLine2Line2Testing::ExceptionTest(const StaticFindIntersectorLine2Line2<float>& intersector)
{
    MAYBE_UNUSED const auto value = intersector.GetPoint();
}
