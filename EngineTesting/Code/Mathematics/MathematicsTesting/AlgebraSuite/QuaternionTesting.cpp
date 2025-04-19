///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:38)

#include "QuaternionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

#include <random>
#include <vector>

Mathematics::QuaternionTesting::QuaternionTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuaternionTesting)

void Mathematics::QuaternionTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuaternionTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClosestCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConstraintsClosestCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::QuaternionTesting::ConstructionTest()
{
    QuaternionF firstQuaternion;

    ASSERT_APPROXIMATE(firstQuaternion[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[3], 0.0f, 1e-8f);

    QuaternionD secondQuaternion(3.0, 5.0, 6.0, 7.0);

    ASSERT_APPROXIMATE(secondQuaternion[0], 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[2], 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[3], 7.0, 1e-10);

    QuaternionD thirdQuaternion(secondQuaternion);

    ASSERT_APPROXIMATE(thirdQuaternion[0], 3.0, 1e-10);
    ASSERT_APPROXIMATE(thirdQuaternion[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(thirdQuaternion[2], 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdQuaternion[3], 7.0, 1e-10);

    thirdQuaternion[0] = 5.0;
    thirdQuaternion[1] = 15.0;
    thirdQuaternion[2] = 25.0;
    thirdQuaternion[3] = 35.0;

    ASSERT_APPROXIMATE(secondQuaternion[0], 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[2], 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[3], 7.0, 1e-10);

    secondQuaternion = thirdQuaternion;

    ASSERT_APPROXIMATE(secondQuaternion[0], 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[2], 25.0, 1e-10);
    ASSERT_APPROXIMATE(secondQuaternion[3], 35.0, 1e-10);

    std::default_random_engine generator{};
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };
    std::uniform_real_distribution<float> randomDistribution1{ 0.0f, MathF::GetTwoPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3F vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        vector0.Normalize();

        const float firstFloat(randomDistribution1(generator));

        Matrix3F matrix0(vector0, firstFloat);

        QuaternionF fourthQuaternion(matrix0);

        Matrix3F matrix1 = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-6f));

        const QuaternionF fifthQuaternion(vector0, firstFloat);

        Vector3F vector1 = fifthQuaternion.ToAxis();
        float secondFloat = fifthQuaternion.ToAngle();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector0, vector1, 1e-4f));
        ASSERT_APPROXIMATE(firstFloat, secondFloat, 1e-5f);

        std::vector<Vector3F> vector03fVector;

        vector03fVector.push_back(Vector3F(matrix0(0, 0), matrix0(1, 0), matrix0(2, 0)));
        vector03fVector.push_back(Vector3F(matrix0(0, 1), matrix0(1, 1), matrix0(2, 1)));
        vector03fVector.push_back(Vector3F(matrix0(0, 2), matrix0(1, 2), matrix0(2, 2)));

        const QuaternionF sixQuaternion(vector03fVector);

        std::vector<Vector3F> vector13fVector = sixQuaternion.ToRotationColumnVector3();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(0), vector13fVector.at(0)));
        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(1), vector13fVector.at(1)));
        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(2), vector13fVector.at(2)));

        fourthQuaternion.FromRotationMatrix(matrix0);

        matrix1 = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-6f));

        fourthQuaternion.FromRotationColumnVector3(vector03fVector);

        vector13fVector = sixQuaternion.ToRotationColumnVector3();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(0), vector13fVector.at(0)));
        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(1), vector13fVector.at(1)));
        ASSERT_TRUE(Vector3ToolsF::Approximate(vector03fVector.at(2), vector13fVector.at(2)));

        fourthQuaternion.FromAxisAngle(vector0, firstFloat);

        const auto extract = fifthQuaternion.ToAngleAxis();

        vector1 = extract.GetAxis();
        secondFloat = extract.GetAngle();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector0, vector1));
        ASSERT_APPROXIMATE(firstFloat, secondFloat, 1e-5f);
    }
}

