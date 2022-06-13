///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:16)

#include "AxesAlignBoundingBox3DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class AxesAlignBoundingBox3<float>;
    template class AxesAlignBoundingBox3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AxesAlignBoundingBox3DTesting)

void Mathematics::AxesAlignBoundingBox3DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IntersectionTest);
}

void Mathematics::AxesAlignBoundingBox3DTesting::ConstructionTest()
{
    const Vector3F firstVector(3.0f, 7.0f, 6.0f);
    const Vector3F secondVector(5.0f, 11.0f, 17.0f);

    const AxesAlignBoundingBox3F firstAABB(firstVector, secondVector);

    ASSERT_TRUE(Vector3ToolsF::Approximate(firstAABB.GetMaxPoint(), Vector3F(5.0f, 11.0f, 17.0f)));
    ASSERT_TRUE(Vector3ToolsF::Approximate(firstAABB.GetMinPoint(), Vector3F(3.0f, 7.0f, 6.0f)));

    const AxesAlignBoundingBox3D secondAABB(firstAABB);

    ASSERT_TRUE(Vector3ToolsD::Approximate(secondAABB.GetMaxPoint(), Vector3D(5.0, 11.0, 17.0)));
    ASSERT_TRUE(Vector3ToolsD::Approximate(secondAABB.GetMinPoint(), Vector3D(3.0, 7.0, 6.0)));

    const AxesAlignBoundingBox3F thirdAABB(3.0f, 5.0f, 1.0f, 7.0f, 4.0f, 16.0f);

    ASSERT_TRUE(Vector3ToolsF::Approximate(thirdAABB.GetMaxPoint(), Vector3F(5.0f, 7.0f, 16.0f)));
    ASSERT_TRUE(Vector3ToolsF::Approximate(thirdAABB.GetMinPoint(), Vector3F(3.0f, 1.0f, 4.0f)));
}

void Mathematics::AxesAlignBoundingBox3DTesting::AccessTest()
{
    default_random_engine randomEngine{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3F firstVector(firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine));

        const uniform_real<float> secondRandomDistribution(firstVector[0], 100.0f);
        const uniform_real<float> thirdRandomDistribution(firstVector[1], 100.0f);
        const uniform_real<float> fourthRandomDistribution(firstVector[2], 100.0f);

        Vector3F secondVector(secondRandomDistribution(randomEngine), thirdRandomDistribution(randomEngine), fourthRandomDistribution(randomEngine));

        const AxesAlignBoundingBox3F firstAABB(firstVector, secondVector);

        ASSERT_TRUE(Vector3ToolsF::Approximate(firstAABB.GetMaxPoint(), secondVector));
        ASSERT_TRUE(Vector3ToolsF::Approximate(firstAABB.GetMinPoint(), firstVector));
        ASSERT_TRUE(Vector3ToolsF::Approximate(firstAABB.GetCenter(), (firstVector + secondVector) / 2.0f));

        ASSERT_APPROXIMATE(firstAABB.GetExtentX(), (secondVector[0] - firstVector[0]) / 2.0f, 1e-8f);

        ASSERT_APPROXIMATE(firstAABB.GetExtentY(), (secondVector[1] - firstVector[1]) / 2.0f, 1e-8f);

        ASSERT_APPROXIMATE(firstAABB.GetExtentZ(), (secondVector[2] - firstVector[2]) / 2.0f, 1e-8f);
    }
}

void Mathematics::AxesAlignBoundingBox3DTesting::IntersectionTest()
{
    default_random_engine randomEngine{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3F firstVector(firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine));

        const uniform_real<float> secondRandomDistribution(firstVector[0], 100.0f);
        const uniform_real<float> thirdRandomDistribution(firstVector[1], 100.0f);
        const uniform_real<float> fourthRandomDistribution(firstVector[2], 100.0f);

        Vector3F secondVector(secondRandomDistribution(randomEngine), thirdRandomDistribution(randomEngine), fourthRandomDistribution(randomEngine));

        Vector3F thirdVector(firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine));

        const uniform_real<float> fifthRandomDistribution(thirdVector[0], 100.0f);
        const uniform_real<float> sixthRandomDistribution(thirdVector[1], 100.0f);
        const uniform_real<float> seventhRandomDistribution(thirdVector[2], 100.0f);

        Vector3F fourthVector(fifthRandomDistribution(randomEngine), sixthRandomDistribution(randomEngine), seventhRandomDistribution(randomEngine));

        const AxesAlignBoundingBox3F firstAABB(firstVector, secondVector);
        const AxesAlignBoundingBox3F secondAABB(thirdVector, fourthVector);

        if ((firstVector[0] <= thirdVector[0] && thirdVector[0] <= secondVector[0]) || (thirdVector[0] <= firstVector[0] && firstVector[0] <= fourthVector[0]))
        {
            ASSERT_TRUE(HasXOverlap(firstAABB, secondAABB));
        }
        else
        {
            ASSERT_FALSE(HasXOverlap(firstAABB, secondAABB));
        }

        if ((firstVector[1] <= thirdVector[1] && thirdVector[1] <= secondVector[1]) || (thirdVector[1] <= firstVector[1] && firstVector[1] <= fourthVector[1]))
        {
            ASSERT_TRUE(HasYOverlap(firstAABB, secondAABB));
        }
        else
        {
            ASSERT_FALSE(HasYOverlap(firstAABB, secondAABB));
        }

        if ((firstVector[2] <= thirdVector[2] && thirdVector[2] <= secondVector[2]) || (thirdVector[2] <= firstVector[2] && firstVector[2] <= fourthVector[2]))
        {
            ASSERT_TRUE(HasZOverlap(firstAABB, secondAABB));
        }
        else
        {
            ASSERT_FALSE(HasZOverlap(firstAABB, secondAABB));
        }

        if (HasXOverlap(firstAABB, secondAABB) && HasYOverlap(firstAABB, secondAABB) && HasZOverlap(firstAABB, secondAABB))
        {
            ASSERT_TRUE(IsIntersection(firstAABB, secondAABB));
        }
        else
        {
            ASSERT_FALSE(IsIntersection(firstAABB, secondAABB));
        }

        if (IsIntersection(firstAABB, secondAABB))
        {
            const AxesAlignBoundingBox3F thirdAABB = FindIntersection(firstAABB, secondAABB);

            ASSERT_TRUE(firstAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= firstAABB.GetMaxPoint()[0]);
            ASSERT_TRUE(firstAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= firstAABB.GetMaxPoint()[1]);
            ASSERT_TRUE(firstAABB.GetMinPoint()[2] <= thirdAABB.GetMinPoint()[2]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[2] <= firstAABB.GetMaxPoint()[2]);

            ASSERT_TRUE(secondAABB.GetMinPoint()[0] <= thirdAABB.GetMinPoint()[0]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[0] <= secondAABB.GetMaxPoint()[0]);
            ASSERT_TRUE(secondAABB.GetMinPoint()[1] <= thirdAABB.GetMinPoint()[1]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[1] <= secondAABB.GetMaxPoint()[1]);
            ASSERT_TRUE(secondAABB.GetMinPoint()[2] <= thirdAABB.GetMinPoint()[2]);
            ASSERT_TRUE(thirdAABB.GetMaxPoint()[2] <= secondAABB.GetMaxPoint()[2]);
        }
    }
}
