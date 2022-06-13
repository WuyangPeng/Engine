///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:50)

#include "Matrix2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

namespace Mathematics
{
    template class Matrix2<float>;
    template class Matrix2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Matrix2Testing)

void Mathematics::Matrix2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
}

void Mathematics::Matrix2Testing::ConstructionTest()
{
    Matrix2F firstMatrix(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 0.0f, 1e-8f);

    Matrix2F secondMatrix(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 1.0f, 1e-8f);

    Matrix2D thirdMatrix(3.0, 6.0, 1.0, 2.0);

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 2.0, 1e-10);

    vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0 };

    Matrix2D fourthMatrix(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 2.0, 1e-10);

    Matrix2D fifthMatrix(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(fifthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 1), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 1), 2.0, 1e-10);

    const Vector2F firstVector(6.0f, 3.0f);
    const Vector2F secondVector(8.0f, 3.1f);

    Matrix2F sixthMatrix(firstVector, secondVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(sixthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(1, 1), 3.1f, 1e-8f);

    Matrix2F seventhMatrix(firstVector, secondVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(seventhMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(1, 1), 3.1f, 1e-8f);

    vector<Vector2F> Vector2Vector{ firstVector, secondVector };

    Matrix2F eighthMatrix(Vector2Vector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(eighthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(1, 1), 3.1f, 1e-8f);

    Matrix2F ninthMatrix(Vector2Vector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(ninthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 1), 3.1f, 1e-8f);

    Matrix2D tenthMatrix(6.0, 89.0);

    ASSERT_APPROXIMATE(tenthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(1, 1), 89.0, 1e-10);

    Matrix2D eleventhMatrix(MathD::GetHalfPI() / 3.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), cos(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), -sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), cos(MathD::GetHalfPI() / 3.0), 1e-10);

    Matrix2F twelfthMatrix(firstVector, secondVector);

    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(), twelfthMatrix(0, 0), 1e-8f);
    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(), twelfthMatrix(0, 1), 1e-8f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(), twelfthMatrix(1, 0), 1e-8f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(), twelfthMatrix(1, 1), 1e-8f);

    eleventhMatrix.MakeZero();

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 0.0, 1e-10);

    eleventhMatrix.MakeIdentity();

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 1.0, 1e-10);

    eleventhMatrix.MakeDiagonal(6.0, 9.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 9.0, 1e-10);

    eleventhMatrix.MakeRotation(MathD::GetHalfPI() / 6.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), cos(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), -sin(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), sin(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), cos(MathD::GetHalfPI() / 6.0), 1e-10);

    ninthMatrix.MakeTensorProduct(firstVector, secondVector);

    ASSERT_APPROXIMATE(twelfthMatrix(0, 0), ninthMatrix(0, 0), 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(0, 1), ninthMatrix(0, 1), 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 0), ninthMatrix(1, 0), 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 1), ninthMatrix(1, 1), 1e-8f);

    eleventhMatrix = tenthMatrix;

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 89.0, 1e-10);

    Matrix2D thirteenthMatrix(eleventhMatrix);

    ASSERT_APPROXIMATE(thirteenthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 1), 89.0, 1e-10);
}

void Mathematics::Matrix2Testing::AccessTest()
{
    const Matrix2F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 3.2f, 1e-8f);

    Matrix2D secondMatrix(9.2, 1.0, 4.2, 5.2);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 4.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 5.2, 1e-10);
}

void Mathematics::Matrix2Testing::OperatorCalculateTest()
{
    const Matrix2F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f);

    Matrix2F secondMatrix = -firstMatrix;

    ASSERT_APPROXIMATE(secondMatrix(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), -3.2f, 1e-8f);

    Matrix2F thirdMatrix(9.2f, 3.0f, 2.0f, 9.0f);

    thirdMatrix += secondMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -6.1f, 1e6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 5.8f, 1e-8f);

    thirdMatrix -= firstMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 2.6f, 1e-6f);

    thirdMatrix *= 6.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 15.6f, 1e-8f);

    thirdMatrix /= 2.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 7.8f, 1e-8f);

    Matrix2F fourthMatrix1 = firstMatrix + thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix1(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix1(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 0), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 1), 11.0f, 1e-8f);

    fourthMatrix1 = firstMatrix - thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix1(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix1(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 0), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 1), -4.6f, 1e-6f);

    fourthMatrix1 = firstMatrix * 5.0f;

    ASSERT_APPROXIMATE(fourthMatrix1(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 0), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 1), 16.0f, 1e-8f);

    fourthMatrix1 = 3.0f * firstMatrix;

    ASSERT_APPROXIMATE(fourthMatrix1(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 0), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 1), 9.6f, 1e-8f);

    fourthMatrix1 = firstMatrix / 2.0f;

    ASSERT_APPROXIMATE(fourthMatrix1(0, 0), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(0, 1), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 0), 4.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix1(1, 1), 1.6f, 1e-8f);

    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix2F fifthMatrix{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

        Matrix2F sixthMatrix{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

        Matrix2F seventhMatrix(sixthMatrix);

        seventhMatrix *= fifthMatrix;

        const Matrix2F fourthMatrix(sixthMatrix(0, 0) * fifthMatrix(0, 0) + sixthMatrix(0, 1) * fifthMatrix(1, 0),
                                    sixthMatrix(0, 0) * fifthMatrix(0, 1) + sixthMatrix(0, 1) * fifthMatrix(1, 1),
                                    sixthMatrix(1, 0) * fifthMatrix(0, 0) + sixthMatrix(1, 1) * fifthMatrix(1, 0),
                                    sixthMatrix(1, 0) * fifthMatrix(0, 1) + sixthMatrix(1, 1) * fifthMatrix(1, 1));

        ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix, 1e-4f));

        seventhMatrix = sixthMatrix * fifthMatrix;

        ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix, 1e-8f));

        Matrix2F::Vector2 firstVector(randomDistribution(generator),
                                      randomDistribution(generator));

        const Matrix2F::Vector2 secondVector = seventhMatrix * firstVector;
        const Matrix2F::Vector2 thirdVector = firstVector * seventhMatrix;

        Matrix2F::Vector2 fourthVector(seventhMatrix(0, 0) * firstVector[0] + seventhMatrix(0, 1) * firstVector[1],
                                       seventhMatrix(1, 0) * firstVector[0] + seventhMatrix(1, 1) * firstVector[1]);

        ASSERT_TRUE(Vector2ToolsF::Approximate(secondVector, fourthVector, 1e-3f));

        fourthVector[0] = seventhMatrix(0, 0) * firstVector[0] + seventhMatrix(1, 0) * firstVector[1];

        fourthVector[1] = seventhMatrix(0, 1) * firstVector[0] + seventhMatrix(1, 1) * firstVector[1];

        ASSERT_TRUE(Vector2ToolsF::Approximate(thirdVector, fourthVector, 1e-3f));

        Matrix2F eighthMatrix = TransposeTimes(fifthMatrix, sixthMatrix);
        Matrix2F ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TransposeTimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));
    }
}

