///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 13:52)

#include "Arc2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Arc2<float>;
    template class Arc2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Arc2Testing)

void Mathematics::Arc2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Arc2Test);
}

void Mathematics::Arc2Testing::Arc2Test()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };
    const uniform_real<double> secondRandomDistribution{ 0.0, MathD::GetTwoPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector2 center(firstRandomDistribution(generator), firstRandomDistribution(generator));

        const double radius(MathD::FAbs(firstRandomDistribution(generator)));

        const double firstAngle(secondRandomDistribution(generator));

        const Vector2 end0(center[0] + radius * MathD::Cos(firstAngle), center[1] + radius * MathD::Sin(firstAngle));

        const uniform_real<double> thirdRandomDistribution(firstAngle, MathD::GetTwoPI());

        const double secondAngle(thirdRandomDistribution(generator));

        const Vector2 end1(center[0] + radius * MathD::Cos(secondAngle), center[1] + radius * MathD::Sin(secondAngle));

        const Arc2D arc2(center, radius, end0, end1);

        ASSERT_TRUE(Vector2ToolsD::Approximate(center, arc2.GetCenter()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(end0, arc2.GetEnd0()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(end1, arc2.GetEnd1()));
        ASSERT_APPROXIMATE(arc2.GetRadius(), radius, 1e-10);

        const double thirdAngle(secondRandomDistribution(generator));

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
