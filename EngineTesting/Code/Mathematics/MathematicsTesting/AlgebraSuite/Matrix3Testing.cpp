///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:30)

#include "Matrix3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Flags/EulerResultType.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"

#include <random>

namespace Mathematics
{
    template class Matrix3<float>;
    template class Matrix3<double>;
}

Mathematics::Matrix3Testing::Matrix3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix3Testing)

void Mathematics::Matrix3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerTest);
}

void Mathematics::Matrix3Testing::ConstructionTest()
{
    Matrix3F matrix0(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(matrix0(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 0.0f, 1e-8f);

    Matrix3F matrix1(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(matrix1(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), 1.0f, 1e-8f);

    Matrix3D matrix2(3.0, 6.0, 1.0, 6.2, 5.2, 1.01, 3.1, 2.0, 6.06);

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 2), 6.06, 1e-10);

    std::vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0, 9.5, 3.1, 4.2, 2.0, 6.1 };

    Matrix3D matrix3(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix3(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 2), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 1), 9.5, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 2), 3.1, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 0), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 2), 6.1, 1e-10);

    Matrix3D matrix4(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix4(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 9.5, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 3.1, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 6.1, 1e-10);

    Vector3F vector0(6.0f, 3.0f, 5.0f);
    Vector3F vector1(8.0f, 3.1f, 9.0f);
    const Vector3F vector2(18.0f, 13.1f, 19.0f);

    Matrix3F matrix5(vector0, vector1, vector2, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix5(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix5(2, 2), 19.0f, 1e-8f);

    Matrix3F matrix6(vector0, vector1, vector2, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix6(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix6(2, 2), 19.0f, 1e-8f);

    std::vector<Vector3F> vector3Vector{ vector0, vector1, vector2 };

    Matrix3F matrix7(vector3Vector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix7(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix7(2, 2), 19.0f, 1e-8f);

    Matrix3F matrix8(vector3Vector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix8(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 2), 19.0f, 1e-8f);

    Matrix3D matrix9(6.0, 89.0, 6.0);

    ASSERT_APPROXIMATE(matrix9(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(1, 1), 89.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix9(2, 2), 6.0, 1e-10);

    Matrix3D matrix10(MatrixRotationAxis::X, MathD::GetHalfPI() / 3.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), cos(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), -sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), cos(MathD::GetHalfPI() / 3.0), 1e-10);

    matrix10.MakeRotation(MatrixRotationAxis::Y, MathD::GetHalfPI() / 4.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), cos(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), sin(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), -sin(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), cos(MathD::GetHalfPI() / 4.0), 1e-10);

    matrix10.MakeRotation(MatrixRotationAxis::Z, MathD::GetHalfPI() / 5.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), cos(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), -sin(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), sin(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), cos(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), 1.0, 1e-10);

    vector0.Normalize();
    matrix10.MakeRotation(Vector3D{ vector0 }, MathD::GetHalfPI() / 3.0);

    double cosValue = MathD::Cos(MathD::GetHalfPI() / 3.0);
    double sinValue = MathD::Sin(MathD::GetHalfPI() / 3.0);
    double oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(matrix10(0, 0), static_cast<double>(vector0[0]) * vector0[0] * oneMinusCos + cosValue, 1e-8);
    ASSERT_APPROXIMATE(matrix10(0, 1), static_cast<double>(vector0[0]) * vector0[1] * oneMinusCos - vector0[2] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(matrix10(0, 2), static_cast<double>(vector0[0]) * vector0[2] * oneMinusCos + vector0[1] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(matrix10(1, 0), static_cast<double>(vector0[0]) * vector0[1] * oneMinusCos + vector0[2] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(matrix10(1, 1), static_cast<double>(vector0[1]) * vector0[1] * oneMinusCos + cosValue, 1e-9);
    ASSERT_APPROXIMATE(matrix10(1, 2), static_cast<double>(vector0[1]) * vector0[2] * oneMinusCos - vector0[0] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(matrix10(2, 0), static_cast<double>(vector0[0]) * vector0[2] * oneMinusCos - vector0[1] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(matrix10(2, 1), static_cast<double>(vector0[1]) * vector0[2] * oneMinusCos + vector0[0] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(matrix10(2, 2), static_cast<double>(vector0[2]) * vector0[2] * oneMinusCos + cosValue, 1e-8);

    Matrix3F matrix11(vector0, vector1);

    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetX(), matrix11(0, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetY(), matrix11(0, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetZ(), matrix11(0, 2), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetX(), matrix11(1, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetY(), matrix11(1, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetZ(), matrix11(1, 2), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetX(), matrix11(2, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetY(), matrix11(2, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetZ(), matrix11(2, 2), 1e-10f);

    matrix10.MakeZero();

    ASSERT_APPROXIMATE(matrix10(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), 0.0, 1e-10);

    matrix10.MakeIdentity();

    ASSERT_APPROXIMATE(matrix10(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), 1.0, 1e-10);

    matrix10.MakeDiagonal(6.0, 9.0, 4.0);

    ASSERT_APPROXIMATE(matrix10(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 1), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix10(2, 2), 4.0, 1e-10);

    vector1.Normalize();

    Matrix3D matrix12(Vector3D{ vector1 }, MathD::GetHalfPI() / 6.0);

    cosValue = MathD::Cos(MathD::GetHalfPI() / 6.0);
    sinValue = MathD::Sin(MathD::GetHalfPI() / 6.0);
    oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(matrix12(0, 0), static_cast<double>(vector1[0]) * vector1[0] * oneMinusCos + cosValue, 1e-9);
    ASSERT_APPROXIMATE(matrix12(0, 1), static_cast<double>(vector1[0]) * vector1[1] * oneMinusCos - vector1[2] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(matrix12(0, 2), static_cast<double>(vector1[0]) * vector1[2] * oneMinusCos + vector1[1] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(matrix12(1, 0), static_cast<double>(vector1[0]) * vector1[1] * oneMinusCos + vector1[2] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(matrix12(1, 1), static_cast<double>(vector1[1]) * vector1[1] * oneMinusCos + cosValue, 1e-10);
    ASSERT_APPROXIMATE(matrix12(1, 2), static_cast<double>(vector1[1]) * vector1[2] * oneMinusCos - vector1[0] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(matrix12(2, 0), static_cast<double>(vector1[0]) * vector1[2] * oneMinusCos - vector1[1] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(matrix12(2, 1), static_cast<double>(vector1[1]) * vector1[2] * oneMinusCos + vector1[0] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(matrix12(2, 2), static_cast<double>(vector1[2]) * vector1[2] * oneMinusCos + cosValue, 1e-8f);

    matrix8.MakeTensorProduct(vector0, vector1);

    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetX(), matrix8(0, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetY(), matrix8(0, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetX() * vector1.GetZ(), matrix8(0, 2), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetX(), matrix8(1, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetY(), matrix8(1, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetY() * vector1.GetZ(), matrix8(1, 2), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetX(), matrix8(2, 0), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetY(), matrix8(2, 1), 1e-10f);
    ASSERT_APPROXIMATE(vector0.GetZ() * vector1.GetZ(), matrix8(2, 2), 1e-10f);

    matrix10 = matrix9;

    ASSERT_TRUE(Approximate(matrix10, matrix9, 1e-10));

    const Matrix3D matrix13(matrix10);

    ASSERT_TRUE(Approximate(matrix10, matrix13, 1e-10));
}

void Mathematics::Matrix3Testing::AccessTest()
{
    const Matrix3F matrix0(3.0f, 4.0f, 8.1f, 3.2f, 9.0f, 1.0f, 6.4f, 5.8f, 9.6f);

    ASSERT_APPROXIMATE(matrix0(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 6.4f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 9.6f, 1e-8f);

    Matrix3D matrix1(9.2, 1.0, 4.2, 5.2, 6.0, 7.0, 3.5, 8.7, 4.5);

    ASSERT_APPROXIMATE(matrix1(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 7.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), 3.5, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), 8.7, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), 4.5, 1e-10);
}

void Mathematics::Matrix3Testing::OperatorCalculateTest()
{
    const Matrix3F matrix0(3.0f, 4.0f, 8.1f, 3.2f, -8.0f, 6.2f, 1.0f, -0.1f, 7.0f);

    Matrix3F matrix1 = -matrix0;

    ASSERT_APPROXIMATE(matrix1(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), -3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), -6.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), -7.0f, 1e-8f);

    Matrix3F matrix2(9.2f, 3.0f, 2.0f, 9.0f, 47.0f, 3.1f, 6.9f, 5.5f, 100.0f);

    matrix2 += matrix1;

    ASSERT_APPROXIMATE(matrix2(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 5.9f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 1), 5.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), 93.0f, 1e-8f);

    matrix2 -= matrix0;

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 2.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 63.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -9.3f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 4.9f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 1), 5.7f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), 86.0f, 1e-8f);

    matrix2 *= 6.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 15.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 378.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -55.8f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 29.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 1), 34.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 2), 516.0f, 1e-6f);

    matrix2 /= 2.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 7.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 1), 189.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -27.9f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 14.7f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 1), 17.1f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 2), 258.0f, 1e-8f);

    Matrix3F matrix32 = matrix0 + matrix2;

    ASSERT_APPROXIMATE(matrix32(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix32(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 2), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 0), 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 1), 181.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 2), -21.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(2, 0), 15.7f, 1e-6f);
    ASSERT_APPROXIMATE(matrix32(2, 1), 17.0f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(2, 2), 265.0f, 1e-8f);

    matrix32 = matrix0 - matrix2;

    ASSERT_APPROXIMATE(matrix32(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix32(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 2), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(1, 0), -4.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix32(1, 1), -197.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 2), 34.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 0), -13.7f, 1e-6f);
    ASSERT_APPROXIMATE(matrix32(2, 1), -17.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(2, 2), -251.0f, 1e-8f);

    matrix32 = matrix0 * 5.0f;

    ASSERT_APPROXIMATE(matrix32(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 2), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 0), 16.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 1), -40.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 2), 31.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 1), -0.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 2), 35.0f, 1e-8f);

    matrix32 = 3.0f * matrix0;

    ASSERT_APPROXIMATE(matrix32(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 2), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(1, 0), 9.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 1), -24.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 2), 18.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix32(2, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 1), -0.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 2), 21.0f, 1e-8f);

    matrix32 = matrix0 / (-2.0f);

    ASSERT_APPROXIMATE(matrix32(0, 0), -1.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 1), -2.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(0, 2), -4.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 0), -1.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(1, 2), -3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 0), -0.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 1), 0.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix32(2, 2), -3.5f, 1e-8f);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3F matrix4(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Matrix3F matrix5(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Matrix3F matrix6(matrix5);

        matrix6 *= matrix4;

        const Matrix3F matrix3(matrix5(0, 0) * matrix4(0, 0) +
                                   matrix5(0, 1) * matrix4(1, 0) +
                                   matrix5(0, 2) * matrix4(2, 0),
                               matrix5(0, 0) * matrix4(0, 1) +
                                   matrix5(0, 1) * matrix4(1, 1) +
                                   matrix5(0, 2) * matrix4(2, 1),
                               matrix5(0, 0) * matrix4(0, 2) +
                                   matrix5(0, 1) * matrix4(1, 2) +
                                   matrix5(0, 2) * matrix4(2, 2),
                               matrix5(1, 0) * matrix4(0, 0) +
                                   matrix5(1, 1) * matrix4(1, 0) +
                                   matrix5(1, 2) * matrix4(2, 0),
                               matrix5(1, 0) * matrix4(0, 1) +
                                   matrix5(1, 1) * matrix4(1, 1) +
                                   matrix5(1, 2) * matrix4(2, 1),
                               matrix5(1, 0) * matrix4(0, 2) +
                                   matrix5(1, 1) * matrix4(1, 2) +
                                   matrix5(1, 2) * matrix4(2, 2),
                               matrix5(2, 0) * matrix4(0, 0) +
                                   matrix5(2, 1) * matrix4(1, 0) +
                                   matrix5(2, 2) * matrix4(2, 0),
                               matrix5(2, 0) * matrix4(0, 1) +
                                   matrix5(2, 1) * matrix4(1, 1) +
                                   matrix5(2, 2) * matrix4(2, 1),
                               matrix5(2, 0) * matrix4(0, 2) +
                                   matrix5(2, 1) * matrix4(1, 2) +
                                   matrix5(2, 2) * matrix4(2, 2));

        ASSERT_TRUE(Approximate(matrix3, matrix6, 1e-8f));

        matrix6 = matrix5 * matrix4;

        ASSERT_TRUE(Approximate(matrix3, matrix6, 1e-8f));

        Matrix3F::Vector3 vector0(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const Matrix3F::Vector3 vector1 = matrix6 * vector0;
        const Matrix3F::Vector3 vector2 = vector0 * matrix6;

        Matrix3F::Vector3 vector3(matrix6(0, 0) * vector0[0] +
                                      matrix6(0, 1) * vector0[1] +
                                      matrix6(0, 2) * vector0[2],
                                  matrix6(1, 0) * vector0[0] +
                                      matrix6(1, 1) * vector0[1] +
                                      matrix6(1, 2) * vector0[2],
                                  matrix6(2, 0) * vector0[0] +
                                      matrix6(2, 1) * vector0[1] +
                                      matrix6(2, 2) * vector0[2]);

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector1, vector3, 1e-3f));

        vector3[0] = matrix6(0, 0) * vector0[0] +
                     matrix6(1, 0) * vector0[1] +
                     matrix6(2, 0) * vector0[2];

        vector3[1] = matrix6(0, 1) * vector0[0] +
                     matrix6(1, 1) * vector0[1] +
                     matrix6(2, 1) * vector0[2];

        vector3[2] = matrix6(0, 2) * vector0[0] +
                     matrix6(1, 2) * vector0[1] +
                     matrix6(2, 2) * vector0[2];

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector2, vector3, 1e-3f));

        Matrix3F matrix7 = TransposeTimes(matrix4, matrix5);
        Matrix3F matrix8 = matrix4.Transpose() * matrix5;

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TimesTranspose(matrix4, matrix5);
        matrix8 = matrix4 * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TransposeTimesTranspose(matrix4, matrix5);
        matrix8 = matrix4.Transpose() * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));
    }
}