void Mathematics::QuaternionTesting::AccessTest()
{
    const QuaternionF firstQuaternion(3.0f, 5.0f, 6.0f, 7.0f);

    ASSERT_APPROXIMATE(firstQuaternion[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[1], 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[2], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstQuaternion[3], 7.0f, 1e-8f);

    QuaternionD secondQuaternion(23.0, 25.0, 62.0, 27.0);

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

void Mathematics::QuaternionTesting::OperatorCalculateTest()
{
    std::default_random_engine generator{};
    std::uniform_real_distribution<double> randomDistribution0{ -100.0f, 100.0f };
    std::uniform_real_distribution<double> randomDistribution1{ 0.0f, MathF::GetTwoPI() };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Vector3D vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        vector0.Normalize();

        const double firstDouble(randomDistribution1(generator));

        const QuaternionD firstQuaternion(vector0, firstDouble);

        Vector3D vector1(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        vector1.Normalize();

        const double secondDouble(randomDistribution1(generator));

        const QuaternionD secondQuaternion(vector1, secondDouble);

        const QuaternionD thirdQuaternion = firstQuaternion * secondQuaternion;

        const QuaternionD fourthQuaternion(Matrix3D(vector0, firstDouble) * Matrix3D(vector1, secondDouble));

        ASSERT_TRUE(Approximate(thirdQuaternion, fourthQuaternion, 1e-10) || Approximate(thirdQuaternion, -fourthQuaternion, 1e-10));

        const Matrix3D matrix0 = thirdQuaternion.ToRotationMatrix();
        const Matrix3D matrix1 = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix0, matrix1, 1e-10));

        QuaternionD fifthQuaternion(firstQuaternion);

        fifthQuaternion *= secondQuaternion;

        const Matrix3D matrix2 = fifthQuaternion.ToRotationMatrix();
        const Matrix3D matrix3 = fourthQuaternion.ToRotationMatrix();

        ASSERT_TRUE(Approximate(matrix2, matrix3, 1e-10));

        QuaternionD sixthQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        QuaternionD seventhQuaternion = -sixthQuaternion;

        ASSERT_APPROXIMATE(sixthQuaternion[0], -seventhQuaternion[0], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[1], -seventhQuaternion[1], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[2], -seventhQuaternion[2], 1e-10);
        ASSERT_APPROXIMATE(sixthQuaternion[3], -seventhQuaternion[3], 1e-10);

        fifthQuaternion *= secondQuaternion;
    }

    const QuaternionD eighthQuaternion(3.0, 5.1, 6.7, 8.71);
    const QuaternionD ninthQuaternion(13.1, 15.0, 16.71, 18.7);

    QuaternionD tenthQuaternion = eighthQuaternion + ninthQuaternion;

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
    ASSERT_APPROXIMATE(tenthQuaternion[1], 2.55, 1e-101);
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

void Mathematics::QuaternionTesting::ArithmeticCalculateTest()
{
    std::default_random_engine generator{};
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };
    std::uniform_real_distribution<float> randomDistribution1{ 0.0f, MathF::GetTwoPI() };
    std::uniform_real_distribution<float> thirdRandomDistribution{ 0.0f, 1.0f };
    std::uniform_int_distribution<> fourthRandomDistribution(0, 20);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        float length = firstQuaternion[0] * firstQuaternion[0] +
                       firstQuaternion[1] * firstQuaternion[1] +
                       firstQuaternion[2] * firstQuaternion[2] +
                       firstQuaternion[3] * firstQuaternion[3];

        ASSERT_APPROXIMATE(length, firstQuaternion.SquaredLength(), 1e-8f);

        length = MathF::Sqrt(length);

        ASSERT_APPROXIMATE(length, firstQuaternion.Length(), 1e-8f);

        QuaternionF secondQuaternion(firstQuaternion);

        secondQuaternion.Normalize();

        ASSERT_APPROXIMATE(firstQuaternion[0], secondQuaternion[0] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[1], secondQuaternion[1] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[2], secondQuaternion[2] * length, 1e-5f);
        ASSERT_APPROXIMATE(firstQuaternion[3], secondQuaternion[3] * length, 1e-5f);

        secondQuaternion = firstQuaternion.Inverse();

        QuaternionF thirdQuaternion = secondQuaternion * firstQuaternion;

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

        ASSERT_TRUE(Approximate(thirdQuaternion, firstQuaternion, 1e-3f));

        Vector3F vector0(randomDistribution0(generator), randomDistribution0(generator), randomDistribution0(generator));

        const Vector3F vector1 = firstQuaternion.Rotate(vector0);
        const Vector3F vector2 = firstQuaternion.ToRotationMatrix() * vector0;

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector1, vector2, 1e-03f));

        Vector3D vector3(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        vector3.Normalize();

        const double firstDouble(randomDistribution1(generator));

        QuaternionD fourthQuaternion(vector3, firstDouble);

        Vector3D vector4(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

        vector4.Normalize();

        const double secondDouble(randomDistribution1(generator));

        QuaternionD fifthQuaternion(vector4, secondDouble);

        QuaternionD sixthQuaternion;

        sixthQuaternion.Slerp(0.0, fourthQuaternion, fifthQuaternion);

        ASSERT_TRUE(Approximate(fourthQuaternion, sixthQuaternion, 1e-10));

        sixthQuaternion.Slerp(1.0, fourthQuaternion, fifthQuaternion);

        ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion, 1e-10) || Approximate(fifthQuaternion, -sixthQuaternion, 1e-10));

        const double firstT = thirdRandomDistribution(generator);

        sixthQuaternion.Slerp(firstT, fourthQuaternion, fifthQuaternion);

        double cosValue = Dot(fourthQuaternion, fifthQuaternion);
        double angle = MathD::ACos(cosValue);

        const int extraSpins = fourthRandomDistribution(generator);

        sixthQuaternion.SlerpExtraSpins(0.0, fourthQuaternion, fifthQuaternion, extraSpins);

        ASSERT_TRUE(Approximate(fourthQuaternion, sixthQuaternion, 1e-10));

        sixthQuaternion.SlerpExtraSpins(1.0, fourthQuaternion, fifthQuaternion, extraSpins);

        ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion, 1e-10) || Approximate(fifthQuaternion, -sixthQuaternion, 1e-10));

        sixthQuaternion.SlerpExtraSpins(firstT, fourthQuaternion, fifthQuaternion, extraSpins);

        cosValue = Dot(fourthQuaternion, fifthQuaternion);
        angle = MathD::ACos(cosValue);

        const double phase = MathD::GetPI() * extraSpins * firstT;

        const double coeff0 = MathD::Sin((1 - firstT) * angle - phase) / MathD::Sin(angle);
        const double coeff1 = MathD::Sin(firstT * angle + phase) / MathD::Sin(angle);

        QuaternionD seventhQuaternion = coeff0 * fourthQuaternion + coeff1 * fifthQuaternion;

        ASSERT_TRUE(Approximate(sixthQuaternion, seventhQuaternion, 1e-10));

        QuaternionD eighthQuaternion(randomDistribution0(generator),
                                     randomDistribution0(generator),
                                     randomDistribution0(generator),
                                     randomDistribution0(generator));

        eighthQuaternion.Normalize();

        QuaternionD ninthQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        ninthQuaternion.Normalize();

        QuaternionD tenthQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        tenthQuaternion.Normalize();

        // 使用另一种算法进行测试。
        seventhQuaternion = eighthQuaternion.Inverse();
        sixthQuaternion = ninthQuaternion.Inverse();
        fifthQuaternion = seventhQuaternion * ninthQuaternion;
        fourthQuaternion = sixthQuaternion * tenthQuaternion;
        seventhQuaternion = 0.25 * (fifthQuaternion.Log() - fourthQuaternion.Log());

        sixthQuaternion = ninthQuaternion * seventhQuaternion.Exp();

        sixthQuaternion.Normalize();

        fifthQuaternion.Intermediate(eighthQuaternion,
                                     ninthQuaternion,
                                     tenthQuaternion);

        fifthQuaternion.Normalize();

        ASSERT_TRUE(Approximate(sixthQuaternion, fifthQuaternion, 1e-10));

        QuaternionD eleventhQuaternion(randomDistribution0(generator),
                                       randomDistribution0(generator),
                                       randomDistribution0(generator),
                                       randomDistribution0(generator));

        eleventhQuaternion.Normalize();

        const double slerpT = 2.0 * firstT * (1.0 - firstT);

        seventhQuaternion.Slerp(firstT, eighthQuaternion, eleventhQuaternion);
        sixthQuaternion.Slerp(firstT, ninthQuaternion, tenthQuaternion);
        fifthQuaternion.Slerp(slerpT, seventhQuaternion, sixthQuaternion);

        seventhQuaternion.Squad(firstT, eighthQuaternion, ninthQuaternion, tenthQuaternion, eleventhQuaternion);

        ASSERT_TRUE(Approximate(seventhQuaternion, fifthQuaternion, 1e-10));

        vector3.Normalize();
        vector0.Normalize();

        vector4 = Vector3ToolsD::CrossProduct(vector3, Vector3D{ vector0 });

        vector4.Normalize();

        angle = Vector3ToolsD::GetVectorIncludedAngle(vector3, Vector3D{ vector0 });

        seventhQuaternion.FromAxisAngle(vector4, angle);
        fifthQuaternion.Align(vector3, Vector3D{ vector0 }, 1e-7);

        ASSERT_TRUE(Approximate(seventhQuaternion, fifthQuaternion, 1e-6));

        QuaternionD::QuaternionSwingTwistType quaternionSwingTwist = eighthQuaternion.DecomposeTwistTimesSwing(Vector3D{ vector0 }, 1e-7);

        seventhQuaternion = quaternionSwingTwist.GetTwist() * quaternionSwingTwist.GetSwing();

        ASSERT_TRUE(Approximate(seventhQuaternion, eighthQuaternion, 1e-6));
        ASSERT_APPROXIMATE(seventhQuaternion[3], eighthQuaternion[3], 1e-6);

        vector4 = eighthQuaternion.Rotate(Vector3D(vector0));
        fifthQuaternion.Align(Vector3D{ vector0 }, vector4, 1e-7);
        seventhQuaternion = eighthQuaternion * fifthQuaternion.Conjugate();

        ASSERT_TRUE(Approximate(seventhQuaternion, quaternionSwingTwist.GetTwist(), 1e-10));

        ASSERT_TRUE(Approximate(fifthQuaternion, quaternionSwingTwist.GetSwing(), 1e-10));

        quaternionSwingTwist = eighthQuaternion.DecomposeSwingTimesTwist(Vector3D{ vector0 }, 1e-7);

        seventhQuaternion = quaternionSwingTwist.GetSwing() * quaternionSwingTwist.GetTwist();

        ASSERT_TRUE(Approximate(seventhQuaternion, eighthQuaternion, 1e-6));

        vector4 = eighthQuaternion.Rotate(Vector3D(vector0));
        fifthQuaternion.Align(Vector3D{ vector0 }, vector4, 1e-7);
        seventhQuaternion = fifthQuaternion.Conjugate() * eighthQuaternion;

        ASSERT_TRUE(Approximate(fifthQuaternion, quaternionSwingTwist.GetSwing(), 1e-10));

        ASSERT_TRUE(Approximate(seventhQuaternion, quaternionSwingTwist.GetTwist(), 1e-10));

        const double dot = eighthQuaternion[0] * ninthQuaternion[0] +
                           eighthQuaternion[1] * ninthQuaternion[1] +
                           eighthQuaternion[2] * ninthQuaternion[2] +
                           eighthQuaternion[3] * ninthQuaternion[3];

        ASSERT_APPROXIMATE(dot, Dot(eighthQuaternion, ninthQuaternion), 1e-10);
    }
}

