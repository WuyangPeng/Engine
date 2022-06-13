///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/30 11:30)

#include "Lozenge3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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

void Mathematics::Lozenge3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LozengeTest);
}

void Mathematics::Lozenge3Testing::LozengeTest()
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

        auto extent0 = Vector3ToolsD::GetLength(axis0);
        auto extent1 = Vector3ToolsD::GetLength(axis1);

        axis0.Normalize();
        axis1.Normalize();

        const Rectangle3D rectangle(center, axis0, axis1, extent0, extent1);

        const double radius(MathD::FAbs(firstRandomDistribution(generator)));

        const Lozenge3D lozenge(rectangle, radius);

        ASSERT_APPROXIMATE(radius, lozenge.GetRadius(), 1e-10);

        ASSERT_TRUE(Vector3ToolsD::Approximate(lozenge.GetRectangle().GetCenter(), rectangle.GetCenter()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(lozenge.GetRectangle().GetAxis0(), rectangle.GetAxis0()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(lozenge.GetRectangle().GetAxis1(), rectangle.GetAxis1()));
        ASSERT_APPROXIMATE(lozenge.GetRectangle().GetExtent0(), rectangle.GetExtent0(), 1e-10);
        ASSERT_APPROXIMATE(lozenge.GetRectangle().GetExtent1(), rectangle.GetExtent1(), 1e-10);
    }
}
