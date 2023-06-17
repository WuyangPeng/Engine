///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:26)

#include "Matrix2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Algebra/Vector2Tools.h"

#include <random>

namespace Mathematics
{
    template class Matrix2<float>;
    template class Matrix2<double>;
}

Mathematics::Matrix2Testing::Matrix2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix2Testing)

void Mathematics::Matrix2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
}

void Mathematics::Matrix2Testing::ConstructionTest()
{
    Matrix2F matrix0(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(matrix0(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 0.0f, 1e-8f);

    Matrix2F matrix1(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(matrix1(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), 1.0f, 1e-8f);

    Matrix2D matrix2(3.0, 6.0, 1.0, 2.0);

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 1), 2.0, 1e-10);

    std::vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0 };

    Matrix2D matrix3(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix3(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 1), 2.0, 1e-10);

    Matrix2D matrix4(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix4(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 2.0, 1e-10);

    const Vector2F vector0(6.0f, 3.0f);
    const Vector2F vector1(8.0f, 3.1f);

    Matrix2F matrix5(vector0, vector1, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix5(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(1, 1), 3.1f, 1e-8f);

    Matrix2F matrix6(vector0, vector1, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix6(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(1, 1), 3.1f, 1e-8f);

    std::vector<Vector2F> Vector2Vector{ vector0, vector1 };

    Matrix2F matrix7(Vector2Vector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix7(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(1, 1), 3.1f, 1e-8f);

    Matrix2F matrix8(Vector2Vector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix8(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 1), 3.1f, 1e-8f);

    Matrix2D matrix9(6.0, 89.0);

    ASSERT_APPROXIMATE(matrix9(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(1, 1), 89.0, 1e-10);

    Matrix2D matrix10(MathD::GetHalfPI() / 3.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), cos(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), -sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), cos(MathD::GetHalfPI() / 3.0), 1e-10);

    Matrix2F matrix11(vector0, vector1);

    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetX(), matrix11(0, 0), 1e-8f);
    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetY(), matrix11(0, 1), 1e-8f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetX(), matrix11(1, 0), 1e-8f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetY(), matrix11(1, 1), 1e-8f);

    matrix10.MakeZero();

    ASSERT_APPROXIMATE(matrix10(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 0.0, 1e-10);

    matrix10.MakeIdentity();

    ASSERT_APPROXIMATE(matrix10(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 1.0, 1e-10);

    matrix10.MakeDiagonal(6.0, 9.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 9.0, 1e-10);

    matrix10.MakeRotation(MathD::GetHalfPI() / 6.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), cos(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), -sin(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), sin(MathD::GetHalfPI() / 6.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), cos(MathD::GetHalfPI() / 6.0), 1e-10);

    matrix8.MakeTensorProduct(vector0, vector1);

    ASSERT_APPROXIMATE(matrix11(0, 0), matrix8(0, 0), 1e-8f);
    ASSERT_APPROXIMATE(matrix11(0, 1), matrix8(0, 1), 1e-8f);
    ASSERT_APPROXIMATE(matrix11(1, 0), matrix8(1, 0), 1e-8f);
    ASSERT_APPROXIMATE(matrix11(1, 1), matrix8(1, 1), 1e-8f);

    matrix10 = matrix9;

    ASSERT_APPROXIMATE(matrix10(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 89.0, 1e-10);

    Matrix2D thirteenthMatrix(matrix10);

    ASSERT_APPROXIMATE(thirteenthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 1), 89.0, 1e-10);
}

void Mathematics::Matrix2Testing::AccessTest()
{
    const Matrix2F matrix0(3.0f, 4.0f, 8.1f, 3.2f);

    ASSERT_APPROXIMATE(matrix0(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 3.2f, 1e-8f);

    Matrix2D matrix1(9.2, 1.0, 4.2, 5.2);

    ASSERT_APPROXIMATE(matrix1(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 5.2, 1e-10);
}

void Mathematics::Matrix2Testing::OperatorCalculateTest()
{
    const Matrix2F matrix0(3.0f, 4.0f, 8.1f, 3.2f);

    Matrix2F matrix1 = -matrix0;

    ASSERT_APPROXIMATE(matrix1(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), -3.2f, 1e-8f);

    Matrix2F matrix2(9.2f, 3.0f, 2.0f, 9.0f);

    matrix2 += matrix1;

    ASSERT_APPROXIMATE(matrix2(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -6.1f, 1e6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 5.8f, 1e-8f);

    matrix2 -= matrix0;

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 2.6f, 1e-6f);

    matrix2 *= 6.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 15.6f, 1e-8f);

    matrix2 /= 2.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 7.8f, 1e-8f);

    Matrix2F matrix31 = matrix0 + matrix2;

    ASSERT_APPROXIMATE(matrix31(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix31(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 0), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 1), 11.0f, 1e-8f);

    matrix31 = matrix0 - matrix2;

    ASSERT_APPROXIMATE(matrix31(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix31(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 0), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix31(1, 1), -4.6f, 1e-6f);

    matrix31 = matrix0 * 5.0f;

    ASSERT_APPROXIMATE(matrix31(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 0), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 1), 16.0f, 1e-8f);

    matrix31 = 3.0f * matrix0;

    ASSERT_APPROXIMATE(matrix31(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 0), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix31(1, 1), 9.6f, 1e-8f);

    matrix31 = matrix0 / 2.0f;

    ASSERT_APPROXIMATE(matrix31(0, 0), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(0, 1), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 0), 4.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix31(1, 1), 1.6f, 1e-8f);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix2F matrix4{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

        Matrix2F matrix5{ randomDistribution(generator), randomDistribution(generator), randomDistribution(generator), randomDistribution(generator) };

        Matrix2F matrix6(matrix5);

        matrix6 *= matrix4;

        const Matrix2F matrix3(matrix5(0, 0) * matrix4(0, 0) + matrix5(0, 1) * matrix4(1, 0),
                               matrix5(0, 0) * matrix4(0, 1) + matrix5(0, 1) * matrix4(1, 1),
                               matrix5(1, 0) * matrix4(0, 0) + matrix5(1, 1) * matrix4(1, 0),
                               matrix5(1, 0) * matrix4(0, 1) + matrix5(1, 1) * matrix4(1, 1));

        ASSERT_TRUE(Approximate(matrix3, matrix6, 1e-4f));

        matrix6 = matrix5 * matrix4;

        ASSERT_TRUE(Approximate(matrix3, matrix6, 1e-8f));

        Matrix2F::Vector2 vector0(randomDistribution(generator),
                                  randomDistribution(generator));

        const Matrix2F::Vector2 vector1 = matrix6 * vector0;
        const Matrix2F::Vector2 vector2 = vector0 * matrix6;

        Matrix2F::Vector2 vector3(matrix6(0, 0) * vector0[0] + matrix6(0, 1) * vector0[1],
                                  matrix6(1, 0) * vector0[0] + matrix6(1, 1) * vector0[1]);

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector1, vector3, 1e-3f));

        vector3[0] = matrix6(0, 0) * vector0[0] + matrix6(1, 0) * vector0[1];

        vector3[1] = matrix6(0, 1) * vector0[0] + matrix6(1, 1) * vector0[1];

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector2, vector3, 1e-3f));

        Matrix2F matrix7 = TransposeTimes(matrix4, matrix5);
        Matrix2F matrix8 = matrix4.Transpose() * matrix5;

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TimesTranspose(matrix4, matrix5);
        matrix8 = matrix4 * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TransposeTimesTranspose(matrix4, matrix5);
        matrix8 = matrix4.Transpose() * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));
    }
}