void Mathematics::QuaternionTesting::ClosestCalculateTest()
{
    std::default_random_engine generator{};
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        QuaternionF secondQuaternion(firstQuaternion[0],
                                     firstQuaternion[1],
                                     0.0f,
                                     0.0f);

        secondQuaternion.Normalize();

        QuaternionF thirdQuaternion = firstQuaternion.GetClosestX();

        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-7f));

        secondQuaternion = firstQuaternion;
        secondQuaternion[1] = 0.0f;
        secondQuaternion[3] = 0.0f;

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestY();

        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-7f));

        secondQuaternion = firstQuaternion;
        secondQuaternion[1] = 0.0f;
        secondQuaternion[2] = 0.0f;

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestZ();

        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-7f));

        firstQuaternion.Normalize();

        const double det = static_cast<double>(firstQuaternion[0]) * firstQuaternion[3] - static_cast<double>(firstQuaternion[1]) * firstQuaternion[2];

        if (MathD::FAbs(det) < 0.5 - MathD::GetZeroTolerance())
        {
            double discr = 1.0 - 4.0 * det * det;
            discr = MathD::Sqrt(MathD::FAbs(discr));
            const double a = static_cast<double>(firstQuaternion[0]) * firstQuaternion[1] + static_cast<double>(firstQuaternion[2]) * firstQuaternion[3];
            const double b = static_cast<double>(firstQuaternion[0]) * firstQuaternion[0] - static_cast<double>(firstQuaternion[1]) * firstQuaternion[1] + static_cast<double>(firstQuaternion[2]) * firstQuaternion[2] - static_cast<double>(firstQuaternion[3]) * firstQuaternion[3];

            double c0 = 0.0;
            double s0 = 0.0;

            if (0.0 <= b)
            {
                c0 = 0.5 * (discr + b);
                s0 = a;
            }
            else
            {
                c0 = a;
                s0 = 0.5 * (discr - b);
            }
            double invLength = MathD::InvSqrt(c0 * c0 + s0 * s0);
            c0 *= invLength;
            s0 *= invLength;

            double c1 = firstQuaternion[0] * c0 + firstQuaternion[1] * s0;
            double s1 = firstQuaternion[2] * c0 + firstQuaternion[3] * s0;
            invLength = MathD::InvSqrt(c1 * c1 + s1 * s1);
            c1 *= invLength;
            s1 *= invLength;

            thirdQuaternion = firstQuaternion.GetClosestXY();

            ASSERT_APPROXIMATE(thirdQuaternion[0], c0 * c1, 1e-6);
            ASSERT_APPROXIMATE(thirdQuaternion[1], s0 * c1, 1e-6);
            ASSERT_APPROXIMATE(thirdQuaternion[2], c0 * s1, 1e-6);
            ASSERT_APPROXIMATE(thirdQuaternion[3], s0 * s1, 1e-6);
        }
        else
        {
            const double invLength = MathD::InvSqrt(MathD::FAbs(det));

            thirdQuaternion = firstQuaternion.GetClosestXY();

            ASSERT_APPROXIMATE(thirdQuaternion[0], firstQuaternion[0] * invLength, 1e-8f);
            ASSERT_APPROXIMATE(thirdQuaternion[1], firstQuaternion[1] * invLength, 1e-8f);
            ASSERT_APPROXIMATE(thirdQuaternion[2], 0.0, 1e-8f);
            ASSERT_APPROXIMATE(thirdQuaternion[3], 0.0, 1e-8f);
        }

        secondQuaternion = firstQuaternion;
        secondQuaternion[3] = -firstQuaternion[3];

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestYX();
        QuaternionF fourthQuaternion = secondQuaternion.GetClosestXY();

        ASSERT_APPROXIMATE(fourthQuaternion[0], thirdQuaternion[0], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[1], thirdQuaternion[1], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[2], thirdQuaternion[2], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[3], -thirdQuaternion[3], 1e-5f);

        secondQuaternion = firstQuaternion;
        secondQuaternion[3] = firstQuaternion[2];
        secondQuaternion[2] = firstQuaternion[3];

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestZX();
        fourthQuaternion = secondQuaternion.GetClosestXY();

        ASSERT_APPROXIMATE(fourthQuaternion[0], thirdQuaternion[0], 1e-3f);
        ASSERT_APPROXIMATE(fourthQuaternion[1], thirdQuaternion[1], 1e-4f);
        ASSERT_APPROXIMATE(fourthQuaternion[2], thirdQuaternion[3], 1e-4f);
        ASSERT_APPROXIMATE(fourthQuaternion[3], thirdQuaternion[2], 1e-3f);

        secondQuaternion = firstQuaternion;
        secondQuaternion[3] = firstQuaternion[2];
        secondQuaternion[2] = -firstQuaternion[3];

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestXZ();
        fourthQuaternion = secondQuaternion.GetClosestXY();

        ASSERT_APPROXIMATE(fourthQuaternion[0], thirdQuaternion[0], 1e-4f);
        ASSERT_APPROXIMATE(fourthQuaternion[1], thirdQuaternion[1], 1e-5f);
        ASSERT_APPROXIMATE(-fourthQuaternion[2], thirdQuaternion[3], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[3], thirdQuaternion[2], 1e-4f);

        secondQuaternion = firstQuaternion;
        secondQuaternion[1] = firstQuaternion[2];
        secondQuaternion[2] = firstQuaternion[3];
        secondQuaternion[3] = firstQuaternion[1];

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestYZ();
        fourthQuaternion = secondQuaternion.GetClosestXY();

        ASSERT_APPROXIMATE(fourthQuaternion[0], thirdQuaternion[0], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[3], thirdQuaternion[1], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[2], thirdQuaternion[3], 1e-6f);
        ASSERT_APPROXIMATE(fourthQuaternion[1], thirdQuaternion[2], 1e-5f);

        secondQuaternion = firstQuaternion;
        secondQuaternion[1] = firstQuaternion[2];
        secondQuaternion[2] = firstQuaternion[3];
        secondQuaternion[3] = -firstQuaternion[1];

        secondQuaternion.Normalize();

        thirdQuaternion = firstQuaternion.GetClosestZY();
        fourthQuaternion = secondQuaternion.GetClosestXY();

        ASSERT_APPROXIMATE(fourthQuaternion[0], thirdQuaternion[0], 1e-4f);
        ASSERT_APPROXIMATE(-fourthQuaternion[3], thirdQuaternion[1], 1e-4f);
        ASSERT_APPROXIMATE(fourthQuaternion[2], thirdQuaternion[3], 1e-5f);
        ASSERT_APPROXIMATE(fourthQuaternion[1], thirdQuaternion[2], 1e-5f);
    }
}

