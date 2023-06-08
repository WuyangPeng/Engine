///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 21:16)

#include "ScribeCircle2CircumscribeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Containment/ScribeCircle2CircumscribeDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

namespace Mathematics
{
    template class ScribeCircle2Circumscribe<float>;
    template class ScribeCircle2Circumscribe<double>;
}

Mathematics::ScribeCircle2CircumscribeTesting::ScribeCircle2CircumscribeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ScribeCircle2CircumscribeTesting)

void Mathematics::ScribeCircle2CircumscribeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ScribeCircle2CircumscribeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CircumscribeTest);
}

void Mathematics::ScribeCircle2CircumscribeTesting::CircumscribeTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 v0(firstRandomDistribution(generator), firstRandomDistribution(generator));
        const Vector2 v1(firstRandomDistribution(generator), firstRandomDistribution(generator));
        const Vector2 v2(firstRandomDistribution(generator), firstRandomDistribution(generator));

        ScribeCircle2CircumscribeD scribeCircle2Circumscribe(v0, v1, v2);

        if (scribeCircle2Circumscribe.IsCircleConstructed())
        {
            const Circle2D circle = scribeCircle2Circumscribe.GetCircle2();

            ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(), v0), circle.GetRadius(), 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(), v1), circle.GetRadius(), 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::Distance(circle.GetCenter(), v2), circle.GetRadius(), 1e-10);
        }
    }
}
