// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 14:36)

#include "SphereFit3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/SphereFit3Detail.h"

#include <random>
#include "Mathematics/Algebra/Vector3Tools.h"

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

namespace Mathematics
{
    template class SphereFit3<float>;
    template class SphereFit3<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, SphereFit3Testing)

void Mathematics::SphereFit3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::SphereFit3Testing ::FitTest()
{
    default_random_engine generator;
    uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector3D> vertices;
        int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        SphereFit3D firstSphereFit3(vertices, 2000, true);
        SphereFit3D secondSphereFit3(vertices, 2000, false);

        Sphere3D firstCircle = firstSphereFit3.GetSphere();
        Sphere3D secondCircle = secondSphereFit3.GetSphere();

        for (int i = 0; i < size; ++i)
        {
            double distance = Vector3ToolsD::Distance(vertices[i], firstCircle.GetCenter());

            ASSERT_TRUE(distance <= firstCircle.GetRadius() * 2.1);
            ASSERT_TRUE(distance <= secondCircle.GetRadius() * 2.1);
        }
    }
}
