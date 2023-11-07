///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:11)

#include "Circle2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

#include <random>

namespace Mathematics
{
    template class Circle2<float>;
    template class Circle2<double>;
}

Mathematics::Circle2Testing::Circle2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Circle2Testing)

void Mathematics::Circle2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Circle2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CircleTest);
}

void Mathematics::Circle2Testing::CircleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 center(randomDistribution0(generator), randomDistribution0(generator));

        const double radius(MathD::FAbs(randomDistribution0(generator)));

        const Circle2D circle(center, radius);

        ASSERT_TRUE(Vector2ToolsD::Approximate(center, circle.GetCenter()));
        ASSERT_APPROXIMATE(radius, circle.GetRadius(), 1e-10);
    }
}