void Mathematics::Matrix2Testing::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<float> randomDistribution{ -10.0f, 10.0f };
    const std::uniform_real<float> angleRandomDistribution(0.0f, MathF::GetHalfPI());

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const Matrix2F::Vector2 vector0(randomDistribution(generator),
                                        randomDistribution(generator));

        const Matrix2F::Vector2 vector1(randomDistribution(generator),
                                        randomDistribution(generator));

        Matrix2F matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const float qForm = matrix0.QuadraticForm(vector0, vector1);

        const float testQFormValue = Vector2ToolsF::DotProduct(vector0, matrix0 * vector1);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix2F matrix1 = matrix0.Transpose();

        ASSERT_APPROXIMATE(matrix0(0, 0), matrix1(0, 0), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(0, 1), matrix1(1, 0), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(1, 0), matrix1(0, 1), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(1, 1), matrix1(1, 1), 1e-8f);

        const float determinant = matrix1(0, 0) * matrix1(1, 1) - matrix1(0, 1) * matrix1(1, 0);

        ASSERT_APPROXIMATE(determinant, matrix1.Determinant(), 1e-3f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix2F matrix2 = matrix1.Inverse();

            Matrix2F matrix3 = matrix1 * matrix2;

            ASSERT_APPROXIMATE(matrix3(0, 0), 1.0f, 1e-5f);
            ASSERT_APPROXIMATE(matrix3(0, 1), 0.0f, 1e-5f);
            ASSERT_APPROXIMATE(matrix3(1, 0), 0.0f, 1e-5f);
            ASSERT_APPROXIMATE(matrix3(1, 1), 1.0f, 1e-5f);

            Matrix2F matrix4 = matrix1.Adjoint();
            matrix4 /= determinant;

            matrix3 = matrix4 * matrix1;

            ASSERT_TRUE(Approximate(matrix3, Matrix2F::GetIdentity(), 1e-5f));
        }

        const float angle = angleRandomDistribution(generator);

        Matrix2F matrix5(angle);

        ASSERT_APPROXIMATE(angle, matrix5.ExtractAngle(), 1e-7f);

        Matrix2F matrix6(matrix5);

        matrix6.Orthonormalize();

        Vector2F vector2(matrix5(0, 0), matrix5(1, 0));
        const Vector2F vector3(matrix6(0, 0), matrix6(1, 0));

        vector2.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector2, vector3, 1e-7f));

        Vector2F vector4(matrix5(0, 1), matrix5(1, 1));
        const Vector2F vector5(matrix6(0, 1), matrix6(1, 1));

        vector4 -= (Vector2ToolsF::DotProduct(vector3, vector4)) * vector3;

        vector4.Normalize();

        ASSERT_TRUE(Vector2ToolsF::Approximate(vector4, vector5, 1e-7f));

        const Matrix2D matrix7(randomDistribution(generator), angle, angle, randomDistribution(generator));

        const Matrix2D::Matrix2EigenDecomposition eigenDecomposition = matrix7.EigenDecomposition(1e-10);

        const Matrix2D rotation = eigenDecomposition.GetRotation();
        const Matrix2D diagonal = eigenDecomposition.GetDiagonal();

        const Matrix2D matrix8 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix8, matrix7, 1e-10));
    }
}
