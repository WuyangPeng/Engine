// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 10:28)

#include "GaussPointsFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class GaussPointsFit2<float>;
    template class GaussPointsFit2<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GaussPointsFit2Testing)

void Mathematics::GaussPointsFit2Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GaussPointsFit2Testing ::FitTest()
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

        GaussPointsFit2D gaussPointsFit2d(vertices);

        Box2D box = gaussPointsFit2d.GetBox2();

        for (int i = 0; i < size; ++i)
        {
            double distanceSquared = Vector2ToolsD::DistanceSquared(box.GetCenter(), vertices[i]);
            double maxDistanceSquared = box.GetExtent0() * box.GetExtent0() + box.GetExtent1() * box.GetExtent1();

            ASSERT_TRUE(distanceSquared <= maxDistanceSquared);
        }
    }
}
