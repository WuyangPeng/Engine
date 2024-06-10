///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:11)

#include "Box2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

#include <random>

namespace Mathematics
{
    template class Box2<float>;
    template class Box2<double>;
}

Mathematics::Box2Testing::Box2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Box2Testing)

void Mathematics::Box2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Box2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box2Testing::BoxTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));

        const Vector2 firstAxis(randomDistribution0(generator), randomDistribution0(generator));

        const Vector2 secondAxis(randomDistribution0(generator), randomDistribution0(generator));

        auto firstExtent = Vector2ToolsD::GetLength(firstAxis);
        auto secondExtent = Vector2ToolsD::GetLength(secondAxis);

        Vector2 thirdAxis(firstAxis);
        Vector2 fourthAxis(secondAxis);

        thirdAxis.Normalize();
        fourthAxis.Normalize();

        thirdAxis.Normalize();
        fourthAxis.Normalize();

        const Box2D box(center, thirdAxis, fourthAxis, firstExtent, secondExtent);

        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetCenter(), center));
        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetAxis0(), thirdAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetAxis1(), fourthAxis));
        ASSERT_APPROXIMATE(box.GetExtent0(), firstExtent, 1e-10);
        ASSERT_APPROXIMATE(box.GetExtent1(), secondExtent, 1e-10);

        auto vertex = box.ComputeVertices();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(0), center - firstAxis - secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(1), center + firstAxis - secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(2), center + firstAxis + secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex.at(3), center - firstAxis + secondAxis));
    }
}
