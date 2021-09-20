// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 10:29)

#include "GaussPointsFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class GaussPointsFit3<float>;
    template class GaussPointsFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GaussPointsFit3Testing)

void Mathematics::GaussPointsFit3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GaussPointsFit3Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<DoubleVector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        GaussPointsFit3<double> gaussPointsFit2d(vertices);

        DoubleBox3 box = gaussPointsFit2d.GetBox3();

        for (int i = 0; i < size; ++i)
        {
            double distanceSquared = DoubleVector3DTools::DistanceSquared(box.GetCenter(), vertices[i]);
            double maxDistanceSquared = box.GetExtent0() * box.GetExtent0() + box.GetExtent1() * box.GetExtent1() + box.GetExtent2() * box.GetExtent2();

            ASSERT_TRUE(distanceSquared <= maxDistanceSquared);
        }
    }
}
