///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:32)

#include "AxesAlignBoundingBox3DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>

namespace Mathematics
{
    template class AxesAlignBoundingBox3<float>;
    template class AxesAlignBoundingBox3<double>;
}

Mathematics::AxesAlignBoundingBox3DTesting::AxesAlignBoundingBox3DTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AxesAlignBoundingBox3DTesting)

void Mathematics::AxesAlignBoundingBox3DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AxesAlignBoundingBox3DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTest);
}

void Mathematics::AxesAlignBoundingBox3DTesting::ConstructionTest()
{
    const Vector3F vector0(3.0f, 7.0f, 6.0f);
    const Vector3F vector1(5.0f, 11.0f, 17.0f);

    const AxesAlignBoundingBox3F aabb0(vector0, vector1);

    ASSERT_TRUE(Vector3ToolsF::Approximate(aabb0.GetMaxPoint(), Vector3F(5.0f, 11.0f, 17.0f)));
    ASSERT_TRUE(Vector3ToolsF::Approximate(aabb0.GetMinPoint(), Vector3F(3.0f, 7.0f, 6.0f)));

    const AxesAlignBoundingBox3D aabb1(aabb0);

    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb1.GetMaxPoint(), Vector3D(5.0, 11.0, 17.0)));
    ASSERT_TRUE(Vector3ToolsD::Approximate(aabb1.GetMinPoint(), Vector3D(3.0, 7.0, 6.0)));

    const AxesAlignBoundingBox3F aabb2(3.0f, 5.0f, 1.0f, 7.0f, 4.0f, 16.0f);

    ASSERT_TRUE(Vector3ToolsF::Approximate(aabb2.GetMaxPoint(), Vector3F(5.0f, 7.0f, 16.0f)));
    ASSERT_TRUE(Vector3ToolsF::Approximate(aabb2.GetMinPoint(), Vector3F(3.0f, 1.0f, 4.0f)));
}

void Mathematics::AxesAlignBoundingBox3DTesting::AccessTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector3F vector0(randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution1(vector0[0], 100.0f);
        std::uniform_real_distribution<float> randomDistribution2(vector0[1], 100.0f);
        std::uniform_real_distribution<float> randomDistribution3(vector0[2], 100.0f);

        Vector3F vector1(randomDistribution1(randomEngine), randomDistribution2(randomEngine), randomDistribution3(randomEngine));

        const AxesAlignBoundingBox3F aabb0(vector0, vector1);

        ASSERT_TRUE(Vector3ToolsF::Approximate(aabb0.GetMaxPoint(), vector1));
        ASSERT_TRUE(Vector3ToolsF::Approximate(aabb0.GetMinPoint(), vector0));
        ASSERT_TRUE(Vector3ToolsF::Approximate(aabb0.GetCenter(), (vector0 + vector1) / 2.0f));

        ASSERT_APPROXIMATE(aabb0.GetExtentX(), (vector1[0] - vector0[0]) / 2.0f, 1e-8f);

        ASSERT_APPROXIMATE(aabb0.GetExtentY(), (vector1[1] - vector0[1]) / 2.0f, 1e-8f);

        ASSERT_APPROXIMATE(aabb0.GetExtentZ(), (vector1[2] - vector0[2]) / 2.0f, 1e-8f);
    }
}

void Mathematics::AxesAlignBoundingBox3DTesting::IntersectionTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Vector3F vector0(randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution1(vector0[0], 100.0f);
        std::uniform_real_distribution<float> randomDistribution2(vector0[1], 100.0f);
        std::uniform_real_distribution<float> randomDistribution3(vector0[2], 100.0f);

        Vector3F vector1(randomDistribution1(randomEngine), randomDistribution2(randomEngine), randomDistribution3(randomEngine));

        Vector3F vector2(randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine));

        std::uniform_real_distribution<float> randomDistribution4(vector2[0], 100.0f);
        std::uniform_real_distribution<float> randomDistribution5(vector2[1], 100.0f);
        std::uniform_real_distribution<float> randomDistribution6(vector2[2], 100.0f);

        Vector3F vector3(randomDistribution4(randomEngine), randomDistribution5(randomEngine), randomDistribution6(randomEngine));

        const AxesAlignBoundingBox3F aabb0(vector0, vector1);
        const AxesAlignBoundingBox3F aabb1(vector2, vector3);

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

        if ((vector0[2] <= vector2[2] && vector2[2] <= vector1[2]) || (vector2[2] <= vector0[2] && vector0[2] <= vector3[2]))
        {
            ASSERT_TRUE(HasZOverlap(aabb0, aabb1));
        }
        else
        {
            ASSERT_FALSE(HasZOverlap(aabb0, aabb1));
        }

        if (HasXOverlap(aabb0, aabb1) && HasYOverlap(aabb0, aabb1) && HasZOverlap(aabb0, aabb1))
        {
            ASSERT_TRUE(IsIntersection(aabb0, aabb1));
        }
        else
        {
            ASSERT_FALSE(IsIntersection(aabb0, aabb1));
        }

        if (IsIntersection(aabb0, aabb1))
        {
            const AxesAlignBoundingBox3F aabb2 = FindIntersection(aabb0, aabb1);

            ASSERT_TRUE(aabb0.GetMinPoint()[0] <= aabb2.GetMinPoint()[0]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[0] <= aabb0.GetMaxPoint()[0]);
            ASSERT_TRUE(aabb0.GetMinPoint()[1] <= aabb2.GetMinPoint()[1]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[1] <= aabb0.GetMaxPoint()[1]);
            ASSERT_TRUE(aabb0.GetMinPoint()[2] <= aabb2.GetMinPoint()[2]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[2] <= aabb0.GetMaxPoint()[2]);

            ASSERT_TRUE(aabb1.GetMinPoint()[0] <= aabb2.GetMinPoint()[0]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[0] <= aabb1.GetMaxPoint()[0]);
            ASSERT_TRUE(aabb1.GetMinPoint()[1] <= aabb2.GetMinPoint()[1]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[1] <= aabb1.GetMaxPoint()[1]);
            ASSERT_TRUE(aabb1.GetMinPoint()[2] <= aabb2.GetMinPoint()[2]);
            ASSERT_TRUE(aabb2.GetMaxPoint()[2] <= aabb1.GetMaxPoint()[2]);
        }
    }
}
