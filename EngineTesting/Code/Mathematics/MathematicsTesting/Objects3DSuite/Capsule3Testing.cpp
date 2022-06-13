///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/28 15:37)

#include "Capsule3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Objects3D/Capsule3Detail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class Capsule3<float>;
    template class Capsule3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Capsule3Testing)

void Mathematics::Capsule3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CapsuleTest);
}

void Mathematics::Capsule3Testing::CapsuleTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Vector3D firstPoint(firstRandomDistribution(generator),
                                  firstRandomDistribution(generator),
                                  firstRandomDistribution(generator));

        const Vector3D secondPoint(firstRandomDistribution(generator),
                                   firstRandomDistribution(generator),
                                   firstRandomDistribution(generator));

        const Segment3D firstSegment(firstPoint, secondPoint);

        const double radius(MathD::FAbs(firstRandomDistribution(generator)));

        const Capsule3D capsule(firstSegment, radius);

        ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetBeginPoint(), firstSegment.GetBeginPoint()));
        ASSERT_TRUE(Vector3ToolsD::Approximate(capsule.GetSegment().GetEndPoint(), firstSegment.GetEndPoint()));
        ASSERT_APPROXIMATE(radius, capsule.GetRadius(), 1e-10);
    }
}
