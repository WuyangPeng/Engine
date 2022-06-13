///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:47)

#include "AVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/Float.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class AVector<float>;
    template class AVector<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AVectorTesting)

void Mathematics::AVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::AVectorTesting::ConstructionTest()
{
    const Float3 tuple{ 3.0f, 5.0f, 9.0f };
    const Vector3F vector{ 9.0f, 6.0f, 1.0f };

    AVectorF firstVector;

    ASSERT_APPROXIMATE(firstVector[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstVector[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstVector[2], 0.0f, 1e-8f);

    AVectorF secondVector{ 6.0f, 9.0f, 1.0f };

    ASSERT_APPROXIMATE(secondVector[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[2], 1.0f, 1e-8f);

    AVectorF thirdVector{};

    ASSERT_APPROXIMATE(thirdVector[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[2], 0.0f, 1e-8f);

    AVectorF fourthVector{ vector };

    ASSERT_APPROXIMATE(fourthVector[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthVector[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthVector[2], 1.0f, 1e-8f);

    AVectorF fifthVector{ fourthVector };

    ASSERT_APPROXIMATE(fifthVector[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fifthVector[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(fifthVector[2], 1.0f, 1e-8f);

    thirdVector = secondVector;

    ASSERT_APPROXIMATE(thirdVector[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[2], 1.0f, 1e-8f);
}

void Mathematics::AVectorTesting::AccessTest() noexcept
{
}

void Mathematics::AVectorTesting::ArithmeticCalculateTest()
{
    const AVectorF firstVector{ 26.0f, 91.0f, 8.0f };

    auto secondVector = -firstVector;
    ASSERT_APPROXIMATE(secondVector[0], -26.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[1], -91.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[2], -8.0f, 1e-8f);

    secondVector[0] = 3.0f;
    secondVector[1] = 7.0f;
    secondVector[2] = 17.0f;

    ASSERT_APPROXIMATE(secondVector[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[1], 7.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector[2], 17.0f, 1e-8f);

    const AVectorD thirdVector{ 6.0, 5.0, 15.0 };

    ASSERT_APPROXIMATE(thirdVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[2], 15.0, 1e-10);

    AVectorD fourthVector{ 9.0, 3.0, 3.0 };
    fourthVector += thirdVector;
    ASSERT_APPROXIMATE(fourthVector[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 8.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 18.0, 1e-10);

    auto fifthVector = thirdVector + fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 13.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 33.0, 1e-10);

    fifthVector -= fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 15.0, 1e-10);

    fourthVector = fifthVector - thirdVector;

    ASSERT_APPROXIMATE(fourthVector[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 0.0, 1e-10);

    fifthVector *= 6.0;

    ASSERT_APPROXIMATE(fifthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 90.0, 1e-10);

    fourthVector = 0.5 * fifthVector;

    ASSERT_APPROXIMATE(fourthVector[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 45.0, 1e-10);

    fourthVector = fifthVector * 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 60.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 180.0, 1e-10);

    fourthVector /= 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 90.0, 1e-10);

    fifthVector = fourthVector / 3.0;

    ASSERT_APPROXIMATE(fifthVector[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 10.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 30.0, 1e-10);
}

void Mathematics::AVectorTesting::VectorCalculateTest()
{
    default_random_engine randomEngine{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        AVectorD firstVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        AVectorD secondVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        auto dotProduct = firstVector[0] * secondVector[0] + firstVector[1] * secondVector[1] + firstVector[2] * secondVector[2];

        ASSERT_APPROXIMATE(Dot(firstVector, secondVector), dotProduct, 1e-10);

        AVectorD crossProduct{ firstVector[1] * secondVector[2] - firstVector[2] * secondVector[1],
                               firstVector[2] * secondVector[0] - firstVector[0] * secondVector[2],
                               firstVector[0] * secondVector[1] - firstVector[1] * secondVector[0] };

        auto testCross = Cross(firstVector, secondVector);

        ASSERT_TRUE(Approximate(testCross, crossProduct, 1e-10));

        crossProduct.Normalize();
        testCross = UnitCross(firstVector, secondVector);

        ASSERT_TRUE(Approximate(testCross, crossProduct, 1e-10));
    }

    AVectorF thirdVector{ 3.0f, 4.0f, 5.0f };

    ASSERT_APPROXIMATE(thirdVector.Length(), MathF::Sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(thirdVector.SquaredLength(), 50.0f, 1e-8f);

    thirdVector.Normalize();

    ASSERT_APPROXIMATE(thirdVector[0], 3.0f / sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[1], 4.0f / sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(thirdVector[2], 5.0f / sqrt(50.0f), 1e-7f);
}

void Mathematics::AVectorTesting::OtherCalculateTest()
{
    default_random_engine randomEngine{};
    const uniform_real<double> randomDistribution{ -100.0, 100.0 };

    AVectorD firstVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };
    AVectorD secondVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    AVectorD thirdVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    vector<AVectorD> vectors;
    vectors.push_back(firstVector);
    vectors.push_back(secondVector);
    vectors.push_back(thirdVector);

    const auto firstOrthonormalize = Orthonormalize(firstVector, secondVector, thirdVector);

    const auto secondOrthonormalize = Orthonormalize(vectors);

    firstVector.Normalize();
    auto dot0 = Dot(firstVector, secondVector);
    secondVector -= dot0 * firstVector;
    secondVector.Normalize();

    auto dot1 = Dot(secondVector, thirdVector);
    dot0 = Dot(firstVector, thirdVector);
    thirdVector -= dot0 * firstVector + dot1 * secondVector;
    thirdVector.Normalize();

    ASSERT_TRUE(Approximate(firstVector, firstOrthonormalize.GetUVector(), 1e-10));
    ASSERT_TRUE(Approximate(secondVector, firstOrthonormalize.GetVVector(), 1e-10));
    ASSERT_TRUE(Approximate(thirdVector, firstOrthonormalize.GetWVector(), 1e-10));
    ASSERT_TRUE(Approximate(firstVector, secondOrthonormalize.GetUVector(), 1e-10));
    ASSERT_TRUE(Approximate(secondVector, secondOrthonormalize.GetVVector(), 1e-10));
    ASSERT_TRUE(Approximate(thirdVector, secondOrthonormalize.GetWVector(), 1e-10));

    AVectorD fourthVector{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    const auto firstOrthonormalBasis = GenerateOrthonormalBasis(fourthVector);

    fourthVector.Normalize();

    const auto secondOrthonormalBasis = GenerateComplementBasis(fourthVector);

    ASSERT_TRUE(Approximate(fourthVector, firstOrthonormalBasis.GetWVector(), 1e-10));
    ASSERT_TRUE(Approximate(fourthVector, secondOrthonormalBasis.GetWVector(), 1e-10));

    const auto fifthVector = Cross(firstOrthonormalBasis.GetUVector(), firstOrthonormalBasis.GetVVector());

    ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetWVector(), fifthVector, 1e-10));

    const auto sixthVector = Cross(firstOrthonormalBasis.GetVVector(), firstOrthonormalBasis.GetWVector());

    ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetUVector(), sixthVector, 1e-10));

    const auto seventhVector = Cross(firstOrthonormalBasis.GetWVector(), firstOrthonormalBasis.GetUVector());

    ASSERT_TRUE(Approximate(firstOrthonormalBasis.GetVVector(), seventhVector));
}
