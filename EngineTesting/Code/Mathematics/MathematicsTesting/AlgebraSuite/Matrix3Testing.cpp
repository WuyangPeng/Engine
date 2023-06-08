///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 21:55)

#include "Matrix3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

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
    Matrix3F firstMatrix(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 2), 0.0f, 1e-8f);

    Matrix3F secondMatrix(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), 1.0f, 1e-8f);

    Matrix3D thirdMatrix(3.0, 6.0, 1.0, 6.2, 5.2, 1.01, 3.1, 2.0, 6.06);

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 6.06, 1e-10);

    vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0, 9.5, 3.1, 4.2, 2.0, 6.1 };

    Matrix3D fourthMatrix(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 9.5, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), 3.1, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), 4.2, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), 6.1, 1e-10);

    Matrix3D fifthMatrix(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(fifthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 1), 9.5, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 2), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 1), 3.1, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 2), 6.1, 1e-10);

    Vector3F firstVector(6.0f, 3.0f, 5.0f);
    Vector3F secondVector(8.0f, 3.1f, 9.0f);
    const Vector3F thirdVector(18.0f, 13.1f, 19.0f);

    Matrix3F sixthMatrix(firstVector, secondVector, thirdVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(sixthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(sixthMatrix(2, 2), 19.0f, 1e-8f);

    Matrix3F seventhMatrix(firstVector, secondVector, thirdVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(seventhMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(seventhMatrix(2, 2), 19.0f, 1e-8f);

    vector<Vector3F> Vector3Vector{ firstVector, secondVector, thirdVector };

    Matrix3F eighthMatrix(Vector3Vector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(eighthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(eighthMatrix(2, 2), 19.0f, 1e-8f);

    Matrix3F ninthMatrix(Vector3Vector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(ninthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 2), 19.0f, 1e-8f);

    Matrix3D tenthMatrix(6.0, 89.0, 6.0);

    ASSERT_APPROXIMATE(tenthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(1, 1), 89.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(tenthMatrix(2, 2), 6.0, 1e-10);

    Matrix3D eleventhMatrix(MatrixRotationAxis::X, MathD::GetHalfPI() / 3.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), cos(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), -sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), sin(MathD::GetHalfPI() / 3.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), cos(MathD::GetHalfPI() / 3.0), 1e-10);

    eleventhMatrix.MakeRotation(MatrixRotationAxis::Y, MathD::GetHalfPI() / 4.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), cos(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), sin(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), -sin(MathD::GetHalfPI() / 4.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), cos(MathD::GetHalfPI() / 4.0), 1e-10);

    eleventhMatrix.MakeRotation(MatrixRotationAxis::Z, MathD::GetHalfPI() / 5.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), cos(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), -sin(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), sin(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), cos(MathD::GetHalfPI() / 5.0), 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), 1.0, 1e-10);

    firstVector.Normalize();
    eleventhMatrix.MakeRotation(Vector3D{ firstVector }, MathD::GetHalfPI() / 3.0);

    double cosValue = MathD::Cos(MathD::GetHalfPI() / 3.0);
    double sinValue = MathD::Sin(MathD::GetHalfPI() / 3.0);
    double oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), static_cast<double>(firstVector[0]) * firstVector[0] * oneMinusCos + cosValue, 1e-8);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), static_cast<double>(firstVector[0]) * firstVector[1] * oneMinusCos - firstVector[2] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), static_cast<double>(firstVector[0]) * firstVector[2] * oneMinusCos + firstVector[1] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), static_cast<double>(firstVector[0]) * firstVector[1] * oneMinusCos + firstVector[2] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), static_cast<double>(firstVector[1]) * firstVector[1] * oneMinusCos + cosValue, 1e-9);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), static_cast<double>(firstVector[1]) * firstVector[2] * oneMinusCos - firstVector[0] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), static_cast<double>(firstVector[0]) * firstVector[2] * oneMinusCos - firstVector[1] * sinValue, 1e-8);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), static_cast<double>(firstVector[1]) * firstVector[2] * oneMinusCos + firstVector[0] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), static_cast<double>(firstVector[2]) * firstVector[2] * oneMinusCos + cosValue, 1e-8);

    Matrix3F twelfthMatrix(firstVector, secondVector);

    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(), twelfthMatrix(0, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(), twelfthMatrix(0, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetZ(), twelfthMatrix(0, 2), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(), twelfthMatrix(1, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(), twelfthMatrix(1, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetZ(), twelfthMatrix(1, 2), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetX(), twelfthMatrix(2, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetY(), twelfthMatrix(2, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetZ(), twelfthMatrix(2, 2), 1e-10f);

    eleventhMatrix.MakeZero();

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), 0.0, 1e-10);

    eleventhMatrix.MakeIdentity();

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), 1.0, 1e-10);

    eleventhMatrix.MakeDiagonal(6.0, 9.0, 4.0);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 9.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), 4.0, 1e-10);

    secondVector.Normalize();

    Matrix3D thirteenthMatrix(Vector3D{ secondVector }, MathD::GetHalfPI() / 6.0);

    cosValue = MathD::Cos(MathD::GetHalfPI() / 6.0);
    sinValue = MathD::Sin(MathD::GetHalfPI() / 6.0);
    oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(thirteenthMatrix(0, 0), static_cast<double>(secondVector[0]) * secondVector[0] * oneMinusCos + cosValue, 1e-9);
    ASSERT_APPROXIMATE(thirteenthMatrix(0, 1), static_cast<double>(secondVector[0]) * secondVector[1] * oneMinusCos - secondVector[2] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(0, 2), static_cast<double>(secondVector[0]) * secondVector[2] * oneMinusCos + secondVector[1] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 0), static_cast<double>(secondVector[0]) * secondVector[1] * oneMinusCos + secondVector[2] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 1), static_cast<double>(secondVector[1]) * secondVector[1] * oneMinusCos + cosValue, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(1, 2), static_cast<double>(secondVector[1]) * secondVector[2] * oneMinusCos - secondVector[0] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(2, 0), static_cast<double>(secondVector[0]) * secondVector[2] * oneMinusCos - secondVector[1] * sinValue, 1e-9);
    ASSERT_APPROXIMATE(thirteenthMatrix(2, 1), static_cast<double>(secondVector[1]) * secondVector[2] * oneMinusCos + secondVector[0] * sinValue, 1e-10);
    ASSERT_APPROXIMATE(thirteenthMatrix(2, 2), static_cast<double>(secondVector[2]) * secondVector[2] * oneMinusCos + cosValue, 1e-8f);

    ninthMatrix.MakeTensorProduct(firstVector, secondVector);

    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(), ninthMatrix(0, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(), ninthMatrix(0, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetZ(), ninthMatrix(0, 2), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(), ninthMatrix(1, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(), ninthMatrix(1, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetZ(), ninthMatrix(1, 2), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetX(), ninthMatrix(2, 0), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetY(), ninthMatrix(2, 1), 1e-10f);
    ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetZ(), ninthMatrix(2, 2), 1e-10f);

    eleventhMatrix = tenthMatrix;

    ASSERT_TRUE(Approximate(eleventhMatrix, tenthMatrix, 1e-10));

    const Matrix3D fourteenthMatrix(eleventhMatrix);

    ASSERT_TRUE(Approximate(eleventhMatrix, fourteenthMatrix, 1e-10));
}

void Mathematics::Matrix3Testing::AccessTest()
{
    const Matrix3F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f, 9.0f, 1.0f, 6.4f, 5.8f, 9.6f);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 2), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 0), 6.4f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 1), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 2), 9.6f, 1e-8f);

    Matrix3D secondMatrix(9.2, 1.0, 4.2, 5.2, 6.0, 7.0, 3.5, 8.7, 4.5);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 5.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 7.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), 3.5, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 8.7, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), 4.5, 1e-10);
}