void Mathematics::QuaternionTesting::FactorCalculateTest()
{
    std::default_random_engine generator{};
    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator),
                                    randomDistribution0(generator));

        QuaternionFactorF firstQuaternionFactor = firstQuaternion.FactorXYZ();

        QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(),
                                     firstQuaternionFactor.GetSinX(),
                                     0.0f, 0.0f);

        QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(),
                                    0.0f,
                                    firstQuaternionFactor.GetSinY(),
                                    0.0f);

        QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(),
                                     0.0f, 0.0f,
                                     firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = secondQuaternion * thirdQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));

        firstQuaternionFactor = firstQuaternion.FactorXZY();

        secondQuaternion = QuaternionF(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        thirdQuaternion = QuaternionF(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        fourthQuaternion = QuaternionF(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        fifthQuaternion = secondQuaternion * fourthQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));

        firstQuaternionFactor = firstQuaternion.FactorYZX();

        secondQuaternion = QuaternionF(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        thirdQuaternion = QuaternionF(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        fourthQuaternion = QuaternionF(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        fifthQuaternion = thirdQuaternion * fourthQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));

        firstQuaternionFactor = firstQuaternion.FactorYXZ();

        secondQuaternion = QuaternionF(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        thirdQuaternion = QuaternionF(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        fourthQuaternion = QuaternionF(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        fifthQuaternion = thirdQuaternion * secondQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));

        firstQuaternionFactor = firstQuaternion.FactorZXY();

        secondQuaternion = QuaternionF(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        thirdQuaternion = QuaternionF(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        fourthQuaternion = QuaternionF(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        fifthQuaternion = fourthQuaternion * secondQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));

        firstQuaternionFactor = firstQuaternion.FactorZYX();

        secondQuaternion = QuaternionF(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        thirdQuaternion = QuaternionF(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        fourthQuaternion = QuaternionF(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        fifthQuaternion = fourthQuaternion * thirdQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion, 1e-6f) || Approximate(firstQuaternion, -fifthQuaternion, 1e-6f));
    }
}

void Mathematics::QuaternionTesting::ConstraintsClosestCalculateTest()
{
    std::default_random_engine generator{};
    std::uniform_real_distribution<float> randomDistribution0{ -MathF::GetHalfPI(), MathF::GetHalfPI() };
    std::uniform_real_distribution<float> thirdRandomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const float firstAngle = randomDistribution0(generator);

        std::uniform_real_distribution<float> randomDistribution1(firstAngle, MathF::GetHalfPI());

        const float secondAngle = randomDistribution1(generator);

        const QuaternionConstraintsF firstQuaternionConstraints(firstAngle, secondAngle);

        QuaternionF firstQuaternion(thirdRandomDistribution(generator),
                                    thirdRandomDistribution(generator),
                                    thirdRandomDistribution(generator),
                                    thirdRandomDistribution(generator));

        QuaternionF secondQuaternion = firstQuaternion.GetClosestX();
        QuaternionF thirdQuaternion = firstQuaternion.GetClosestX(firstQuaternionConstraints);

        if (firstQuaternionConstraints.IsValid(secondQuaternion[0], secondQuaternion[1]))
        {
            // secondQuaternion和thirdQuaterniony应该是相等的
            ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));
        }
        else
        {
            // thirdQuaternion的值同边界点有关
            float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
            float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
            float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
            float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

            float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[1];

            float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[1];

            if (dotMinAngle < 0.0)
            {
                cosValueMin = -cosValueMin;
                sinValueMin = -sinValueMin;
                dotMinAngle = -dotMinAngle;
            }

            if (dotMaxAngle < 0.0)
            {
                cosValueMax = -cosValueMax;
                sinValueMax = -sinValueMax;
                dotMaxAngle = -dotMaxAngle;
            }

            if (dotMaxAngle <= dotMinAngle)
            {
                ASSERT_APPROXIMATE(cosValueMin, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMin, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[3], 1e-8f);
            }
            else
            {
                ASSERT_APPROXIMATE(cosValueMax, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMax, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[3], 1e-8f);
            }
        }

        secondQuaternion = firstQuaternion.GetClosestY();
        thirdQuaternion = firstQuaternion.GetClosestY(firstQuaternionConstraints);

        if (firstQuaternionConstraints.IsValid(secondQuaternion[0], secondQuaternion[2]))
        {
            // secondQuaternion和thirdQuaterniony应该是相等的
            ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));
        }
        else
        {
            // thirdQuaternion的值同边界点有关
            float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
            float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
            float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
            float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

            float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[2];

            float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[2];

            if (dotMinAngle < 0.0)
            {
                cosValueMin = -cosValueMin;
                sinValueMin = -sinValueMin;
                dotMinAngle = -dotMinAngle;
            }

            if (dotMaxAngle < 0.0)
            {
                cosValueMax = -cosValueMax;
                sinValueMax = -sinValueMax;
                dotMaxAngle = -dotMaxAngle;
            }

            if (dotMaxAngle <= dotMinAngle)
            {
                ASSERT_APPROXIMATE(cosValueMin, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMin, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[3], 1e-8f);
            }
            else
            {
                ASSERT_APPROXIMATE(cosValueMax, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMax, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[3], 1e-8f);
            }
        }

        secondQuaternion = firstQuaternion.GetClosestZ();
        thirdQuaternion = firstQuaternion.GetClosestZ(firstQuaternionConstraints);

        if (firstQuaternionConstraints.IsValid(secondQuaternion[0], secondQuaternion[3]))
        {
            // secondQuaternion和thirdQuaterniony应该是相等的
            ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));
        }
        else
        {
            // thirdQuaternion的值同边界点有关
            float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
            float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
            float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
            float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

            float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[3];

            float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[3];

            if (dotMinAngle < 0.0)
            {
                cosValueMin = -cosValueMin;
                sinValueMin = -sinValueMin;
                dotMinAngle = -dotMinAngle;
            }

            if (dotMaxAngle < 0.0)
            {
                cosValueMax = -cosValueMax;
                sinValueMax = -sinValueMax;
                dotMaxAngle = -dotMaxAngle;
            }

            if (dotMaxAngle <= dotMinAngle)
            {
                ASSERT_APPROXIMATE(cosValueMin, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMin, thirdQuaternion[3], 1e-8f);
            }
            else
            {
                ASSERT_APPROXIMATE(cosValueMax, thirdQuaternion[0], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[1], 1e-8f);
                ASSERT_APPROXIMATE(0.0, thirdQuaternion[2], 1e-8f);
                ASSERT_APPROXIMATE(sinValueMax, thirdQuaternion[3], 1e-8f);
            }
        }

        firstQuaternion.Normalize();

        const float thirdAngle = randomDistribution0(generator);

        std::uniform_real_distribution<float> fourthRandomDistribution(thirdAngle, MathF::GetHalfPI());

        const float fourthAngle = fourthRandomDistribution(generator);

        const QuaternionConstraintsF secondQuaternionConstraints(thirdAngle, fourthAngle);

        secondQuaternion = firstQuaternion.GetClosestXY();
        thirdQuaternion = firstQuaternion.GetClosestXY(firstQuaternionConstraints, secondQuaternionConstraints);

        float det = firstQuaternion[0] * firstQuaternion[3] - firstQuaternion[1] * firstQuaternion[2];

        if (MathF::FAbs(det) < 0.5f - MathF::GetZeroTolerance())
        {
            const float discr = MathF::Sqrt(MathF::FAbs(1.0f - 4.0f * det * det));

            const float a = firstQuaternion[0] * firstQuaternion[1] + firstQuaternion[2] * firstQuaternion[3];
            const float b = firstQuaternion[0] * firstQuaternion[0] - firstQuaternion[1] * firstQuaternion[1] +
                            firstQuaternion[2] * firstQuaternion[2] - firstQuaternion[3] * firstQuaternion[3];

            float c0 = 0.0f;
            float s0 = 0.0f;

            if (0.0f <= b)
            {
                c0 = 0.5f * (discr + b);
                s0 = a;
            }
            else
            {
                c0 = a;
                s0 = 0.5f * (discr - b);
            }
            float invLength = MathF::InvSqrt(c0 * c0 + s0 * s0);
            c0 *= invLength;
            s0 *= invLength;

            float c1 = firstQuaternion[0] * c0 + firstQuaternion[1] * s0;
            float s1 = firstQuaternion[2] * c0 + firstQuaternion[3] * s0;
            invLength = MathF::InvSqrt(c1 * c1 + s1 * s1);
            c1 *= invLength;
            s1 *= invLength;

            if (firstQuaternionConstraints.IsValid(c0, s0) && secondQuaternionConstraints.IsValid(c1, s1))
            {
                // secondQuaternion和thirdQuaterniony应该是相等的
                ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));
            }
            else
            {
                // thirdQuaternion的值同边界点有关
                QuaternionF r(firstQuaternionConstraints.GetCosMinAngle(), firstQuaternionConstraints.GetSinMinAngle(), 0.0f, 0.0f);
                QuaternionF rInv = r.Conjugate();
                QuaternionF prod = rInv * firstQuaternion;
                QuaternionF tmp = prod.GetClosestY(secondQuaternionConstraints);
                float dotOptAngle = Dot(prod, tmp);
                QuaternionF q = r * tmp;

                r = QuaternionF(firstQuaternionConstraints.GetCosMaxAngle(), firstQuaternionConstraints.GetSinMaxAngle(), 0.0f, 0.0f);

                rInv = r.Conjugate();
                prod = rInv * firstQuaternion;
                tmp = prod.GetClosestY(secondQuaternionConstraints);
                float dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = r * tmp;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMinAngle(), 0.0f, secondQuaternionConstraints.GetSinMinAngle(), 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestX(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMaxAngle(), 0.0f, secondQuaternionConstraints.GetSinMaxAngle(), 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestX(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-4f));
            }
        }
        else
        {
            float c0 = 0.0f;
            float s0 = 0.0f;
            float c1 = 0.0f;
            float s1 = 0.0f;

            if (0.0f < det)
            {
                const float minAngle = firstQuaternionConstraints.GetMinAngle() - secondQuaternionConstraints.GetMaxAngle();
                const float maxAngle = firstQuaternionConstraints.GetMaxAngle() - secondQuaternionConstraints.GetMinAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestX(con);

                float angle = MathF::ATan2(tmp[1], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[1] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle <= firstQuaternionConstraints.GetMaxAngle() - secondQuaternionConstraints.GetMaxAngle())
                {
                    c1 = secondQuaternionConstraints.GetCosMaxAngle();
                    s1 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = secondQuaternionConstraints.GetMaxAngle() + angle;
                    c0 = MathF::Cos(angle);
                    s0 = MathF::Sin(angle);
                }
                else
                {
                    c0 = firstQuaternionConstraints.GetCosMaxAngle();
                    s0 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = firstQuaternionConstraints.GetMaxAngle() - angle;
                    c1 = MathF::Cos(angle);
                    s1 = MathF::Sin(angle);
                }
            }
            else
            {
                const float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
                const float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestX(con);

                float angle = MathF::ATan2(tmp[1], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[1] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle >= firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMaxAngle())
                {
                    c1 = secondQuaternionConstraints.GetCosMaxAngle();
                    s1 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - secondQuaternionConstraints.GetMaxAngle();
                    c0 = MathF::Cos(angle);
                    s0 = MathF::Sin(angle);
                }
                else
                {
                    c0 = firstQuaternionConstraints.GetCosMaxAngle();
                    s0 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - firstQuaternionConstraints.GetMaxAngle();
                    c1 = MathF::Cos(angle);
                    s1 = MathF::Sin(angle);
                }
            }

            QuaternionF q(c0 * c1, s0 * c1, c0 * s1, s0 * s1);

            if (Dot(firstQuaternion, q) < 0.0f)
            {
                q = -q;
            }

            ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-8f));
        }

        secondQuaternion = firstQuaternion;
        secondQuaternion[3] = -secondQuaternion[3];
        secondQuaternion = secondQuaternion.GetClosestXY(secondQuaternionConstraints, firstQuaternionConstraints);

        secondQuaternion[3] = -secondQuaternion[3];

        thirdQuaternion = firstQuaternion.GetClosestYX(firstQuaternionConstraints, secondQuaternionConstraints);

        // secondQuaternion和thirdQuaterniony应该是相等的
        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));

        secondQuaternion = firstQuaternion.GetClosestZX();
        thirdQuaternion = firstQuaternion.GetClosestZX(firstQuaternionConstraints, secondQuaternionConstraints);

        det = firstQuaternion[0] * firstQuaternion[2] - firstQuaternion[1] * firstQuaternion[3];

        if (MathF::FAbs(det) < 0.5f - MathF::GetZeroTolerance())
        {
            const float discr = MathF::Sqrt(MathF::FAbs(1.0f - 4.0f * det * det));

            const float a = firstQuaternion[0] * firstQuaternion[3] +
                            firstQuaternion[1] * firstQuaternion[2];
            const float b = firstQuaternion[0] * firstQuaternion[0] +
                            firstQuaternion[1] * firstQuaternion[1] -
                            firstQuaternion[2] * firstQuaternion[2] -
                            firstQuaternion[3] * firstQuaternion[3];

            float c2 = 0.0f;
            float s2 = 0.0f;

            if (0.0f <= b)
            {
                c2 = 0.5f * (discr + b);
                s2 = a;
            }
            else
            {
                c2 = a;
                s2 = 0.5f * (discr - b);
            }
            float invLength = MathF::InvSqrt(c2 * c2 + s2 * s2);
            c2 *= invLength;
            s2 *= invLength;

            float c0 = firstQuaternion[0] * c2 + firstQuaternion[3] * s2;
            float s0 = firstQuaternion[1] * c2 + firstQuaternion[2] * s2;
            invLength = MathF::InvSqrt(c0 * c0 + s0 * s0);
            c0 *= invLength;
            s0 *= invLength;

            if (firstQuaternionConstraints.IsValid(c2, s2) && secondQuaternionConstraints.IsValid(c0, s0))
            {
                // secondQuaternion和thirdQuaterniony应该是相等的
                ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-6f));
            }
            else
            {
                // thirdQuaternion的值同边界点有关
                QuaternionF r(firstQuaternionConstraints.GetCosMinAngle(), 0.0f, 0.0f, firstQuaternionConstraints.GetSinMinAngle());
                QuaternionF rInv = r.Conjugate();
                QuaternionF prod = rInv * firstQuaternion;
                QuaternionF tmp = prod.GetClosestX(secondQuaternionConstraints);
                float dotOptAngle = Dot(prod, tmp);
                QuaternionF q = r * tmp;

                r = QuaternionF(firstQuaternionConstraints.GetCosMaxAngle(), 0.0f, 0.0f, firstQuaternionConstraints.GetSinMaxAngle());

                rInv = r.Conjugate();
                prod = rInv * firstQuaternion;
                tmp = prod.GetClosestX(secondQuaternionConstraints);
                float dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = r * tmp;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMinAngle(), secondQuaternionConstraints.GetSinMinAngle(), 0.0f, 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestZ(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMaxAngle(), secondQuaternionConstraints.GetSinMaxAngle(), 0.0f, 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestZ(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-4f));
            }
        }
        else
        {
            float c0 = 0.0f;
            float s0 = 0.0f;
            float c2 = 0.0f;
            float s2 = 0.0f;

            if (0.0f < det)
            {
                const float minAngle = secondQuaternionConstraints.GetMinAngle() - firstQuaternionConstraints.GetMaxAngle();
                const float maxAngle = secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMinAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestX(con);

                float angle = MathF::ATan2(tmp[1], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[1] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle <= secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMaxAngle())
                {
                    c2 = firstQuaternionConstraints.GetCosMaxAngle();
                    s2 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = firstQuaternionConstraints.GetMaxAngle() + angle;
                    c0 = MathF::Cos(angle);
                    s0 = MathF::Sin(angle);
                }
                else
                {
                    c0 = secondQuaternionConstraints.GetCosMaxAngle();
                    s0 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = secondQuaternionConstraints.GetMaxAngle() - angle;
                    c2 = MathF::Cos(angle);
                    s2 = MathF::Sin(angle);
                }
            }
            else
            {
                const float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
                const float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestX(con);

                float angle = MathF::ATan2(tmp[1], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[1] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle >= secondQuaternionConstraints.GetMinAngle() + firstQuaternionConstraints.GetMaxAngle())
                {
                    c2 = firstQuaternionConstraints.GetCosMaxAngle();
                    s2 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - firstQuaternionConstraints.GetMaxAngle();
                    c0 = MathF::Cos(angle);
                    s0 = MathF::Sin(angle);
                }
                else
                {
                    c2 = secondQuaternionConstraints.GetCosMaxAngle();
                    s2 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - secondQuaternionConstraints.GetMaxAngle();
                    c0 = MathF::Cos(angle);
                    s0 = MathF::Sin(angle);
                }
            }

            QuaternionF q(c2 * c0, c2 * s0, s0 * s2, c0 * s2);

            if (Dot(firstQuaternion, q) < 0.0f)
            {
                q = -q;
            }

            ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-8f));
        }

        secondQuaternion = firstQuaternion;
        secondQuaternion[2] = -secondQuaternion[2];
        secondQuaternion = secondQuaternion.GetClosestZX(secondQuaternionConstraints, firstQuaternionConstraints);

        secondQuaternion[2] = -secondQuaternion[2];

        thirdQuaternion = firstQuaternion.GetClosestXZ(firstQuaternionConstraints, secondQuaternionConstraints);

        // secondQuaternion和thirdQuaterniony应该是相等的
        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));

        secondQuaternion = firstQuaternion.GetClosestZY();
        thirdQuaternion = firstQuaternion.GetClosestZY(firstQuaternionConstraints, secondQuaternionConstraints);

        det = firstQuaternion[0] * firstQuaternion[1] + firstQuaternion[2] * firstQuaternion[3];

        if (MathF::FAbs(det) < 0.5f - MathF::GetZeroTolerance())
        {
            const float discr = MathF::Sqrt(MathF::FAbs(1.0f - 4.0f * det * det));

            const float a = firstQuaternion[0] * firstQuaternion[3] -
                            firstQuaternion[1] * firstQuaternion[2];
            const float b = firstQuaternion[0] * firstQuaternion[0] -
                            firstQuaternion[1] * firstQuaternion[1] +
                            firstQuaternion[2] * firstQuaternion[2] -
                            firstQuaternion[3] * firstQuaternion[3];

            float c2 = 0.0f;
            float s2 = 0.0f;

            if (0.0f <= b)
            {
                c2 = 0.5f * (discr + b);
                s2 = a;
            }
            else
            {
                c2 = a;
                s2 = 0.5f * (discr - b);
            }
            float invLength = MathF::InvSqrt(c2 * c2 + s2 * s2);
            c2 *= invLength;
            s2 *= invLength;

            float c1 = firstQuaternion[0] * c2 + firstQuaternion[3] * s2;
            float s1 = firstQuaternion[2] * c2 - firstQuaternion[1] * s2;
            invLength = MathF::InvSqrt(c1 * c1 + s1 * s1);
            c1 *= invLength;
            s1 *= invLength;

            if (firstQuaternionConstraints.IsValid(c2, s2) && secondQuaternionConstraints.IsValid(c1, s1))
            {
                // secondQuaternion和thirdQuaterniony应该是相等的
                ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-6f));
            }
            else
            {
                // thirdQuaternion的值同边界点有关
                QuaternionF r(firstQuaternionConstraints.GetCosMinAngle(), 0.0f, 0.0f, firstQuaternionConstraints.GetSinMinAngle());
                QuaternionF rInv = r.Conjugate();
                QuaternionF prod = rInv * firstQuaternion;
                QuaternionF tmp = prod.GetClosestY(secondQuaternionConstraints);
                float dotOptAngle = Dot(prod, tmp);
                QuaternionF q = r * tmp;

                r = QuaternionF(firstQuaternionConstraints.GetCosMaxAngle(), 0.0f, 0.0f, firstQuaternionConstraints.GetSinMaxAngle());

                rInv = r.Conjugate();
                prod = rInv * firstQuaternion;
                tmp = prod.GetClosestY(secondQuaternionConstraints);
                float dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = r * tmp;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMinAngle(), 0.0f, secondQuaternionConstraints.GetSinMinAngle(), 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestZ(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                r = QuaternionF(secondQuaternionConstraints.GetCosMaxAngle(), 0.0f, secondQuaternionConstraints.GetSinMaxAngle(), 0.0f);
                rInv = r.Conjugate();
                prod = firstQuaternion * rInv;
                tmp = prod.GetClosestZ(firstQuaternionConstraints);
                dotAngle = Dot(prod, tmp);
                if (dotAngle > dotOptAngle)
                {
                    q = tmp * r;
                    dotOptAngle = dotAngle;
                }

                ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-4f));
            }
        }
        else
        {
            float c1 = 0.0f;
            float s1 = 0.0f;
            float c2 = 0.0f;
            float s2 = 0.0f;

            if (0.0f < det)
            {
                const float minAngle = secondQuaternionConstraints.GetMinAngle() - firstQuaternionConstraints.GetMaxAngle();
                const float maxAngle = secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMinAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestY(con);

                float angle = MathF::ATan2(tmp[2], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[2] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle <= secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMaxAngle())
                {
                    c2 = firstQuaternionConstraints.GetCosMaxAngle();
                    s2 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = firstQuaternionConstraints.GetMaxAngle() + angle;
                    c1 = MathF::Cos(angle);
                    s1 = MathF::Sin(angle);
                }
                else
                {
                    c1 = secondQuaternionConstraints.GetCosMaxAngle();
                    s1 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = secondQuaternionConstraints.GetMaxAngle() - angle;
                    c2 = MathF::Cos(angle);
                    s2 = MathF::Sin(angle);
                }
            }
            else
            {
                const float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
                const float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
                const QuaternionConstraintsF con(minAngle, maxAngle);

                QuaternionF tmp = firstQuaternion.GetClosestY(con);

                float angle = MathF::ATan2(tmp[2], tmp[0]);
                if (angle < minAngle || angle > maxAngle)
                {
                    angle -= (tmp[2] >= 0.0f ? MathF::GetPI() : -MathF::GetPI());
                }

                if (angle >= secondQuaternionConstraints.GetMinAngle() + firstQuaternionConstraints.GetMaxAngle())
                {
                    c2 = firstQuaternionConstraints.GetCosMaxAngle();
                    s2 = firstQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - firstQuaternionConstraints.GetMaxAngle();
                    c1 = MathF::Cos(angle);
                    s1 = MathF::Sin(angle);
                }
                else
                {
                    c1 = secondQuaternionConstraints.GetCosMaxAngle();
                    s1 = secondQuaternionConstraints.GetSinMaxAngle();
                    angle = angle - secondQuaternionConstraints.GetMaxAngle();
                    c2 = MathF::Cos(angle);
                    s2 = MathF::Sin(angle);
                }
            }

            QuaternionF q(c2 * c1, -s1 * s2, s1 * c2, c1 * s2);

            if (Dot(firstQuaternion, q) < 0.0f)
            {
                q = -q;
            }

            ASSERT_TRUE(Approximate(q, thirdQuaternion, 1e-8f));
        }

        secondQuaternion = firstQuaternion;
        secondQuaternion[1] = -secondQuaternion[1];
        secondQuaternion = secondQuaternion.GetClosestZY(secondQuaternionConstraints, firstQuaternionConstraints);

        secondQuaternion[1] = -secondQuaternion[1];

        thirdQuaternion = firstQuaternion.GetClosestYZ(firstQuaternionConstraints, secondQuaternionConstraints);

        // secondQuaternion和thirdQuaterniony应该是相等的
        ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion, 1e-8f));
    }
}

void Mathematics::QuaternionTesting::CompareTest()
{
    std::default_random_engine generator{};

    std::uniform_real_distribution<float> randomDistribution0{ -100.0f, 100.0f };

    QuaternionF firstQuaternion(randomDistribution0(generator),
                                randomDistribution0(generator),
                                randomDistribution0(generator),
                                randomDistribution0(generator));

    QuaternionF secondQuaternion(randomDistribution0(generator),
                                 randomDistribution0(generator),
                                 randomDistribution0(generator),
                                 randomDistribution0(generator));

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

    GetStream() << "以下是调试信息：\n";
    GetStream() << firstQuaternion << '\n';
    GetStream() << secondQuaternion << '\n';
}
