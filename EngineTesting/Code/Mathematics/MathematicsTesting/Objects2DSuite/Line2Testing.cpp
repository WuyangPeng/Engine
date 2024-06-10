///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:12)

#include "Line2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

#include <random>

namespace Mathematics
{
    template class Line2<float>;
    template class Line2<double>;
}

Mathematics::Line2Testing::Line2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Line2Testing)

void Mathematics::Line2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Line2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::Line2Testing::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution0{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 origin(randomDistribution0(generator), randomDistribution0(generator));

        Vector2 direction(randomDistribution0(generator), randomDistribution0(generator));

        direction.Normalize();

        const Line2D line(origin, direction);

        ASSERT_TRUE(Vector2ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector2ToolsD::Approximate(direction, line.GetDirection()));
    }
}
