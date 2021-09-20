// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 17:31)

#include "Lozenge3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Lozenge3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Lozenge3<float>;
    template class Lozenge3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Lozenge3Testing)

void Mathematics::Lozenge3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LozengeTest);
}

void Mathematics::Lozenge3Testing ::LozengeTest()
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

        double radius(DoubleMath::FAbs(firstRandomDistribution(generator)));

        DoubleLozenge3 lozenge(rectangle, radius);

        ASSERT_APPROXIMATE(radius, lozenge.GetRadius(), 1e-10);

        ASSERT_TRUE(DoubleVector3DTools::Approximate(lozenge.GetRectangle().GetCenter(), rectangle.GetCenter()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(lozenge.GetRectangle().GetAxis0(), rectangle.GetAxis0()));
        ASSERT_TRUE(DoubleVector3DTools::Approximate(lozenge.GetRectangle().GetAxis1(), rectangle.GetAxis1()));
        ASSERT_APPROXIMATE(lozenge.GetRectangle().GetExtent0(), rectangle.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(lozenge.GetRectangle().GetExtent1(), rectangle.GetExtent1(), 1e-10);
    }
}
