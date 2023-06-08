///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:38)

#include "AQuaternionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class AQuaternion<float>;
    template class AQuaternion<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::AQuaternionTesting::AQuaternionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AQuaternionTesting)

void Mathematics::AQuaternionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AQuaternionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::AQuaternionTesting::ConstructionTest()
{
    AQuaternionF firstQuaternion;

    ASSERT_APPROXIMATE(firstQuaternion[0], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(firstQuaternion[1], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(firstQuaternion[2], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(firstQuaternion[3], 0.0f, 1e-10f);

    AQuaternionF secondQuaternion{ 3.0, 5.0, 6.0, 7.0 };

    ASSERT_APPROXIMATE(secondQuaternion[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[3], 7.0, 1e-10f);

    AQuaternionF thirdQuaternion{ secondQuaternion };

    ASSERT_APPROXIMATE(thirdQuaternion[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(thirdQuaternion[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(thirdQuaternion[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(thirdQuaternion[3], 7.0, 1e-10f);

    thirdQuaternion[0] = 5.0;
    thirdQuaternion[1] = 15.0;
    thirdQuaternion[2] = 25.0;
    thirdQuaternion[3] = 35.0;

    ASSERT_APPROXIMATE(secondQuaternion[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(secondQuaternion[3], 7.0, 1e-10f);

    secondQuaternion = thirdQuaternion;

    ASSERT_APPROXIMATE(secondQuaternion[0], 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[2], 25.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[3], 35.0, 1e-10);

    default_random_engine randomEngine{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };
    const uniform_real<float> secondRandomDistribution{ 0.0f, MathF::GetTwoPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorF firstVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        firstVector.Normalize();

        const float firstFloat{ secondRandomDistribution(randomEngine) };

        const MatrixF firstMatrix{ firstVector, firstFloat };

        AQuaternionF fourthQuaternion{ firstMatrix };

        auto secondMatrix = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-6f));

        const AQuaternionF fifthQuaternion{ firstVector, firstFloat };

        auto secondVector = fifthQuaternion.ToAxis();
        auto secondFloat = fifthQuaternion.ToAngle();

        ASSERT_TRUE(Approximate(firstVector, secondVector, 1e-6f));
        ASSERT_APPROXIMATE(firstFloat, secondFloat, 1e-5f);

        fourthQuaternion.FromRotationMatrix(firstMatrix);

        secondMatrix = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-6f));

        fourthQuaternion.FromAxisAngle(firstVector, firstFloat);

        secondVector = fifthQuaternion.ToAxis();
        secondFloat = fifthQuaternion.ToAngle();

        ASSERT_TRUE(Approximate(firstVector, secondVector, 1e-6f));
        ASSERT_APPROXIMATE(firstFloat, secondFloat, 1e-5f);
    }
}

void Mathematics::AQuaternionTesting::AccessTest()
{
    const AQuaternionF firstQuaternion{ 3.0f, 5.0f, 6.0f, 7.0f };

    ASSERT_APPROXIMATE(firstQuaternion[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[1], 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[2], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[3], 7.0f, 1e-8f);

    AQuaternionD secondQuaternion(23.0, 25.0, 62.0, 27.0);

    ASSERT_APPROXIMATE(secondQuaternion[0], 23.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[1], 25.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[2], 62.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[3], 27.0, 1e-10);

    ASSERT_APPROXIMATE(secondQuaternion.GetW(), 23.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetX(), 25.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetZ(), 27.0, 1e-10);

    secondQuaternion.SetW(3.0);

    ASSERT_APPROXIMATE(secondQuaternion.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetX(), 25.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetZ(), 27.0, 1e-10);

    secondQuaternion.SetX(4.5);

    ASSERT_APPROXIMATE(secondQuaternion.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetZ(), 27.0, 1e-10);

    secondQuaternion.SetY(14.5);

    ASSERT_APPROXIMATE(secondQuaternion.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetY(), 14.5, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetZ(), 27.0, 1e-10);

    secondQuaternion.SetZ(7.77);

    ASSERT_APPROXIMATE(secondQuaternion.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetY(), 14.5, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion.GetZ(), 7.77, 1e-10);
}

void Mathematics::AQuaternionTesting::OperatorCalculateTest()
{
    default_random_engine randomEngine{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };
    const uniform_real<double> secondRandomDistribution{ 0.0, MathD::GetTwoPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorD firstVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        firstVector.Normalize();

        const double firstDouble{ secondRandomDistribution(randomEngine) };

        const AQuaternionD firstQuaternion{ firstVector, firstDouble };

        AVectorD secondVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        secondVector.Normalize();

        const double secondDouble{ secondRandomDistribution(randomEngine) };

        const AQuaternionD secondQuaternion{ secondVector, secondDouble };

        const auto thirdQuaternion = firstQuaternion * secondQuaternion;

        const AQuaternionD fourthQuaternion{ MatrixD(firstVector, firstDouble) * MatrixD(secondVector, secondDouble) };

        ASSERT_TRUE(Approximate(thirdQuaternion, fourthQuaternion, 1e-10) || Approximate(thirdQuaternion, -fourthQuaternion, 1e-10));

        const auto firstMatrix = thirdQuaternion.ToRotationMatrix();
        const auto secondMatrix = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, secondMatrix, 1e-10));

        AQuaternionD fifthQuaternion{ firstQuaternion };

        fifthQuaternion *= secondQuaternion;

        const auto thirdMatrix = fifthQuaternion.ToRotationMatrix();
        const auto fourthMatrix = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(firstMatrix, fourthMatrix, 1e-10));

        AQuaternionD sixthQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        auto seventhQuaternion = -sixthQuaternion;

        ASSERT_APPROXIMATE(sixthQuaternion[0], -seventhQuaternion[0], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[1], -seventhQuaternion[1], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[2], -seventhQuaternion[2], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[3], -seventhQuaternion[3], 1e-10);

        fifthQuaternion *= secondQuaternion;
    }

    const AQuaternionD eighthQuaternion{ 3.0, 5.1, 6.7, 8.71 };
    const AQuaternionD ninthQuaternion{ 13.1, 15.0, 16.71, 18.7 };

    auto tenthQuaternion = eighthQuaternion + ninthQuaternion;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 16.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 20.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 23.41, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 27.41, 1e-10);

    tenthQuaternion = eighthQuaternion - ninthQuaternion;

    ASSERT_APPROXIMATE(tenthQuaternion[0], -10.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], -9.9, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], -10.01, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], -9.99, 1e-10);

    tenthQuaternion = eighthQuaternion * 4.0;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 20.4, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 26.8, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 34.84, 1e-10);

    tenthQuaternion = 20.0 * eighthQuaternion;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 60.0, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 102.0, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 134.0, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 174.2, 1e-10);

    tenthQuaternion = eighthQuaternion / 2.0;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 1.5, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 2.55, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 3.35, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 4.355, 1e-10);

    tenthQuaternion = eighthQuaternion;

    tenthQuaternion += ninthQuaternion;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 16.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 20.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 23.41, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 27.41, 1e-10);

    tenthQuaternion = eighthQuaternion;

    tenthQuaternion -= ninthQuaternion;

    ASSERT_APPROXIMATE(tenthQuaternion[0], -10.1, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], -9.9, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], -10.01, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], -9.99, 1e-10);

    tenthQuaternion = eighthQuaternion;

    tenthQuaternion *= 4.0;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 20.4, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 26.8, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 34.84, 1e-10);

    tenthQuaternion = eighthQuaternion;

    tenthQuaternion /= 2.0;

    ASSERT_APPROXIMATE(tenthQuaternion[0], 1.5, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[1], 2.55, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[2], 3.35, 1e-10);
    ASSERT_APPROXIMATE(tenthQuaternion[3], 4.355, 1e-10);
}

