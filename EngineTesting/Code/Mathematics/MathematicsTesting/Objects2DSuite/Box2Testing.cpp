// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 14:05)

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Box2Testing)

void Mathematics::Box2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoxTest);
}

void Mathematics::Box2Testing ::BoxTest()
{
    default_random_engine generator{};
    uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 center(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2 firstAxis(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2 secondAxis(firstRandomDistribution(generator), firstRandomDistribution(generator));

        double firstExtent = Vector2ToolsD::GetLength(firstAxis);
        double secondExtent = Vector2ToolsD::GetLength(secondAxis);

        Vector2 thirdAxis(firstAxis);
        Vector2 fourthAxis(secondAxis);

        thirdAxis.Normalize();
        fourthAxis.Normalize();

        Box2D box(center, thirdAxis, fourthAxis, firstExtent, secondExtent);

        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetCenter(), center));
        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetAxis0(), thirdAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(box.GetAxis1(), fourthAxis));
        ASSERT_APPROXIMATE(box.GetExtent0(), firstExtent, 1e-10);
        ASSERT_APPROXIMATE(box.GetExtent1(), secondExtent, 1e-10);

        vector<Vector2D> vertex = box.ComputeVertices();

        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex[0], center - firstAxis - secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex[1], center + firstAxis - secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex[2], center + firstAxis + secondAxis));
        ASSERT_TRUE(Vector2ToolsD::Approximate(vertex[3], center - firstAxis + secondAxis));
    }
}
