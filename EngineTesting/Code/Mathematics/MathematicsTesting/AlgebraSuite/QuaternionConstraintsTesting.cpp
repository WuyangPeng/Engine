///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:37)

#include "QuaternionConstraintsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/QuaternionConstraintsDetail.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class QuaternionConstraints<float>;
    template class QuaternionConstraints<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::QuaternionConstraintsTesting::QuaternionConstraintsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuaternionConstraintsTesting)

void Mathematics::QuaternionConstraintsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuaternionConstraintsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstraintsTest);
}

void Mathematics::QuaternionConstraintsTesting::ConstraintsTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution0{ -MathF::GetHalfPI(), MathF::GetHalfPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const float firstAngle = randomDistribution0(generator);

        std::uniform_real_distribution<float> randomDistribution1(firstAngle, MathF::GetHalfPI());

        const float secondAngle = randomDistribution1(generator);

        const QuaternionConstraintsF firstQuaternionConstraints(firstAngle, secondAngle);

        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosMinAngle(), MathF::Cos(firstAngle), 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinMinAngle(), MathF::Sin(firstAngle), 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosMaxAngle(), MathF::Cos(secondAngle), 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinMaxAngle(), MathF::Sin(secondAngle), 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetMinAngle(), firstAngle, 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetMaxAngle(), secondAngle, 1e-8f);

        const float avrAngle(0.5f * (firstAngle + secondAngle));

        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetCosAvrAngle(), MathF::Cos(avrAngle), 1e-8f);
        ASSERT_APPROXIMATE(firstQuaternionConstraints.GetSinAvrAngle(), MathF::Sin(avrAngle), 1e-8f);

        std::uniform_real_distribution<float> thirdRandomDistribution(-100.0f, 100.0f);

        Vector2F vector0(thirdRandomDistribution(generator), thirdRandomDistribution(generator));

        vector0.Normalize();

        const float angle = MathF::ATan(vector0[1] / vector0[0]);

        if (firstAngle <= angle && angle <= secondAngle)
        {
            ASSERT_TRUE(firstQuaternionConstraints.IsValid(vector0[0], vector0[1]));
        }
        else
        {
            ASSERT_FALSE(firstQuaternionConstraints.IsValid(vector0[0], vector0[1]));
        }
    }
}
