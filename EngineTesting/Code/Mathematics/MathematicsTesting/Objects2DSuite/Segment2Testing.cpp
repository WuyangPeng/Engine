///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 14:23)

#include "Segment2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Segment2<float>;
    template class Segment2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Segment2Testing)

void Mathematics::Segment2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::Segment2Testing::SegmentTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 firstPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

        const Vector2 secondPoint(firstRandomDistribution(generator), firstRandomDistribution(generator));

        const Segment2D firstSegment(firstPoint, secondPoint);

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstPoint, firstSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondPoint, firstSegment.GetEndPoint()));

        const auto center = firstSegment.GetCenterPoint();
        const auto direction = firstSegment.GetDirection();
        const auto extent = firstSegment.GetExtent();

        const Segment2D secondSegment(extent, center, direction);

        ASSERT_TRUE(Vector2ToolsD::Approximate(firstPoint, secondSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(secondPoint, secondSegment.GetEndPoint()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(center, secondSegment.GetCenterPoint()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(direction, secondSegment.GetDirection()));
        ASSERT_APPROXIMATE(extent, secondSegment.GetExtent(), 1e-10);
    }
}
