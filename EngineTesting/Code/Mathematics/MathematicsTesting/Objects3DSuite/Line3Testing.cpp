///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:17)

#include "Line3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Line3Detail.h"

#include <random>

namespace Mathematics
{
    template class Line3<float>;
    template class Line3<double>;
}

Mathematics::Line3Testing::Line3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Line3Testing)

void Mathematics::Line3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Line3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LineTest);
}

void Mathematics::Line3Testing::LineTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D origin(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D direction(randomDistribution0(generator),
                           randomDistribution0(generator),
                           randomDistribution0(generator));

        direction.Normalize();

        const Line3D line(origin, direction);

        ASSERT_TRUE(Vector3ToolsD::Approximate(origin, line.GetOrigin()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(direction, line.GetDirection()));
    }
}