void Mathematics::Matrix3Testing::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };
    std::uniform_real_distribution<float> angleRandomDistribution{ 0.0f, MathF::GetPI() - 0.01f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3F::Vector3 vector0(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        const Matrix3F::Vector3 vector1(randomDistribution(generator),
                                        randomDistribution(generator),
                                        randomDistribution(generator));

        Matrix3F matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const float qForm = matrix0.QuadraticForm(vector0, vector1);

        const float testQFormValue = Vector3ToolsF::DotProduct(vector0, matrix0 * vector1);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix3F matrix1 = matrix0.Transpose();

        ASSERT_APPROXIMATE(matrix0(0, 0), matrix1(0, 0), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(0, 1), matrix1(1, 0), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(0, 2), matrix1(2, 0), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(1, 0), matrix1(0, 1), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(1, 1), matrix1(1, 1), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(1, 2), matrix1(2, 1), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(2, 0), matrix1(0, 2), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(2, 1), matrix1(1, 2), 1e-8f);
        ASSERT_APPROXIMATE(matrix0(2, 2), matrix1(2, 2), 1e-8f);

        matrix1 = matrix0.TimesDiagonal(vector0);

        Matrix3F matrix2 = matrix0 * Matrix3F(vector0[0], vector0[1], vector0[2]);

        ASSERT_TRUE(Approximate(matrix2, matrix1, 1e-8f));

        matrix1 = matrix0.DiagonalTimes(vector0);

        matrix2 = Matrix3F(vector0[0], vector0[1], vector0[2]) * matrix0;

        ASSERT_TRUE(Approximate(matrix2, matrix1, 1e-8f));

        const float column00 = matrix1(0, 2) * matrix1(2, 1) - matrix1(0, 1) * matrix1(2, 2);
        const float column10 = matrix1(0, 0) * matrix1(2, 2) - matrix1(0, 2) * matrix1(2, 0);
        const float column20 = matrix1(0, 1) * matrix1(2, 0) - matrix1(0, 0) * matrix1(2, 1);

        const float determinant = column00 * matrix1(1, 0) + column10 * matrix1(1, 1) + column20 * matrix1(1, 2);

        ASSERT_APPROXIMATE(determinant, matrix1.Determinant(), 1e-1f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix3F matrix3 = matrix1.Inverse();

            Matrix3F matrix4 = matrix1 * matrix3;

            ASSERT_TRUE(Approximate(matrix4, Matrix3F::GetIdentity(), 1e-3f));

            Matrix3F matrix5 = matrix1.Adjoint();
            matrix5 /= determinant;

            matrix4 = matrix5 * matrix1;

            ASSERT_TRUE(Approximate(matrix4, Matrix3F::GetIdentity(), 1e-4f));
        }

        float angle = angleRandomDistribution(generator);
        vector0.Normalize();

        Matrix3F matrix6(vector0, angle);

        ASSERT_APPROXIMATE(angle, matrix6.ExtractAngle(), 1e-4f);
        ASSERT_TRUE(Vector3ToolsF::Approximate(matrix6.ExtractAxis(), vector0, 1e-5f));

        const auto extract = matrix6.ExtractAngleAxis();

        ASSERT_APPROXIMATE(angle, extract.GetAngle(), 1e-4f);
        ASSERT_TRUE(Vector3ToolsF::Approximate(extract.GetAxis(), vector0, 1e-5f));

        Matrix3F matrix7(matrix6);

        matrix6.Orthonormalize();

        Vector3F vector2(matrix7(0, 0), matrix7(1, 0), matrix7(2, 0));
        const Vector3F vector3(matrix6(0, 0), matrix6(1, 0), matrix6(2, 0));

        vector2.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector2, vector3, 1e-7f));

        Vector3F vector4(matrix7(0, 1), matrix7(1, 1), matrix7(2, 1));

        const Vector3F vector5(matrix6(0, 1), matrix6(1, 1), matrix6(2, 1));

        vector4 -= (Vector3ToolsF::DotProduct(vector3, vector4)) * vector3;

        vector4.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector4, vector5, 1e-7f));

        Vector3F seventhVector(matrix7(0, 2), matrix7(1, 2), matrix7(2, 2));
        const Vector3F eighthVector(matrix6(0, 2), matrix6(1, 2), matrix6(2, 2));

        seventhVector -= (Vector3ToolsF::DotProduct(vector3, seventhVector)) * vector3;

        seventhVector -= (Vector3ToolsF::DotProduct(vector5, seventhVector)) * vector5;

        seventhVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, eighthVector, 1e-6f));

        const float secondAngle = angleRandomDistribution(generator);
        const float thirdAngle = angleRandomDistribution(generator);

        const Matrix3F matrix8(randomDistribution(generator), angle, secondAngle, angle, randomDistribution(generator), thirdAngle, secondAngle, thirdAngle, randomDistribution(generator));

        Matrix3F::Matrix3EigenDecomposition eigenDecomposition = matrix8.EigenDecomposition(1e-8f);

        Matrix3F rotation = eigenDecomposition.GetRotation();
        Matrix3F diagonal = eigenDecomposition.GetDiagonal();

        const Matrix3F matrix9 = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(matrix8, matrix9, 1e-5f));

        matrix6.MakeRotation(vector0, MathF::GetPI());

        ASSERT_APPROXIMATE(MathF::GetPI(), matrix6.ExtractAngle(), 1e-3f);

        // 由于旋转的角度是PI，所以旋转的方向可能是相反的。
        ASSERT_TRUE(Vector3ToolsF::Approximate(matrix6.ExtractAxis(), vector0) || Vector3ToolsF::Approximate(-matrix6.ExtractAxis(), vector0));

        const Matrix3F matrix10(vector0, angle);
        const Matrix3F matrix11(vector1, angle / 2.0f);

        matrix6.Slerp(0.5, matrix10, matrix9);

        Matrix3F thirteenthMatrix = TransposeTimes(matrix10, matrix9);

        const Vector3F ninthVector = thirteenthMatrix.ExtractAxis();
        angle = thirteenthMatrix.ExtractAngle();

        thirteenthMatrix.MakeRotation(ninthVector, angle * 0.5f);

        thirteenthMatrix = matrix10 * thirteenthMatrix;

        ASSERT_TRUE(Approximate(matrix6, thirteenthMatrix, 1e-8f));

        // 测试m_Matrix(0,2)为零的情况
        const Matrix3F fourteenthMatrix(randomDistribution(generator), angle, 0.0f, angle, randomDistribution(generator), thirdAngle, 0.0f, thirdAngle, randomDistribution(generator));

        eigenDecomposition = fourteenthMatrix.EigenDecomposition();

        rotation = eigenDecomposition.GetRotation();
        diagonal = eigenDecomposition.GetDiagonal();

        const Matrix3F fifteenthMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(fifteenthMatrix, fourteenthMatrix, 1e-5f));
    }
}

