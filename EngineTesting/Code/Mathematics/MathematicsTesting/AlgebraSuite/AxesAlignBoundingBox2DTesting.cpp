///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:30)

#include "AxesAlignBoundingBox2DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

#include <random>

namespace Mathematics
{
    template class AxesAlignBoundingBox2<float>;
    template class AxesAlignBoundingBox2<double>;
}

Mathematics::AxesAlignBoundingBox2DTesting::AxesAlignBoundingBox2DTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AxesAlignBoundingBox2DTesting)

void Mathematics::AxesAlignBoundingBox2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AxesAlignBoundingBox2DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTest);
}

void Mathematics::AxesAlignBoundingBox2DTesting::ConstructionTest()
{
    const Vector2F vector0{ 3.0f, 7.0f };
    const Vector2F vector1{ 5.0f, 11.0f };

    const AxesAlignBoundingBox2F aabb0{ vector0, vector1 };

    ASSERT_TRUE(Vector2ToolsF::Approximate(aabb0.GetMaxPoint(), Vector2F(5.0f, 11.0f)));
    ASSERT_TRUE(Vector2ToolsF::Approximate(aabb0.GetMinPoint(), Vector2F(3.0f, 7.0f)));

    const AxesAlignBoundingBox2D aabb1{ aabb0 };

    ASSERT_TRUE(Vector2ToolsD::Approximate(aabb1.GetMaxPoint(), Vector2(5.0, 11.0)));
    ASSERT_TRUE(Vector2ToolsD::Approximate(aabb1.GetMinPoint(), Vector2(3.0, 7.0)));

    const AxesAlignBoundingBox2F aabb2{ 3.0f, 5.0f, 1.0f, 7.0f };

    ASSERT_TRUE(Vector2ToolsF::Approximate(aabb2.GetMaxPoint(), Vector2F(5.0f, 7.0f)));
    ASSERT_TRUE(Vector2ToolsF::Approximate(aabb2.GetMinPoint(), Vector2F(3.0f, 1.0f)));
}

void Mathematics::AxesAlignBoundingBox2DTesting::AccessTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector2F vector0(randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution1(vector0[0], 100.0f);
        std::uniform_real_distribution<float> thirdRandomDistribution(vector0[1], 100.0f);

        Vector2F vector1(randomDistribution1(randomEngine), thirdRandomDistribution(randomEngine));

        const AxesAlignBoundingBox2F aabb0(vector0, vector1);

        ASSERT_TRUE(Vector2ToolsF::Approximate(aabb0.GetMaxPoint(), vector1));
        ASSERT_TRUE(Vector2ToolsF::Approximate(aabb0.GetMinPoint(), vector0));
        ASSERT_TRUE(Vector2ToolsF::Approximate(aabb0.GetCenter(), (vector0 + vector1) / 2.0f));

        ASSERT_APPROXIMATE(aabb0.GetExtentX(), (vector1[0] - vector0[0]) / 2.0f, 1e-8f);

        ASSERT_APPROXIMATE(aabb0.GetExtentY(), (vector1[1] - vector0[1]) / 2.0f, 1e-8f);
    }
}

void Mathematics::AxesAlignBoundingBox2DTesting::IntersectionTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector2F vector0(randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution1(vector0[0], 100.0f);
        std::uniform_real_distribution<float> randomDistribution2(vector0[1], 100.0f);

        Vector2F vector1(randomDistribution1(randomEngine), randomDistribution2(randomEngine));

        Vector2F vector2(randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution3(vector2[0], 100.0f);
        std::uniform_real_distribution<float> randomDistribution4(vector2[1], 100.0f);

        Vector2F vector3(randomDistribution3(randomEngine), randomDistribution4(randomEngine));

        const AxesAlignBoundingBox2F aabb0(vector0, vector1);
        const AxesAlignBoundingBox2F aabb1(vector2, vector3);

        if ((vector0[0] <= vector2[0] && vector2[0] <= vector1[0]) || (vector2[0] <= vector0[0] && vector0[0] <= vector3[0]))
        {
            ASSERT_TRUE(HasXOverlap(aabb0, aabb1));
        }
        else
        {
            ASSERT_FALSE(HasXOverlap(aabb0, aabb1));
        }

        if ((vector0[1] <= vector2[1] && vector2[1] <= vector1[1]) || (vector2[1] <= vector0[1] && vector0[1] <= vector3[1]))
        {
            ASSERT_TRUE(HasYOverlap(aabb0, aabb1));
        }
        else
        {
            ASSERT_FALSE(HasYOverlap(aabb0, aabb1));
        }

        if (HasXOverlap(aabb0, aabb1) && HasYOverlap(aabb0, aabb1))
        {
            ASSERT_TRUE(IsIntersection(aabb0, aabb1));
        }
        else
        {
            ASSERT_FALSE(IsIntersection(aabb0, aabb1));
        }

        if (IsIntersection(aabb0, aabb1))
        {
            const AxesAlignBoundingBox2F aabb2 = FindIntersection(aabb0, aabb1);

            ASSERT_TRUE(aabb0.GetMinPoint()[0] <= aabb2.GetMinPoint()[0]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[0] <= aabb0.GetMaxPoint()[0]);
            ASSERT_TRUE(aabb0.GetMinPoint()[1] <= aabb2.GetMinPoint()[1]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[1] <= aabb0.GetMaxPoint()[1]);

            ASSERT_TRUE(aabb1.GetMinPoint()[0] <= aabb2.GetMinPoint()[0]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[0] <= aabb1.GetMaxPoint()[0]);
            ASSERT_TRUE(aabb1.GetMinPoint()[1] <= aabb2.GetMinPoint()[1]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[1] <= aabb1.GetMaxPoint()[1]);
        }
    }
}