void Mathematics::Matrix3Testing::OperatorCalculateTest()
{
    const Matrix3F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f, -8.0f, 6.2f, 1.0f, -0.1f, 7.0f);

    Matrix3F secondMatrix = -firstMatrix;

    ASSERT_APPROXIMATE(secondMatrix(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), -3.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), -6.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), -7.0f, 1e-8f);

    Matrix3F thirdMatrix(9.2f, 3.0f, 2.0f, 9.0f, 47.0f, 3.1f, 6.9f, 5.5f, 100.0f);

    thirdMatrix += secondMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -3.1f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 5.9f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 5.6f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 93.0f, 1e-8f);

    thirdMatrix -= firstMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 2.6f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 63.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -9.3f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 4.9f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 5.7f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 86.0f, 1e-8f);

    thirdMatrix *= 6.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 15.6f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 378.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -55.8f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 29.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 34.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 516.0f, 1e-6f);

    thirdMatrix /= 2.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 7.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 189.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -27.9f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 14.7f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 17.1f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 258.0f, 1e-8f);

    Matrix3F fourthMatrix2 = firstMatrix + thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix2(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 2), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 0), 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 1), 181.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 2), -21.7f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 0), 15.7f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 1), 17.0f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 2), 265.0f, 1e-8f);

    fourthMatrix2 = firstMatrix - thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix2(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 2), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 0), -4.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 1), -197.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 2), 34.1f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 0), -13.7f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 1), -17.2f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 2), -251.0f, 1e-8f);

    fourthMatrix2 = firstMatrix * 5.0f;

    ASSERT_APPROXIMATE(fourthMatrix2(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 2), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 0), 16.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 1), -40.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 2), 31.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 1), -0.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 2), 35.0f, 1e-8f);

    fourthMatrix2 = 3.0f * firstMatrix;

    ASSERT_APPROXIMATE(fourthMatrix2(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 2), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 0), 9.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 1), -24.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 2), 18.6f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 1), -0.3f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 2), 21.0f, 1e-8f);

    fourthMatrix2 = firstMatrix / (-2.0f);

    ASSERT_APPROXIMATE(fourthMatrix2(0, 0), -1.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 1), -2.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(0, 2), -4.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 0), -1.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(1, 2), -3.1f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 0), -0.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 1), 0.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix2(2, 2), -3.5f, 1e-8f);

    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3F fifthMatrix(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        Matrix3F sixthMatrix(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        Matrix3F seventhMatrix(sixthMatrix);

        seventhMatrix *= fifthMatrix;

        const Matrix3F fourthMatrix(sixthMatrix(0, 0) * fifthMatrix(0, 0) +
                                        sixthMatrix(0, 1) * fifthMatrix(1, 0) +
                                        sixthMatrix(0, 2) * fifthMatrix(2, 0),
                                    sixthMatrix(0, 0) * fifthMatrix(0, 1) +
                                        sixthMatrix(0, 1) * fifthMatrix(1, 1) +
                                        sixthMatrix(0, 2) * fifthMatrix(2, 1),
                                    sixthMatrix(0, 0) * fifthMatrix(0, 2) +
                                        sixthMatrix(0, 1) * fifthMatrix(1, 2) +
                                        sixthMatrix(0, 2) * fifthMatrix(2, 2),
                                    sixthMatrix(1, 0) * fifthMatrix(0, 0) +
                                        sixthMatrix(1, 1) * fifthMatrix(1, 0) +
                                        sixthMatrix(1, 2) * fifthMatrix(2, 0),
                                    sixthMatrix(1, 0) * fifthMatrix(0, 1) +
                                        sixthMatrix(1, 1) * fifthMatrix(1, 1) +
                                        sixthMatrix(1, 2) * fifthMatrix(2, 1),
                                    sixthMatrix(1, 0) * fifthMatrix(0, 2) +
                                        sixthMatrix(1, 1) * fifthMatrix(1, 2) +
                                        sixthMatrix(1, 2) * fifthMatrix(2, 2),
                                    sixthMatrix(2, 0) * fifthMatrix(0, 0) +
                                        sixthMatrix(2, 1) * fifthMatrix(1, 0) +
                                        sixthMatrix(2, 2) * fifthMatrix(2, 0),
                                    sixthMatrix(2, 0) * fifthMatrix(0, 1) +
                                        sixthMatrix(2, 1) * fifthMatrix(1, 1) +
                                        sixthMatrix(2, 2) * fifthMatrix(2, 1),
                                    sixthMatrix(2, 0) * fifthMatrix(0, 2) +
                                        sixthMatrix(2, 1) * fifthMatrix(1, 2) +
                                        sixthMatrix(2, 2) * fifthMatrix(2, 2));

        ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix, 1e-8f));

        seventhMatrix = sixthMatrix * fifthMatrix;

        ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix, 1e-8f));

        Matrix3F::Vector3 firstVector(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        const Matrix3F::Vector3 secondVector = seventhMatrix * firstVector;
        const Matrix3F::Vector3 thirdVector = firstVector * seventhMatrix;

        Matrix3F::Vector3 fourthVector(seventhMatrix(0, 0) * firstVector[0] +
                                           seventhMatrix(0, 1) * firstVector[1] +
                                           seventhMatrix(0, 2) * firstVector[2],
                                       seventhMatrix(1, 0) * firstVector[0] +
                                           seventhMatrix(1, 1) * firstVector[1] +
                                           seventhMatrix(1, 2) * firstVector[2],
                                       seventhMatrix(2, 0) * firstVector[0] +
                                           seventhMatrix(2, 1) * firstVector[1] +
                                           seventhMatrix(2, 2) * firstVector[2]);

        ASSERT_TRUE(Vector3ToolsF::Approximate(secondVector, fourthVector, 1e-3f));

        fourthVector[0] = seventhMatrix(0, 0) * firstVector[0] +
                          seventhMatrix(1, 0) * firstVector[1] +
                          seventhMatrix(2, 0) * firstVector[2];

        fourthVector[1] = seventhMatrix(0, 1) * firstVector[0] +
                          seventhMatrix(1, 1) * firstVector[1] +
                          seventhMatrix(2, 1) * firstVector[2];

        fourthVector[2] = seventhMatrix(0, 2) * firstVector[0] +
                          seventhMatrix(1, 2) * firstVector[1] +
                          seventhMatrix(2, 2) * firstVector[2];

        ASSERT_TRUE(Vector3ToolsF::Approximate(thirdVector, fourthVector, 1e-3f));

        Matrix3F eighthMatrix = TransposeTimes(fifthMatrix, sixthMatrix);
        Matrix3F ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TransposeTimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));
    }
}