void Mathematics::AQuaternionTesting::ArithmeticCalculateTest()
{
    default_random_engine randomEngine{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };
    const uniform_real<float> secondRandomDistribution{ 0.0, MathF::GetTwoPI() };
    const uniform_real<float> thirdRandomDistribution{ 0.0f, 1.0f };
    const uniform_int<> fourthRandomDistribution{ 0, 20 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AQuaternionF firstQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        auto length = firstQuaternion[0] * firstQuaternion[0] + firstQuaternion[1] * firstQuaternion[1] + firstQuaternion[2] * firstQuaternion[2] + firstQuaternion[3] * firstQuaternion[3];

        ASSERT_APPROXIMATE(length, firstQuaternion.SquaredLength(), 1e-8f);

        length = MathF::Sqrt(length);

        ASSERT_APPROXIMATE(length, firstQuaternion.Length(), 1e-8f);

        AQuaternionF secondQuaternion{ firstQuaternion };

        secondQuaternion.Normalize();

        ASSERT_APPROXIMATE(firstQuaternion[0], secondQuaternion[0] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[1], secondQuaternion[1] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[2], secondQuaternion[2] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[3], secondQuaternion[3] * length, 1e-5f);

        secondQuaternion = firstQuaternion.Inverse();

        AQuaternionF thirdQuaternion = secondQuaternion * firstQuaternion;

        ASSERT_APPROXIMATE(thirdQuaternion[0], 1.0f, 1e-6f);
        ASSERT_APPROXIMATE(thirdQuaternion[1], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(thirdQuaternion[2], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(thirdQuaternion[3], 0.0f, 1e-7f);

        thirdQuaternion = firstQuaternion * secondQuaternion;

        ASSERT_APPROXIMATE(thirdQuaternion[0], 1.0f, 1e-6f);
        ASSERT_APPROXIMATE(thirdQuaternion[1], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(thirdQuaternion[2], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(thirdQuaternion[3], 0.0f, 1e-7f);

        thirdQuaternion = firstQuaternion.Conjugate();

        ASSERT_APPROXIMATE(thirdQuaternion[0], firstQuaternion[0], 1e-8f);
        ASSERT_APPROXIMATE(thirdQuaternion[1], -firstQuaternion[1], 1e-8f);
        ASSERT_APPROXIMATE(thirdQuaternion[2], -firstQuaternion[2], 1e-8f);
        ASSERT_APPROXIMATE(thirdQuaternion[3], -firstQuaternion[3], 1e-8f);

        firstQuaternion[0] = 0.0f;
        secondQuaternion = firstQuaternion.Exp();
        thirdQuaternion = secondQuaternion.Log();

        firstQuaternion.Normalize();
        thirdQuaternion.Normalize();

        ASSERT_TRUE(Approximate(thirdQuaternion, firstQuaternion, 1e-6f) || Approximate(thirdQuaternion, -firstQuaternion, 1e-6f));

        firstQuaternion = secondQuaternion;
        secondQuaternion = firstQuaternion.Log();
        thirdQuaternion = secondQuaternion.Exp();

        ASSERT_TRUE(Approximate(thirdQuaternion, firstQuaternion, 1e-2f));

        const AVectorF firstVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        const auto secondVector = firstQuaternion.Rotate(firstVector);
        const auto thirdVector = firstQuaternion.ToRotationMatrix() * firstVector;

        ASSERT_TRUE(Approximate(secondVector, thirdVector, 1e-4f));

        AVectorD fourthVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        fourthVector.Normalize();

        const double firstDouble{ secondRandomDistribution(randomEngine) };

        AQuaternionD fourthQuaternion{ fourthVector, firstDouble };

        AVectorD fifthVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        fifthVector.Normalize();

        const double secondDouble{ secondRandomDistribution(randomEngine) };

        AQuaternionD fifthQuaternion{ fifthVector, secondDouble };

        AQuaternionD sixthQuaternion;

        sixthQuaternion.Slerp(0.0, fourthQuaternion, fifthQuaternion);

        ASSERT_TRUE(Approximate(fourthQuaternion, sixthQuaternion, 1e-10));

        sixthQuaternion.Slerp(1.0, fourthQuaternion, fifthQuaternion);

        ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion, 1e-10));

        auto firstT = thirdRandomDistribution(randomEngine);

        sixthQuaternion.Slerp(firstT, fourthQuaternion, fifthQuaternion);

        auto cosValue = Dot(fourthQuaternion, fifthQuaternion);
        auto angle = MathD::ACos(cosValue);

        auto passAngle = MathD::ACos(Dot(fourthQuaternion, sixthQuaternion));
        auto remainAngle = MathD::ACos(Dot(sixthQuaternion, fifthQuaternion));

        ASSERT_APPROXIMATE(passAngle + remainAngle, angle, 0.00001);
        ASSERT_APPROXIMATE(passAngle / angle, firstT, 0.00001);
        ASSERT_APPROXIMATE(remainAngle / angle, 1.0 - firstT, 0.0001);

        AQuaternionD eighthQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        eighthQuaternion.Normalize();

        AQuaternionD ninthQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        ninthQuaternion.Normalize();

        AQuaternionD tenthQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        tenthQuaternion.Normalize();

        // 使用另一种算法进行测试。
        auto seventhQuaternion = eighthQuaternion.Inverse();
        sixthQuaternion = ninthQuaternion.Inverse();
        fifthQuaternion = seventhQuaternion * ninthQuaternion;
        fourthQuaternion = sixthQuaternion * tenthQuaternion;
        seventhQuaternion = 0.25 * (fifthQuaternion.Log() - fourthQuaternion.Log());

        sixthQuaternion = ninthQuaternion * seventhQuaternion.Exp();

        sixthQuaternion.Normalize();

        fifthQuaternion.Intermediate(eighthQuaternion, ninthQuaternion, tenthQuaternion);

        fifthQuaternion.Normalize();

        ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion, 1e-10));

        AQuaternionD eleventhQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        eleventhQuaternion.Normalize();

        const auto slerpT = 2.0 * firstT * (1.0 - firstT);

        seventhQuaternion.Slerp(firstT, eighthQuaternion, eleventhQuaternion);
        sixthQuaternion.Slerp(firstT, ninthQuaternion, tenthQuaternion);
        fifthQuaternion.Slerp(slerpT, seventhQuaternion, sixthQuaternion);

        seventhQuaternion.Squad(firstT, eighthQuaternion, ninthQuaternion, tenthQuaternion, eleventhQuaternion);

        ASSERT_TRUE(Approximate(seventhQuaternion, fifthQuaternion, 1e-10));

        auto dot = eighthQuaternion[0] * ninthQuaternion[0] + eighthQuaternion[1] * ninthQuaternion[1] +
                   eighthQuaternion[2] * ninthQuaternion[2] + eighthQuaternion[3] * ninthQuaternion[3];

        ASSERT_APPROXIMATE(dot, Dot(eighthQuaternion, ninthQuaternion), 1e-10);
    }
}

void Mathematics::AQuaternionTesting::CompareTest()
{
    default_random_engine randomEngine{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    AQuaternionF firstQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

    AQuaternionF secondQuaternion{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

    ASSERT_TRUE(firstQuaternion == firstQuaternion);
    ASSERT_FALSE(firstQuaternion == secondQuaternion);
    ASSERT_TRUE(firstQuaternion != secondQuaternion);

    if (!(firstQuaternion < secondQuaternion))
    {
        firstQuaternion[0] = 0.0f;
        secondQuaternion[0] = 1.0f;
    }

    ASSERT_TRUE(firstQuaternion < secondQuaternion);
    ASSERT_FALSE(firstQuaternion > secondQuaternion);
    ASSERT_TRUE(firstQuaternion <= secondQuaternion);
    ASSERT_FALSE(firstQuaternion >= secondQuaternion);

    ASSERT_TRUE(Approximate(firstQuaternion, firstQuaternion, 1e-8f));
    ASSERT_TRUE(Approximate(secondQuaternion, secondQuaternion, 1e-8f));
    ASSERT_FALSE(Approximate(firstQuaternion, secondQuaternion, 1e-8f));
}
