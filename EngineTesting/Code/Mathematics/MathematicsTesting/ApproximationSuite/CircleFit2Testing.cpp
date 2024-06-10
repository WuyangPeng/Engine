///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:53)

#include "CircleFit2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/CircleFit2Detail.h"

#include <random>

namespace Mathematics
{
    template class CircleFit2<float>;
    template class CircleFit2<double>;
}

Mathematics::CircleFit2Testing::CircleFit2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, CircleFit2Testing)

void Mathematics::CircleFit2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::CircleFit2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::CircleFit2Testing::FitTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);
    std::uniform_int_distribution<> randomDistribution1(10, 20);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<Vector2D> vertices;
        const int size = randomDistribution1(generator);

        for (int i = 0; i < size; ++i)
        {
            vertices.push_back(Vector2(randomDistribution0(generator), randomDistribution0(generator)));
        }

        const CircleFit2D firstCircleFit2(vertices, 10000, true);
        const CircleFit2D secondCircleFit2(vertices, 10000, false);

        const Circle2D firstCircle = firstCircleFit2.GetCircle();
        const Circle2D secondCircle = secondCircleFit2.GetCircle();

        for (int i = 0; i < size; ++i)
        {
            const double distance = Vector2ToolsD::Distance(vertices.at(i), firstCircle.GetCenter());

            ASSERT_LESS_EQUAL(distance, firstCircle.GetRadius() * 2.2);
            ASSERT_LESS_EQUAL(distance, secondCircle.GetRadius() * 2.2);
        }
    }
}
