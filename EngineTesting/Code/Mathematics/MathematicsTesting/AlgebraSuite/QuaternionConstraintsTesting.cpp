///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 22:30)

#include "QuaternionConstraintsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/QuaternionConstraintsDetail.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class QuaternionConstraints<float>;
    template class QuaternionConstraints<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuaternionConstraintsTesting)

void Mathematics::QuaternionConstraintsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstraintsTest);
}

void Mathematics::QuaternionConstraintsTesting::ConstraintsTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -MathF::GetHalfPI(), MathF::GetHalfPI() };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const float firstAngle = firstRandomDistribution(generator);

        const uniform_real<float> secondRandomDistribution(firstAngle, MathF::GetHalfPI());

        const float secondAngle = secondRandomDistribution(generator);

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

        const uniform_real<float> thirdRandomDistribution(-100.0f, 100.0f);

        Vector2F firstVector(thirdRandomDistribution(generator), thirdRandomDistribution(generator));

        firstVector.Normalize();

        const float angle = MathF::ATan(firstVector[1] / firstVector[0]);

        if (firstAngle <= angle && angle <= secondAngle)
        {
            ASSERT_TRUE(firstQuaternionConstraints.IsValid(firstVector[0], firstVector[1]));
        }
        else
        {
            ASSERT_FALSE(firstQuaternionConstraints.IsValid(firstVector[0], firstVector[1]));
        }
    }
}
