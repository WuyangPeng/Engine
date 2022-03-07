// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:53)

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Rectangle3Testing)

void Mathematics::Rectangle3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RectangleTest);
}

void Mathematics::Rectangle3Testing ::RectangleTest()
{
    default_random_engine generator{};

    uniform_real<double> firstRandomDistribution(-100.0, 100.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D center(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        Vector3D axis0(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        Vector3D axis1(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        double extent0 = Vector3ToolsD::GetLength(axis0);
        double extent1 = Vector3ToolsD::GetLength(axis1);

        axis0.Normalize();
        axis1.Normalize();

        Rectangle3D rectangle(center, axis0, axis1, extent0, extent1);

        ASSERT_TRUE(Vector3ToolsD::Approximate(center, rectangle.GetCenter()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(axis0, rectangle.GetAxis0()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(axis1, rectangle.GetAxis1()));
        ASSERT_APPROXIMATE(extent0, rectangle.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(extent1, rectangle.GetExtent1(), 1e-10);

        vector<Vector3D> vertices = rectangle.ComputeVertices();

        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices[0], rectangle.GetMMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices[1], rectangle.GetPMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices[2], rectangle.GetPPCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(vertices[3], rectangle.GetMPCorner()));

        Vector3D ppCorner = center + extent0 * axis0 + extent1 * axis1;
        Vector3D pmCorner = center + extent0 * axis0 - extent1 * axis1;
        Vector3D mpCorner = center - extent0 * axis0 + extent1 * axis1;
        Vector3D mmCorner = center - extent0 * axis0 - extent1 * axis1;

        ASSERT_TRUE(Vector3ToolsD::Approximate(mmCorner, rectangle.GetMMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(pmCorner, rectangle.GetPMCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(ppCorner, rectangle.GetPPCorner()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(mpCorner, rectangle.GetMPCorner()));
    }
}
