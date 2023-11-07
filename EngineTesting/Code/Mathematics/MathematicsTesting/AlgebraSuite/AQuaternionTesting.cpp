///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:03)

#include "AQuaternionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

#include <random>

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
    AQuaternionF quaternion0;

    ASSERT_APPROXIMATE(quaternion0[0], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(quaternion0[1], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(quaternion0[2], 0.0f, 1e-10f);
    ASSERT_APPROXIMATE(quaternion0[3], 0.0f, 1e-10f);

    AQuaternionF quaternion1{ 3.0, 5.0, 6.0, 7.0 };

    ASSERT_APPROXIMATE(quaternion1[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[3], 7.0, 1e-10f);

    AQuaternionF quaternion2{ quaternion1 };

    ASSERT_APPROXIMATE(quaternion2[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion2[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion2[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion2[3], 7.0, 1e-10f);

    quaternion2[0] = 5.0;
    quaternion2[1] = 15.0;
    quaternion2[2] = 25.0;
    quaternion2[3] = 35.0;

    ASSERT_APPROXIMATE(quaternion1[0], 3.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[1], 5.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[2], 6.0, 1e-10f);
    ASSERT_APPROXIMATE(quaternion1[3], 7.0, 1e-10f);

    quaternion1 = quaternion2;

    ASSERT_APPROXIMATE(quaternion1[0], 5.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[2], 25.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[3], 35.0, 1e-10);
}

void Mathematics::AQuaternionTesting::AccessTest()
{
    constexpr AQuaternionF quaternion0{ 3.0f, 5.0f, 6.0f, 7.0f };

    ASSERT_APPROXIMATE(quaternion0[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(quaternion0[1], 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(quaternion0[2], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(quaternion0[3], 7.0f, 1e-8f);

    AQuaternionD quaternion1(23.0, 25.0, 62.0, 27.0);

    ASSERT_APPROXIMATE(quaternion1[0], 23.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[1], 25.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[2], 62.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1[3], 27.0, 1e-10);

    ASSERT_APPROXIMATE(quaternion1.GetW(), 23.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetX(), 25.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetZ(), 27.0, 1e-10);

    quaternion1.SetW(3.0);

    ASSERT_APPROXIMATE(quaternion1.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetX(), 25.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetZ(), 27.0, 1e-10);

    quaternion1.SetX(4.5);

    ASSERT_APPROXIMATE(quaternion1.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetY(), 62.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetZ(), 27.0, 1e-10);

    quaternion1.SetY(14.5);

    ASSERT_APPROXIMATE(quaternion1.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetY(), 14.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetZ(), 27.0, 1e-10);

    quaternion1.SetZ(7.77);

    ASSERT_APPROXIMATE(quaternion1.GetW(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetX(), 4.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetY(), 14.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion1.GetZ(), 7.77, 1e-10);
}

void Mathematics::AQuaternionTesting::OperatorCalculateTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0{ -100.0, 100.0 };
    std::uniform_real<double> randomDistribution1{ 0.0, MathD::GetTwoPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorD vector0{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        vector0.Normalize();

        const double double0{ randomDistribution1(randomEngine) };

        const AQuaternionD quaternion0{ vector0, double0 };

        AVectorD vector1{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        vector1.Normalize();

        const double double1{ randomDistribution1(randomEngine) };

        const AQuaternionD quaternion1{ vector1, double1 };

        const auto quaternion2 = quaternion0 * quaternion1;

        const AQuaternionD quaternion3{ MatrixD(vector0, double0) * MatrixD(vector1, double1) };

        ASSERT_TRUE(Approximate(quaternion2, quaternion3, 1e-10) || Approximate(quaternion2, -quaternion3, 1e-10));

        const auto matrix0 = quaternion2.ToRotationMatrix();
        const auto matrix1 = quaternion3.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        AQuaternionD quaternion4{ quaternion0 };

        quaternion4 *= quaternion1;

        const auto matrix2 = quaternion4.ToRotationMatrix();
        const auto matrix3 = quaternion3.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix3, 1e-10));

        AQuaternionD quaternion5{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        auto seventhQuaternion = -quaternion5;

        ASSERT_APPROXIMATE(quaternion5[0], -seventhQuaternion[0], 1e-10);
        ASSERT_APPROXIMATE(quaternion5[1], -seventhQuaternion[1], 1e-10);
        ASSERT_APPROXIMATE(quaternion5[2], -seventhQuaternion[2], 1e-10);
        ASSERT_APPROXIMATE(quaternion5[3], -seventhQuaternion[3], 1e-10);

        quaternion4 *= quaternion1;
    }

    const AQuaternionD quaternion6{ 3.0, 5.1, 6.7, 8.71 };
    const AQuaternionD quaternion7{ 13.1, 15.0, 16.71, 18.7 };

    auto quaternion8 = quaternion6 + quaternion7;

    ASSERT_APPROXIMATE(quaternion8[0], 16.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 20.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 23.41, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 27.41, 1e-10);

    quaternion8 = quaternion6 - quaternion7;

    ASSERT_APPROXIMATE(quaternion8[0], -10.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], -9.9, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], -10.01, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], -9.99, 1e-10);

    quaternion8 = quaternion6 * 4.0;

    ASSERT_APPROXIMATE(quaternion8[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 20.4, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 26.8, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 34.84, 1e-10);

    quaternion8 = 20.0 * quaternion6;

    ASSERT_APPROXIMATE(quaternion8[0], 60.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 102.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 134.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 174.2, 1e-10);

    quaternion8 = quaternion6 / 2.0;

    ASSERT_APPROXIMATE(quaternion8[0], 1.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 2.55, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 3.35, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 4.355, 1e-10);

    quaternion8 = quaternion6;

    quaternion8 += quaternion7;

    ASSERT_APPROXIMATE(quaternion8[0], 16.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 20.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 23.41, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 27.41, 1e-10);

    quaternion8 = quaternion6;

    quaternion8 -= quaternion7;

    ASSERT_APPROXIMATE(quaternion8[0], -10.1, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], -9.9, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], -10.01, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], -9.99, 1e-10);

    quaternion8 = quaternion6;

    quaternion8 *= 4.0;

    ASSERT_APPROXIMATE(quaternion8[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 20.4, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 26.8, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 34.84, 1e-10);

    quaternion8 = quaternion6;

    quaternion8 /= 2.0;

    ASSERT_APPROXIMATE(quaternion8[0], 1.5, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[1], 2.55, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[2], 3.35, 1e-10);
    ASSERT_APPROXIMATE(quaternion8[3], 4.355, 1e-10);
}

void Mathematics::AQuaternionTesting::ArithmeticCalculateTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution0{ -100.0f, 100.0f };
    std::uniform_real<float> randomDistribution1{ 0.0, MathF::GetTwoPI() };
    std::uniform_real<float> randomDistribution2{ 0.0f, 1.0f };
    const std::uniform_int<> randomDistribution3{ 0, 20 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AQuaternionF quaternion0{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        auto length = quaternion0[0] * quaternion0[0] + quaternion0[1] * quaternion0[1] + quaternion0[2] * quaternion0[2] + quaternion0[3] * quaternion0[3];

        ASSERT_APPROXIMATE(length, quaternion0.SquaredLength(), 1e-8f);

        length = MathF::Sqrt(length);

        ASSERT_APPROXIMATE(length, quaternion0.Length(), 1e-8f);

        AQuaternionF quaternion1{ quaternion0 };

        quaternion1.Normalize();

        ASSERT_APPROXIMATE(quaternion0[0], quaternion1[0] * length, 1e-5f);
        ASSERT_APPROXIMATE(quaternion0[1], quaternion1[1] * length, 1e-5f);
        ASSERT_APPROXIMATE(quaternion0[2], quaternion1[2] * length, 1e-5f);
        ASSERT_APPROXIMATE(quaternion0[3], quaternion1[3] * length, 1e-5f);

        quaternion1 = quaternion0.Inverse();

        AQuaternionF quaternion2 = quaternion1 * quaternion0;

        ASSERT_APPROXIMATE(quaternion2[0], 1.0f, 1e-6f);
        ASSERT_APPROXIMATE(quaternion2[1], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(quaternion2[2], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(quaternion2[3], 0.0f, 1e-7f);

        quaternion2 = quaternion0 * quaternion1;

        ASSERT_APPROXIMATE(quaternion2[0], 1.0f, 1e-6f);
        ASSERT_APPROXIMATE(quaternion2[1], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(quaternion2[2], 0.0f, 1e-7f);
        ASSERT_APPROXIMATE(quaternion2[3], 0.0f, 1e-7f);

        quaternion2 = quaternion0.Conjugate();

        ASSERT_APPROXIMATE(quaternion2[0], quaternion0[0], 1e-8f);
        ASSERT_APPROXIMATE(quaternion2[1], -quaternion0[1], 1e-8f);
        ASSERT_APPROXIMATE(quaternion2[2], -quaternion0[2], 1e-8f);
        ASSERT_APPROXIMATE(quaternion2[3], -quaternion0[3], 1e-8f);

        quaternion0[0] = 0.0f;
        quaternion1 = quaternion0.Exp();
        quaternion2 = quaternion1.Log();

        quaternion0.Normalize();
        quaternion2.Normalize();

        ASSERT_TRUE(Approximate(quaternion2, quaternion0, 1e-6f) || Approximate(quaternion2, -quaternion0, 1e-6f));

        quaternion0 = quaternion1;
        quaternion1 = quaternion0.Log();
        quaternion2 = quaternion1.Exp();

        ASSERT_TRUE(Approximate(quaternion2, quaternion0, 1e-2f));

        const AVectorF vector0{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        const auto vector1 = quaternion0.Rotate(vector0);
        const auto vector2 = quaternion0.ToRotationMatrix() * vector0;

        ASSERT_TRUE(Approximate(vector1, vector2, 1e-4f));

        AVectorD vector3{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        vector3.Normalize();

        const double double0{ randomDistribution1(randomEngine) };

        AQuaternionD quaternion3{ vector3, double0 };

        AVectorD vector4{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        vector4.Normalize();

        const double double1{ randomDistribution1(randomEngine) };

        AQuaternionD quaternion4{ vector4, double1 };

        AQuaternionD quaternion5{};

        quaternion5.Slerp(0.0, quaternion3, quaternion4);

        ASSERT_TRUE(Approximate(quaternion3, quaternion5, 1e-10));

        quaternion5.Slerp(1.0, quaternion3, quaternion4);

        ASSERT_TRUE(Approximate(quaternion4, quaternion5, 1e-10));

        auto t0 = randomDistribution2(randomEngine);

        quaternion5.Slerp(t0, quaternion3, quaternion4);

        auto cosValue = Dot(quaternion3, quaternion4);
        auto angle = MathD::ACos(cosValue);

        auto passAngle = MathD::ACos(Dot(quaternion3, quaternion5));
        auto remainAngle = MathD::ACos(Dot(quaternion5, quaternion4));

        ASSERT_APPROXIMATE(passAngle + remainAngle, angle, 0.00001);
        ASSERT_APPROXIMATE(passAngle / angle, t0, 0.00001);
        ASSERT_APPROXIMATE(remainAngle / angle, 1.0 - t0, 0.0001);

        AQuaternionD quaternion6{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        quaternion6.Normalize();

        AQuaternionD quaternion7{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        quaternion7.Normalize();

        AQuaternionD quaternion8{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        quaternion8.Normalize();

        // 使用另一种算法进行测试。
        auto quaternion9 = quaternion6.Inverse();
        quaternion5 = quaternion7.Inverse();
        quaternion4 = quaternion9 * quaternion7;
        quaternion3 = quaternion5 * quaternion8;
        quaternion9 = 0.25 * (quaternion4.Log() - quaternion3.Log());

        quaternion5 = quaternion7 * quaternion9.Exp();

        quaternion5.Normalize();

        quaternion4.Intermediate(quaternion6, quaternion7, quaternion8);

        quaternion4.Normalize();

        ASSERT_TRUE(Approximate(quaternion4, quaternion5, 1e-10));

        AQuaternionD quaternion10{ randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine), randomDistribution0(randomEngine) };

        quaternion10.Normalize();

        const auto slerpT = 2.0 * t0 * (1.0 - t0);

        quaternion9.Slerp(t0, quaternion6, quaternion10);
        quaternion5.Slerp(t0, quaternion7, quaternion8);
        quaternion4.Slerp(slerpT, quaternion9, quaternion5);

        quaternion9.Squad(t0, quaternion6, quaternion7, quaternion8, quaternion10);

        ASSERT_TRUE(Approximate(quaternion9, quaternion4, 1e-10));

        auto dot = quaternion6[0] * quaternion7[0] + quaternion6[1] * quaternion7[1] + quaternion6[2] * quaternion7[2] + quaternion6[3] * quaternion7[3];

        ASSERT_APPROXIMATE(dot, Dot(quaternion6, quaternion7), 1e-10);
    }
}

void Mathematics::AQuaternionTesting::CompareTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    AQuaternionF quaternion0{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    AQuaternionF quaternion1{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    ASSERT_TRUE(quaternion0 == quaternion0);
    ASSERT_FALSE(quaternion0 == quaternion1);
    ASSERT_TRUE(quaternion0 != quaternion1);

    if (!(quaternion0 < quaternion1))
    {
        quaternion0[0] = 0.0f;
        quaternion1[0] = 1.0f;
    }

    ASSERT_TRUE(quaternion0 < quaternion1);
    ASSERT_FALSE(quaternion0 > quaternion1);
    ASSERT_TRUE(quaternion0 <= quaternion1);
    ASSERT_FALSE(quaternion0 >= quaternion1);

    ASSERT_TRUE(Approximate(quaternion0, quaternion0, 1e-8f));
    ASSERT_TRUE(Approximate(quaternion1, quaternion1, 1e-8f));
    ASSERT_FALSE(Approximate(quaternion0, quaternion1, 1e-8f));
}
