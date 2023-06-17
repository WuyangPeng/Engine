///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:11)

#include "Arc2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

#include <random>

namespace Mathematics
{
    template class Arc2<float>;
    template class Arc2<double>;
}

Mathematics::Arc2Testing::Arc2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Arc2Testing)

void Mathematics::Arc2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Arc2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Arc2Test);
}

void Mathematics::Arc2Testing::Arc2Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };
    const std::uniform_real<double> randomDistribution1{ 0.0, MathD::GetTwoPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector2 center(randomDistribution0(generator), randomDistribution0(generator));

        const double radius(MathD::FAbs(randomDistribution0(generator)));

        const double firstAngle(randomDistribution1(generator));

        const Vector2 end0(center[0] + radius * MathD::Cos(firstAngle), center[1] + radius * MathD::Sin(firstAngle));

        const std::uniform_real<double> thirdRandomDistribution(firstAngle, MathD::GetTwoPI());

        const double secondAngle(thirdRandomDistribution(generator));

        const Vector2 end1(center[0] + radius * MathD::Cos(secondAngle), center[1] + radius * MathD::Sin(secondAngle));

        const Arc2D arc2(center, radius, end0, end1);

        ASSERT_TRUE(Vector2ToolsD::Approximate(center, arc2.GetCenter()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(end0, arc2.GetEnd0()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(end1, arc2.GetEnd1()));
        ASSERT_APPROXIMATE(arc2.GetRadius(), radius, 1e-10);

        const double thirdAngle(randomDistribution1(generator));

        const Vector2 point(center[0] + radius * MathD::Cos(thirdAngle), center[1] + radius * MathD::Sin(thirdAngle));

        if (firstAngle <= thirdAngle && thirdAngle <= secondAngle)
        {
            ASSERT_TRUE(arc2.Contains(point));
        }
        else
        {
            ASSERT_FALSE(arc2.Contains(point));
        }
    }
}