void Mathematics::Matrix3Testing::ArithmeticCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };
    const uniform_real<float> angleRandomDistribution{ 0.0f, MathF::GetPI() - 0.01f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3F::Vector3 firstVector(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        const Matrix3F::Vector3 secondVector(randomDistribution(generator),
                                             randomDistribution(generator),
                                             randomDistribution(generator));

        Matrix3F firstMatrix(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const float qForm = firstMatrix.QuadraticForm(firstVector, secondVector);

        const float testQFormValue = Vector3ToolsF::DotProduct(firstVector, firstMatrix * secondVector);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix3F secondMatrix = firstMatrix.Transpose();

        ASSERT_APPROXIMATE(firstMatrix(0, 0), secondMatrix(0, 0), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(0, 1), secondMatrix(1, 0), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(0, 2), secondMatrix(2, 0), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(1, 0), secondMatrix(0, 1), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(1, 1), secondMatrix(1, 1), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(1, 2), secondMatrix(2, 1), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(2, 0), secondMatrix(0, 2), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(2, 1), secondMatrix(1, 2), 1e-8f);
        ASSERT_APPROXIMATE(firstMatrix(2, 2), secondMatrix(2, 2), 1e-8f);

        secondMatrix = firstMatrix.TimesDiagonal(firstVector);

        Matrix3F thirdMatrix = firstMatrix * Matrix3F(firstVector[0], firstVector[1], firstVector[2]);

        ASSERT_TRUE(Approximate(thirdMatrix, secondMatrix, 1e-8f));

        secondMatrix = firstMatrix.DiagonalTimes(firstVector);

        thirdMatrix = Matrix3F(firstVector[0], firstVector[1], firstVector[2]) * firstMatrix;

        ASSERT_TRUE(Approximate(thirdMatrix, secondMatrix, 1e-8f));

        const float column00 = secondMatrix(0, 2) * secondMatrix(2, 1) - secondMatrix(0, 1) * secondMatrix(2, 2);
        const float column10 = secondMatrix(0, 0) * secondMatrix(2, 2) - secondMatrix(0, 2) * secondMatrix(2, 0);
        const float column20 = secondMatrix(0, 1) * secondMatrix(2, 0) - secondMatrix(0, 0) * secondMatrix(2, 1);

        const float determinant = column00 * secondMatrix(1, 0) + column10 * secondMatrix(1, 1) + column20 * secondMatrix(1, 2);

        ASSERT_APPROXIMATE(determinant, secondMatrix.Determinant(), 1e-1f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix3F fourthMatrix = secondMatrix.Inverse();

            Matrix3F fifthMatrix = secondMatrix * fourthMatrix;

            ASSERT_TRUE(Approximate(fifthMatrix, Matrix3F::GetIdentity(), 1e-3f));

            Matrix3F sixthMatrix = secondMatrix.Adjoint();
            sixthMatrix /= determinant;

            fifthMatrix = sixthMatrix * secondMatrix;

            ASSERT_TRUE(Approximate(fifthMatrix, Matrix3F::GetIdentity(), 1e-4f));
        }

        float angle = angleRandomDistribution(generator);
        firstVector.Normalize();

        Matrix3F seventhMatrix(firstVector, angle);

        ASSERT_APPROXIMATE(angle, seventhMatrix.ExtractAngle(),
                           1e-5f);
        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhMatrix.ExtractAxis(), firstVector));

        const Matrix3ExtractF extract = seventhMatrix.ExtractAngleAxis();

        ASSERT_APPROXIMATE(angle, extract.GetAngle(), 1e-5f);
        ASSERT_TRUE(Vector3ToolsF::Approximate(extract.GetAxis(), firstVector));

        Matrix3F eighthMatrix(seventhMatrix);

        seventhMatrix.Orthonormalize();

        Vector3F thirdVector(eighthMatrix(0, 0), eighthMatrix(1, 0), eighthMatrix(2, 0));
        const Vector3F fourthVector(seventhMatrix(0, 0), seventhMatrix(1, 0), seventhMatrix(2, 0));

        thirdVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(thirdVector, fourthVector, 1e-7f));

        Vector3F fifthVector(eighthMatrix(0, 1), eighthMatrix(1, 1), eighthMatrix(2, 1));

        const Vector3F sixthVector(seventhMatrix(0, 1), seventhMatrix(1, 1), seventhMatrix(2, 1));

        fifthVector -= (Vector3ToolsF::DotProduct(fourthVector, fifthVector)) * fourthVector;

        fifthVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(fifthVector, sixthVector, 1e-7f));

        Vector3F seventhVector(eighthMatrix(0, 2), eighthMatrix(1, 2), eighthMatrix(2, 2));
        const Vector3F eighthVector(seventhMatrix(0, 2), seventhMatrix(1, 2), seventhMatrix(2, 2));

        seventhVector -= (Vector3ToolsF::DotProduct(fourthVector, seventhVector)) * fourthVector;

        seventhVector -= (Vector3ToolsF::DotProduct(sixthVector, seventhVector)) * sixthVector;

        seventhVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, eighthVector, 1e-7f));

        const float secondAngle = angleRandomDistribution(generator);
        const float thirdAngle = angleRandomDistribution(generator);

        const Matrix3F ninthMatrix(randomDistribution(generator), angle, secondAngle, angle, randomDistribution(generator), thirdAngle, secondAngle, thirdAngle, randomDistribution(generator));

        Matrix3F::Matrix3EigenDecomposition eigenDecomposition = ninthMatrix.EigenDecomposition(1e-8f);

        Matrix3F rotation = eigenDecomposition.GetRotation();
        Matrix3F diagonal = eigenDecomposition.GetDiagonal();

        const Matrix3F tenthMatrix = rotation * diagonal * rotation.Transpose();

        ASSERT_TRUE(Approximate(ninthMatrix, tenthMatrix, 1e-5f));

        seventhMatrix.MakeRotation(firstVector, MathF::GetPI());

        ASSERT_APPROXIMATE(MathF::GetPI(), seventhMatrix.ExtractAngle(), 1e-3f);

        // 由于旋转的角度是PI，所以旋转的方向可能是相反的。
        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhMatrix.ExtractAxis(), firstVector) || Vector3ToolsF::Approximate(-seventhMatrix.ExtractAxis(), firstVector));

        const Matrix3F eleventhMatrix(firstVector, angle);
        const Matrix3F twelfthMatrix(secondVector, angle / 2.0f);

        seventhMatrix.Slerp(0.5, eleventhMatrix, tenthMatrix);

        Matrix3F thirteenthMatrix = TransposeTimes(eleventhMatrix, tenthMatrix);

        const Vector3F ninthVector = thirteenthMatrix.ExtractAxis();
        angle = thirteenthMatrix.ExtractAngle();

        thirteenthMatrix.MakeRotation(ninthVector, angle * 0.5f);

        thirteenthMatrix = eleventhMatrix * thirteenthMatrix;

        ASSERT_TRUE(Approximate(seventhMatrix, thirteenthMatrix, 1e-8f));

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
    default_random_engine generator{};
    const uniform_real<double> firstAngleRandomDistribution{ -MathD::GetPI(), MathD::GetPI() };
    const uniform_real<double> secondAngleRandomDistribution{ -MathD::GetHalfPI(), MathD::GetHalfPI() };
    const uniform_real<double> thirdAngleRandomDistribution{ 0.0, MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const double firstAngle = firstAngleRandomDistribution(generator);
        const double secondAngle = secondAngleRandomDistribution(generator);
        const double thirdAngle = firstAngleRandomDistribution(generator);
        const double fourthAngle = thirdAngleRandomDistribution(generator);

        Matrix3D firstMatrix;

        firstMatrix.MakeEulerXYZ(firstAngle, secondAngle, thirdAngle);

        Matrix3D::Euler firstEuler = firstMatrix.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerXZY(firstAngle, secondAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerYXZ(firstAngle, secondAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerYZX(firstAngle, secondAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerZXY(firstAngle, secondAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerZYX(firstAngle, secondAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(secondAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerXYX(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerXZX(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerYXY(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerYZY(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerZXZ(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        firstMatrix.MakeEulerZYZ(firstAngle, fourthAngle, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(fourthAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(thirdAngle, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

        // 测试特殊情况
        firstMatrix.MakeEulerXYZ(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerXYZ(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerXZY(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerXZY(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerYXZ(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerYXZ(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerYZX(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerYZX(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerZXY(firstAngle + thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerZXY(firstAngle - thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerZYX(firstAngle + thirdAngle, MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetHalfPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerZYX(firstAngle - thirdAngle, -MathD::GetHalfPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(-MathD::GetHalfPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerXYX(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerXYX(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXYX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerXZX(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerXZX(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerXZX();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerYXY(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerYXY(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYXY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerYZY(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerYZY(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerYZY();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerZXZ(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerZXZ(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetX0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

        firstMatrix.MakeEulerZYZ(firstAngle + thirdAngle, MathD::GetPI(), thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(MathD::GetPI(), firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Difference);

        firstMatrix.MakeEulerZYZ(firstAngle - thirdAngle, 0.0f, thirdAngle);

        firstEuler = firstMatrix.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(firstAngle, firstEuler.GetZ0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetY0Angle(), 1e-10);
        ASSERT_APPROXIMATE(0.0f, firstEuler.GetZ1Angle(), 1e-10);

        ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);
    }
}
