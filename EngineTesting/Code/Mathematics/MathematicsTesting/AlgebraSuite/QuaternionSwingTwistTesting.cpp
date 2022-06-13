///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:33)

#include "QuaternionSwingTwistTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/QuaternionSwingTwistDetail.h"
#include "Mathematics/Algebra/Vector3.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class QuaternionSwingTwist<float>;
    template class QuaternionSwingTwist<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuaternionSwingTwistTesting)

void Mathematics::QuaternionSwingTwistTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuaternionSwingTwistTest);
}

void Mathematics::QuaternionSwingTwistTesting::QuaternionSwingTwistTest()
{
    default_random_engine generator{};
    const uniform_real<double> randomDistribution{ -10.0, 10.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D firstVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        firstVector.Normalize();

        QuaternionD firstQuaternion(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        firstQuaternion.Normalize();

        QuaternionD::QuaternionSwingTwist quaternionSwingTwist = firstQuaternion.DecomposeTwistTimesSwing(firstVector, 1e-10);

        QuaternionD secondQuaternion = quaternionSwingTwist.GetTwist() * quaternionSwingTwist.GetSwing();

        ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion, 1e-10));

        quaternionSwingTwist = firstQuaternion.DecomposeSwingTimesTwist(firstVector, 1e-10);

        secondQuaternion = quaternionSwingTwist.GetSwing() * quaternionSwingTwist.GetTwist();

        ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion, 1e-10));
    }
}
