// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:53)

#include "Rectangle3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
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
        DoubleVector3D center(firstRandomDistribution(generator),
                              firstRandomDistribution(generator),
                              firstRandomDistribution(generator));

        DoubleVector3D axis0(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        DoubleVector3D axis1(firstRandomDistribution(generator),
                             firstRandomDistribution(generator),
                             firstRandomDistribution(generator));

        double extent0 = DoubleVector3DTools::VectorMagnitude(axis0);
        double extent1 = DoubleVector3DTools::VectorMagnitude(axis1);

        axis0.Normalize();
        axis1.Normalize();

        DoubleRectangle3 rectangle(center, axis0, axis1, extent0, extent1);

        ASSERT_TRUE(DoubleVector3DTools::Approximate(center, rectangle.GetCenter()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(axis0, rectangle.GetAxis0()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(axis1, rectangle.GetAxis1()));
        ASSERT_APPROXIMATE(extent0, rectangle.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(extent1, rectangle.GetExtent1(), 1e-10);

        vector<DoubleVector3D> vertices = rectangle.ComputeVertices();

        ASSERT_TRUE(DoubleVector3DTools::Approximate(vertices[0], rectangle.GetMMCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(vertices[1], rectangle.GetPMCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(vertices[2], rectangle.GetPPCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(vertices[3], rectangle.GetMPCorner()));

        DoubleVector3D ppCorner = center + extent0 * axis0 + extent1 * axis1;
        DoubleVector3D pmCorner = center + extent0 * axis0 - extent1 * axis1;
        DoubleVector3D mpCorner = center - extent0 * axis0 + extent1 * axis1;
        DoubleVector3D mmCorner = center - extent0 * axis0 - extent1 * axis1;

        ASSERT_TRUE(DoubleVector3DTools::Approximate(mmCorner, rectangle.GetMMCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(pmCorner, rectangle.GetPMCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(ppCorner, rectangle.GetPPCorner()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(mpCorner, rectangle.GetMPCorner()));
    }
}