void Mathematics::Matrix3Testing::EulerTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> firstAngleRandomDistribution{ -MathD::GetPI(), MathD::GetPI() };
    std::uniform_real_distribution<double> secondAngleRandomDistribution{ -MathD::GetHalfPI(), MathD::GetHalfPI() };
    std::uniform_real_distribution<double> thirdAngleRandomDistribution{ 0.0, MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const double firstAngle = firstAngleRandomDistribution(generator);
        const double secondAngle = secondAngleRandomDistribution(generator);
        const double thirdAngle = firstAngleRandomDistribution(generator);
        const double fourthAngle = thirdAngleRandomDistribution(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerXYZ(firstAngle, secondAngle, thirdAngle);

        Matrix3D::Euler euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerXZY(firstAngle, secondAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerYXZ(firstAngle, secondAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerYZX(firstAngle, secondAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerZXY(firstAngle, secondAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerZYX(firstAngle, secondAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerXYX(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerXZX(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerYXY(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerYZY(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerZXZ(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        matrix0.MakeEulerZYZ(firstAngle, fourthAngle, thirdAngle);

        euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::Unique);

        // 测试特殊情况
        matrix0.MakeEulerXYZ(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerXYZ(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerXZY(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerXZY(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerYXZ(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerYXZ(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerYZX(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerYZX(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerZXY(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerZXY(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerZYX(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerZYX(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerXYX(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerXYX(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerXZX(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerXZX(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerYXY(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerYXY(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerYZY(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerYZY(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerZXZ(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerZXZ(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);

        matrix0.MakeEulerZYZ(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueDifference);

        matrix0.MakeEulerZYZ(firstAngle - thirdAngle, 0.0f, thirdAngle);

        euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, euler0.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, euler0.GetZ1Angle(), 1e-10);

        ASSERT_EQUAL(euler0.GetType(), EulerResult::NotUniqueSum);
    }
}
