///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 13:39)

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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, CircleFit2Testing)

void Mathematics::CircleFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CircleFit2Testing::FitTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const uniform_int<> secondRandomDistribution(10, 50);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = secondRandomDistribution(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(firstRandomDistribution(generator), firstRandomDistribution(generator)));
        }

        const CircleFit2D firstCircleFit2(vertices, 1000, true);
        const CircleFit2D secondCircleFit2(vertices, 1000, false);

        const Circle2D firstCircle = firstCircleFit2.GetCircle();
        const Circle2D secondCircle = secondCircleFit2.GetCircle();

        for (int i = 0; i < size; ++i)
        {
            const double distance = Vector2ToolsD::Distance(vertices.at(i), firstCircle.GetCenter());

            ASSERT_TRUE(distance <= firstCircle.GetRadius() * 2.1);
            ASSERT_TRUE(distance <= secondCircle.GetRadius() * 2.1);
        }
    }
}
