///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:20)

#include "Segment3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

#include <random>

namespace Mathematics
{
    template class Segment3<float>;
    template class Segment3<double>;
}

Mathematics::Segment3Testing::Segment3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Segment3Testing)

void Mathematics::Segment3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Segment3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SegmentTest);
}

void Mathematics::Segment3Testing::SegmentTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real_distribution<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D point0(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Vector3D point1(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        const Segment3D firstSegment(point0, point1);

        ASSERT_TRUE(Vector3ToolsD::Approximate(point0, firstSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(point1, firstSegment.GetEndPoint()));

        const auto center = firstSegment.GetCenterPoint();
        const auto direction = firstSegment.GetDirection();
        auto extent = firstSegment.GetExtent();

        const Segment3D secondSegment(extent, center, direction);

        ASSERT_TRUE(Vector3ToolsD::Approximate(point0, secondSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(point1, secondSegment.GetEndPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(center, secondSegment.GetCenterPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(direction, secondSegment.GetDirection()));
        ASSERT_APPROXIMATE(extent, secondSegment.GetExtent(), 1e-10);
    }
}
