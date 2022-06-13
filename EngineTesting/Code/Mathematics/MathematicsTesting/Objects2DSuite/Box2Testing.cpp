///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 13:57)

#include "Box2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Box2<float>;
    template class Box2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Box2Testing)

void Mathematics::Box2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box2Testing::BoxTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 center(firstRandomDistribution(generator), firstRandomDistribution(generator));

        const Vector2 firstAxis(firstRandomDistribution(generator), firstRandomDistribution(generator));

        const Vector2 secondAxis(firstRandomDistribution(generator), firstRandomDistribution(generator));

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
