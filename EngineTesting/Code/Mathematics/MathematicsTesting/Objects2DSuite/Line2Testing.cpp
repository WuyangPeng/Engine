///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 19:27)

#include "Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Line2<float>;
    template class Line2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Line2Testing)

void Mathematics::Line2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::Line2Testing::LineTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector2 origin(firstRandomDistribution(generator), firstRandomDistribution(generator));

        Vector2 direction(firstRandomDistribution(generator), firstRandomDistribution(generator));

        direction.Normalize();

        const Line2D line(origin, direction);

        ASSERT_TRUE(Vector2ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(direction, line.GetDirection()));
    }
}
