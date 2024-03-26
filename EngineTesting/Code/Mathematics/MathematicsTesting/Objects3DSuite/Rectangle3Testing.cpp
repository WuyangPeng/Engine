///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:20)

#include "Rectangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Rectangle3Detail.h"
#include "Mathematics/Primitives/RectangleDetail.h"

#include <random>

namespace Mathematics
{
    template class Rectangle3<float>;
    template class Rectangle3<double>;
}

Mathematics::Rectangle3Testing::Rectangle3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Rectangle3Testing)

void Mathematics::Rectangle3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Rectangle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RectangleTest);
}

void Mathematics::Rectangle3Testing::RectangleTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_real<double> randomDistribution0(-100.0, 100.0);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector3D center(randomDistribution0(generator),
                              randomDistribution0(generator),
                              randomDistribution0(generator));

        Vector3D axis0(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        Vector3D axis1(randomDistribution0(generator),
                       randomDistribution0(generator),
                       randomDistribution0(generator));

        const double extent0 = Vector3ToolsD::GetLength(axis0);
        const double extent1 = Vector3ToolsD::GetLength(axis1);

        axis0.Normalize();
        axis1.Normalize();

        const Rectangle3D rectangle(center, axis0, axis1, extent0, extent1);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, rectangle.GetCenter()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(axis0, rectangle.GetAxis0()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(axis1, rectangle.GetAxis1()));
        ASSERT_APPROXIMATE(extent0, rectangle.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(extent1, rectangle.GetExtent1(), 1e-10);

        auto vertices = rectangle.ComputeVertices();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices.at(0), rectangle.GetMMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices.at(1), rectangle.GetPMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices.at(2), rectangle.GetPPCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices.at(3), rectangle.GetMPCorner()));

        auto ppCorner = center + extent0 * axis0 + extent1 * axis1;
        auto pmCorner = center + extent0 * axis0 - extent1 * axis1;
        auto mpCorner = center - extent0 * axis0 + extent1 * axis1;
        auto mmCorner = center - extent0 * axis0 - extent1 * axis1;

        ASSERT_TRUE(Vector3ToolsD::Approximate(mmCorner, rectangle.GetMMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(pmCorner, rectangle.GetPMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(ppCorner, rectangle.GetPPCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(mpCorner, rectangle.GetMPCorner()));
    }
}