void Mathematics::Matrix2Testing::ArithmeticCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };
    const uniform_real<float> angleRandomDistribution(0.0f, MathF::GetHalfPI());

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Matrix2F::Vector2 firstVector(randomDistribution(generator),
                                            randomDistribution(generator));

        const Matrix2F::Vector2 secondVector(randomDistribution(generator),
                                             randomDistribution(generator));

        Matrix2F firstMatrix(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const float qForm = firstMatrix.QuadraticForm(firstVector, secondVector);

        const float testQFormValue = Vector2ToolsF::DotProduct(firstVector, firstMatrix * secondVector);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix2F secondMatrix = firstMatrix.Transpose();

        ASSERT_APPROXIMATE(firstMatrix(0, 0), secondMatrix(0, 0), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(0, 1), secondMatrix(1, 0), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(1, 0), secondMatrix(0, 1), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(1, 1), secondMatrix(1, 1), 1e-8f);

        const float determinant = secondMatrix(0, 0) * secondMatrix(1, 1) - secondMatrix(0, 1) * secondMatrix(1, 0);

        ASSERT_APPROXIMATE(determinant, secondMatrix.Determinant(), 1e-3f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix2F thirdMatrix = secondMatrix.Inverse();

            Matrix2F fourthMatrix = secondMatrix * thirdMatrix;

            ASSERT_APPROXIMATE(fourthMatrix(0, 0), 1.0f, 1e-5f);
            ASSERT_APPROXIMATE(fourthMatrix(0, 1), 0.0f, 1e-5f);
            ASSERT_APPROXIMATE(fourthMatrix(1, 0), 0.0f, 1e-5f);
            ASSERT_APPROXIMATE(fourthMatrix(1, 1), 1.0f, 1e-5f);

            Matrix2F fifthMatrix = secondMatrix.Adjoint();
            fifthMatrix /= determinant;

            fourthMatrix = fifthMatrix * secondMatrix;

            ASSERT_TRUE(Approximate(fourthMatrix, Matrix2F::GetIdentity(), 1e-5f));
        }

        const float angle = angleRandomDistribution(generator);

        Matrix2F sixthMatrix(angle);

        ASSERT_APPROXIMATE(angle, sixthMatrix.ExtractAngle(), 1e-7f);

        Matrix2F seventhMatrix(sixthMatrix);

        seventhMatrix.Orthonormalize();

        Vector2F thirdVector(sixthMatrix(0, 0), sixthMatrix(1, 0));
        const Vector2F fourthVector(seventhMatrix(0, 0), seventhMatrix(1, 0));

        thirdVector.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(thirdVector, fourthVector, 1e-7f));

        Vector2F fifthVector(sixthMatrix(0, 1), sixthMatrix(1, 1));
        const Vector2F sixthVector(seventhMatrix(0, 1), seventhMatrix(1, 1));

        fifthVector -= (Vector2ToolsF::DotProduct(fourthVector, fifthVector)) * fourthVector;

        fifthVector.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(fifthVector, sixthVector, 1e-7f));

        const Matrix2D eighthMatrix(randomDistribution(generator), angle, angle, randomDistribution(generator));

        const Matrix2D::Matrix2EigenDecomposition eigenDecomposition = eighthMatrix.EigenDecomposition(1e-10);

        const Matrix2D rotation = eigenDecomposition.GetRotation();
        const Matrix2D diagonal = eigenDecomposition.GetDiagonal();

        const Matrix2D ninthMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(ninthMatrix, eighthMatrix, 1e-10));
    }
}
