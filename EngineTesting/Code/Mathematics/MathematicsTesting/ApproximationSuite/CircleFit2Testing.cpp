// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 16:18)

#include "CircleFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/CircleFit2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class CircleFit2<float>;
    template class CircleFit2<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, CircleFit2Testing)

void Mathematics::CircleFit2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CircleFit2Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        CircleFit2D firstCircleFit2(vertices, 1000, true);
        CircleFit2D secondCircleFit2(vertices, 1000, false);

        Circle2D firstCircle = firstCircleFit2.GetCircle();
        Circle2D secondCircle = secondCircleFit2.GetCircle();

        for (int i = 0; i < size; ++i)
        {
            double distance = Vector2ToolsD::Distance(vertices[i], firstCircle.GetCenter());

            ASSERT_TRUE(distance <= firstCircle.GetRadius() * 2.1);
            ASSERT_TRUE(distance <= secondCircle.GetRadius() * 2.1);
        }
    }
}
