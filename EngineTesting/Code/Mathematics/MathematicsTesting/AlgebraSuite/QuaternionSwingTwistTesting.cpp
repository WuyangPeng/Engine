///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:38)

#include "QuaternionSwingTwistTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/QuaternionSwingTwistDetail.h"
#include "Mathematics/Algebra/Vector3.h"

#include <random>

namespace Mathematics
{
    template class QuaternionSwingTwist<float>;
    template class QuaternionSwingTwist<double>;
}

Mathematics::QuaternionSwingTwistTesting::QuaternionSwingTwistTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuaternionSwingTwistTesting)

void Mathematics::QuaternionSwingTwistTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuaternionSwingTwistTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuaternionSwingTwistTest);
}

void Mathematics::QuaternionSwingTwistTesting::QuaternionSwingTwistTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ -10.0, 10.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        vector0.Normalize();

        QuaternionD firstQuaternion(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        firstQuaternion.Normalize();

        QuaternionD::QuaternionSwingTwist quaternionSwingTwist = firstQuaternion.DecomposeTwistTimesSwing(vector0, 1e-10);

        QuaternionD secondQuaternion = quaternionSwingTwist.GetTwist() * quaternionSwingTwist.GetSwing();

        ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion, 1e-10));

        quaternionSwingTwist = firstQuaternion.DecomposeSwingTimesTwist(vector0, 1e-10);

        secondQuaternion = quaternionSwingTwist.GetSwing() * quaternionSwingTwist.GetTwist();

        ASSERT_TRUE(Approximate(firstQuaternion, secondQuaternion, 1e-10));
    }
}
