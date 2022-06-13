///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 11:21)

#include "Rectangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Rectangle3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Rectangle3<float>;
    template class Rectangle3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Rectangle3Testing)

void Mathematics::Rectangle3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RectangleTest);
}

void Mathematics::Rectangle3Testing::RectangleTest()
{
    default_random_engine generator{};

    const uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D center(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        Vector3D axis0(firstRandomDistribution(generator),
                       firstRandomDistribution(generator),
                       firstRandomDistribution(generator));

        Vector3D axis1(firstRandomDistribution(generator),
                       firstRandomDistribution(generator),
                       firstRandomDistribution(generator));

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
