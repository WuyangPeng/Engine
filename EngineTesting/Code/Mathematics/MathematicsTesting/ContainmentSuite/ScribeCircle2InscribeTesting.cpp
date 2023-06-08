///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 21:16)

#include "ScribeCircle2InscribeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Containment/ScribeCircle2InscribeDetail.h"
#include <random>

namespace Mathematics
{
    template class ScribeCircle2Inscribe<float>;
    template class ScribeCircle2Inscribe<double>;
}

Mathematics::ScribeCircle2InscribeTesting::ScribeCircle2InscribeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ScribeCircle2InscribeTesting)

void Mathematics::ScribeCircle2InscribeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ScribeCircle2InscribeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InscribeTest);
}

void Mathematics::ScribeCircle2InscribeTesting::InscribeTest()
{
    std::default_random_engine generator;
    const std::uniform_real<double> firstRandomDistribution(-100.0, 100.0);
    const std::uniform_int<> secondRandomDistribution(10, 50);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 v0(firstRandomDistribution(generator), firstRandomDistribution(generator));
        const Vector2 v1(firstRandomDistribution(generator), firstRandomDistribution(generator));
        const Vector2 v2(firstRandomDistribution(generator), firstRandomDistribution(generator));

        ScribeCircle2InscribeD scribeCircle2Inscribed(v0, v1, v2);

        if (scribeCircle2Inscribed.IsCircleConstructed())
        {
            const Circle2D circle = scribeCircle2Inscribed.GetCircle2();

            const Vector2 v0Diff = circle.GetCenter() - v0;
            const Vector2 v1Diff = circle.GetCenter() - v1;
            const Vector2 v2Diff = circle.GetCenter() - v2;
            Vector2 v10 = v1 - v0;
            Vector2 v02 = v0 - v2;
            Vector2 v21 = v2 - v1;

            v10.Normalize();
            v02.Normalize();
            v21.Normalize();

            const double param10 = Vector2ToolsD::DotProduct(v10, v0Diff);
            const double param02 = Vector2ToolsD::DotProduct(v02, v2Diff);
            const double param21 = Vector2ToolsD::DotProduct(v21, v1Diff);

            ASSERT_APPROXIMATE(Vector2ToolsD::GetLength(v0 + param10 * v10 - circle.GetCenter()),
                               circle.GetRadius(), 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::GetLength(v2 + param02 * v02 - circle.GetCenter()),
                               circle.GetRadius(), 1e-10);
            ASSERT_APPROXIMATE(Vector2ToolsD::GetLength(v1 + param21 * v21 - circle.GetCenter()),
                               circle.GetRadius(), 1e-10);
        }
    }
}
