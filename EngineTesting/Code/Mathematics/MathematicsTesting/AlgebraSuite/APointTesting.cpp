///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:31)

#include "APointTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/Float.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class APoint<float>;
    template class APoint<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, APointTesting)

void Mathematics::APointTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::APointTesting::ConstructionTest()
{
    const Float3 tuple{ 3.0f, 5.0f, 9.0f };
    const Vector3F vector{ 9.0f, 6.0f, 1.0f };

    APointF firstPoint;

    ASSERT_APPROXIMATE(firstPoint[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], 0.0f, 1e-8f);

    APointF secondPoint{ 6.0f, 9.0f, 1.0f };

    ASSERT_APPROXIMATE(secondPoint[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondPoint[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondPoint[2], 1.0f, 1e-8f);

    APointF thirdPoint{};

    ASSERT_APPROXIMATE(thirdPoint[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdPoint[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdPoint[2], 0.0f, 1e-8f);

    APointF fourthPoint{ vector };

    ASSERT_APPROXIMATE(fourthPoint[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthPoint[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthPoint[2], 1.0f, 1e-8f);

    const APointF fifthPoint{ fourthPoint };

    ASSERT_APPROXIMATE(fourthPoint[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthPoint[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthPoint[2], 1.0f, 1e-8f);

    thirdPoint = secondPoint;

    ASSERT_APPROXIMATE(thirdPoint[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdPoint[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdPoint[2], 1.0f, 1e-8f);
}

void Mathematics::APointTesting::AccessTest() noexcept
{
}

void Mathematics::APointTesting::CalculateTest()
{
    APointF firstPoint{ 6.1f, 3.0f, 8.2f };
    const AVectorF firstVector{ 16.1f, 23.0f, 18.2f };

    firstPoint += firstVector;

    ASSERT_APPROXIMATE(firstPoint[0], 22.2f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], 26.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], 26.4f, 1e-5f);

    const AVectorF secondVector{ 22.1f, 123.0f, 118.2f };

    firstPoint -= secondVector;

    ASSERT_APPROXIMATE(firstPoint[0], 0.1f, 1e-6f);
    ASSERT_APPROXIMATE(firstPoint[1], -97.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], -91.8f, 1e-5f);

    APointF secondPoint{ 26.1f, 31.0f, 8.22f };

    firstPoint += secondPoint;

    ASSERT_APPROXIMATE(firstPoint[0], 26.2f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], -66.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], -83.58f, 1e-5f);

    const APointF thirdPoint{ 26.3f, -66.1f, -83.57f };

    firstPoint -= thirdPoint;

    ASSERT_APPROXIMATE(firstPoint[0], -0.1f, 1e-5f);
    ASSERT_APPROXIMATE(firstPoint[1], 0.1f, 1e-5f);
    ASSERT_APPROXIMATE(firstPoint[2], -0.01f, 1e-5f);

    firstPoint *= 0.7f;

    ASSERT_APPROXIMATE(firstPoint[0], -0.07f, 1e-5f);
    ASSERT_APPROXIMATE(firstPoint[1], 0.07f, 1e-5f);
    ASSERT_APPROXIMATE(firstPoint[2], -0.007f, 1e-5f);

    firstPoint /= 0.1f;

    ASSERT_APPROXIMATE(firstPoint[0], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(firstPoint[1], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(firstPoint[2], -0.07f, 1e-4f);

    secondPoint = -firstPoint;

    ASSERT_APPROXIMATE(secondPoint[0], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(secondPoint[1], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(secondPoint[2], 0.07f, 1e-4f);

    auto thirdVector = firstPoint - secondPoint;

    ASSERT_APPROXIMATE(thirdVector[0], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(thirdVector[1], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(thirdVector[2], -0.14f, 1e-4f);

    auto fourthPoint = firstPoint + thirdVector;

    ASSERT_APPROXIMATE(fourthPoint[0], -2.1f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], 2.1f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], -0.21f, 1e-3f);

    fourthPoint = firstPoint - thirdVector;

    ASSERT_APPROXIMATE(fourthPoint[0], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], 0.07f, 1e-4f);

    fourthPoint = secondPoint + thirdPoint;

    ASSERT_APPROXIMATE(fourthPoint[0], 27.0f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], -66.8f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], -83.5f, 1e-4f);

    fourthPoint = secondPoint * 2.0f;

    ASSERT_APPROXIMATE(fourthPoint[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], 0.14f, 1e-4f);

    fourthPoint = secondPoint / 0.5f;

    ASSERT_APPROXIMATE(fourthPoint[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], 0.14f, 1e-4f);

    fourthPoint = 2.0f * secondPoint;

    ASSERT_APPROXIMATE(fourthPoint[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(fourthPoint[2], 0.14f, 1e-4f);

    default_random_engine randomEngine{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        APointD fifthPoint{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        AVectorD fourthVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        auto dotProduct = fifthPoint[0] * fourthVector[0] + fifthPoint[1] * fourthVector[1] + fifthPoint[2] * fourthVector[2];

        ASSERT_APPROXIMATE(Dot(fifthPoint, fourthVector), dotProduct, 1e-10);

        const auto sixthPoint = fifthPoint + APointD{ 0.001, 0.001, 0.001 };

        ASSERT_TRUE(Approximate(fifthPoint, fifthPoint, 1e-10));
        ASSERT_TRUE(Approximate(fifthPoint, sixthPoint, 1e-2));
        ASSERT_FALSE(Approximate(fifthPoint, sixthPoint, 1e-4));

        ASSERT_TRUE(Approximate(fifthPoint, fifthPoint));
    }
}
