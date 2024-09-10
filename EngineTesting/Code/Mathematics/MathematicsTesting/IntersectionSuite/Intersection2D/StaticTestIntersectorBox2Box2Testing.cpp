///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:53)

#include "StaticTestIntersectorBox2Box2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Intersection/Intersection2D/StaticTestIntersectorBox2Box2Detail.h"

#include <random>

namespace Mathematics
{
    template class StaticTestIntersectorBox2Box2<float>;
    template class StaticTestIntersectorBox2Box2<double>;
}

Mathematics::StaticTestIntersectorBox2Box2Testing::StaticTestIntersectorBox2Box2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, StaticTestIntersectorBox2Box2Testing)

void Mathematics::StaticTestIntersectorBox2Box2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::StaticTestIntersectorBox2Box2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::StaticTestIntersectorBox2Box2Testing::BoxTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution(-100.0f, 100.0f);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2F lhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        const Vector2F rhsCenter(randomDistribution(generator),
                                 randomDistribution(generator));

        Vector2F lhsFirstAxis(randomDistribution(generator),
                              randomDistribution(generator));

        Vector2F rhsFirstAxis(randomDistribution(generator),
                              randomDistribution(generator));

        lhsFirstAxis.Normalize();
        rhsFirstAxis.Normalize();

        const float lhsFirstExtent = MathF::FAbs(randomDistribution(generator));
        const float rhsFirstExtent = MathF::FAbs(randomDistribution(generator));

        Vector2F lhsSecondAxis(randomDistribution(generator),
                               randomDistribution(generator));

        Vector2F rhsSecondAxis(randomDistribution(generator),
                               randomDistribution(generator));

        lhsSecondAxis.Normalize();
        rhsSecondAxis.Normalize();

        const float lhsSecondExtent = MathF::FAbs(randomDistribution(generator));
        const float rhsSecondExtent = MathF::FAbs(randomDistribution(generator));

        const Box2F lhsBox(lhsCenter, lhsFirstAxis, lhsSecondAxis, lhsFirstExtent, lhsSecondExtent);
        const Box2F rhsBox(rhsCenter, rhsFirstAxis, rhsSecondAxis, rhsFirstExtent, rhsSecondExtent);

        StaticTestIntersectorBox2Box2<float> intersector(lhsBox, rhsBox);

        const Vector2F boxCentersDifference = rhsCenter - lhsCenter;

        const float absA0DotB0 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, rhsFirstAxis));
        const float absA0DotB1 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, rhsSecondAxis));
        float absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(lhsFirstAxis, boxCentersDifference));

        if (lhsFirstExtent + rhsFirstExtent * absA0DotB0 + rhsSecondExtent * absA0DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        const float absA1DotB0 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, rhsFirstAxis));
        const float absA1DotB1 = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, rhsSecondAxis));
        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(lhsSecondAxis, boxCentersDifference));

        if (lhsSecondExtent + rhsFirstExtent * absA1DotB0 + rhsSecondExtent * absA1DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(rhsFirstAxis, boxCentersDifference));

        if (rhsFirstExtent + lhsFirstExtent * absA0DotB0 + lhsSecondExtent * absA1DotB0 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        absADotD = MathF::FAbs(Vector2ToolsF::DotProduct(rhsSecondAxis, boxCentersDifference));

        if (rhsSecondExtent + lhsFirstExtent * absA0DotB1 + lhsSecondExtent * absA1DotB1 < absADotD)
        {
            ASSERT_FALSE(intersector.IsIntersection());
            continue;
        }

        ASSERT_TRUE(intersector.IsIntersection());
    }
}
