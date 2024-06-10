///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:34)

#include "MatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4.h"

#include <random>

Mathematics::MatrixTesting::MatrixTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MatrixTesting)

void Mathematics::MatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HomogeneousPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Invert3x3Test);
}

void Mathematics::MatrixTesting::ConstructionTest()
{
    MatrixF matrix0(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(matrix0(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 3), 0.0f, 1e-8f);

    MatrixF matrix1(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(matrix1(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 3), 1.0f, 1e-8f);

    MatrixD matrix2(3.0, 6.0, 1.0, 2.0,
                    13.0, 16.0, 11.0, 12.0,
                    23.0, 26.0, 21.0, 22.0,
                    33.0, 63.0, 13.0, 23.0);

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 0), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 1), 16.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 2), 11.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 3), 12.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 0), 23.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 1), 26.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 2), 21.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 3), 22.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 0), 33.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 1), 63.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 2), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 3), 23.0, 1e-10);

    std::vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0, 32.0, 5.0, 6.1, 5.5, 3.0, 0.5, 9.99, 6.22, 3.33, 2.22, 3.22, 2.5 };

    MatrixD matrix3(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix3(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 2), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 0), 32.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 2), 6.1, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 3), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 1), 0.5, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 3), 6.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 1), 2.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 2), 3.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 3), 2.5, 1e-10);

    MatrixD matrix4(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix4(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 32.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.5, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 2.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 6.1, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 3.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 6.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 2.5, 1e-10);

    matrix4.MakeZero();

    ASSERT_APPROXIMATE(matrix4(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 0.0, 1e-10);

    matrix4.MakeIdentity();

    ASSERT_APPROXIMATE(matrix4(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 1.0, 1e-10);

    const Matrix3D matrix5(3.0, 6.0, 1.0,
                           6.2, 5.2, 1.01,
                           3.1, 2.0, 6.06);

    MatrixD matrix6(matrix5);

    ASSERT_APPROXIMATE(matrix6(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix6(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix6(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(matrix6(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(matrix6(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(2, 2), 6.06, 1e-10);
    ASSERT_APPROXIMATE(matrix6(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix6(3, 3), 1.0, 1e-10);

    MatrixD matrix7(matrix2);

    ASSERT_APPROXIMATE(matrix7(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 0), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 1), 16.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 2), 11.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 3), 12.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 0), 23.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 1), 26.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 2), 21.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 3), 22.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 0), 33.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 1), 63.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 2), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 3), 23.0, 1e-10);

    const Vector4F vector0(6.0f, 3.0f, 5.0f, 3.0f);
    const Vector4F vector1(8.0f, 3.1f, 9.0f, 13.0f);
    const Vector4F vector2(18.0f, 13.1f, 19.0f, 32.0f);
    const Vector4F vector3(-18.0f, -13.1f, -19.0f, -32.0f);

    MatrixF matrix8(vector0, vector1,
                    vector2, vector3,
                    MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix8(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(0, 3), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(1, 3), 13.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 2), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(2, 3), 32.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(3, 0), -18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(3, 1), -13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(3, 2), -19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix8(3, 3), -32.0f, 1e-8f);

    MatrixF matrix9(vector0, vector1,
                    vector2, vector3,
                    MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix9(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(0, 3), -18.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(1, 3), -13.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(2, 2), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(2, 3), -19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(3, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(3, 1), 13.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(3, 2), 32.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix9(3, 3), -32.0f, 1e-8f);

    MatrixF matrix10(4.0, 2.0f, 3.0f);

    ASSERT_APPROXIMATE(matrix10(0, 0), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 1), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 2), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 3), 1.0f, 1e-8f);

    AVectorF vector4(1.0f, 3.0f, 3.5f);

    vector4.Normalize();
    MatrixF matrix11(vector4, MathF::GetHalfPI() / 3.0f);

    const double cosValue = MathD::Cos(MathD::GetHalfPI() / 3.0);
    const double sinValue = MathD::Sin(MathD::GetHalfPI() / 3.0);
    const double oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(matrix11(0, 0), static_cast<double>(vector4[0]) * vector4[0] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix11(0, 1), static_cast<double>(vector4[0]) * vector4[1] * oneMinusCos - vector4[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(0, 2), static_cast<double>(vector4[0]) * vector4[2] * oneMinusCos + vector4[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(1, 0), static_cast<double>(vector4[0]) * vector4[1] * oneMinusCos + vector4[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(1, 1), static_cast<double>(vector4[1]) * vector4[1] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix11(1, 2), static_cast<double>(vector4[1]) * vector4[2] * oneMinusCos - vector4[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(matrix11(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(2, 0), static_cast<double>(vector4[0]) * vector4[2] * oneMinusCos - vector4[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(2, 1), static_cast<double>(vector4[1]) * vector4[2] * oneMinusCos + vector4[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(matrix11(2, 2), static_cast<double>(vector4[2]) * vector4[2] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix11(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix11(3, 3), 1.0f, 1e-8f);

    matrix10 = matrix11;

    ASSERT_TRUE(Approximate(matrix10, matrix11, 1e-8f));

    matrix7 = matrix5;

    ASSERT_APPROXIMATE(matrix7(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 2), 6.06, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 3), 1.0, 1e-10);

    matrix7.MakeDiagonal(2.0, 3.0, 5.0);

    ASSERT_APPROXIMATE(matrix7(0, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 1), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 2), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix7(3, 3), 1.0, 1e-10);

    matrix10.MakeRotation(vector4, MathF::GetHalfPI() / 3.0f);

    ASSERT_APPROXIMATE(matrix10(0, 0), static_cast<double>(vector4[0]) * vector4[0] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix10(0, 1), static_cast<double>(vector4[0]) * vector4[1] * oneMinusCos - vector4[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(0, 2), static_cast<double>(vector4[0]) * vector4[2] * oneMinusCos + vector4[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 0), static_cast<double>(vector4[0]) * vector4[1] * oneMinusCos + vector4[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(1, 1), static_cast<double>(vector4[1]) * vector4[1] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix10(1, 2), static_cast<double>(vector4[1]) * vector4[2] * oneMinusCos - vector4[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(matrix10(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 0), static_cast<double>(vector4[0]) * vector4[2] * oneMinusCos - vector4[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(2, 1), static_cast<double>(vector4[1]) * vector4[2] * oneMinusCos + vector4[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(matrix10(2, 2), static_cast<double>(vector4[2]) * vector4[2] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(matrix10(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix10(3, 3), 1.0f, 1e-8f);
}

void Mathematics::MatrixTesting::AccessTest()
{
    const MatrixF matrix0(3.0f, 4.0f, 8.1f, 3.2f,
                          6.0f, 3.3f, 4.4f, 5.5f,
                          6.6f, 7.7f, 8.8f, 9.9f,
                          10.0f, 55.0f, 6.3f, 3.21f);

    ASSERT_APPROXIMATE(matrix0(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 3), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 3.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 4.4f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 3), 5.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 6.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 7.7f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 8.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 3), 9.9f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 0), 10.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 1), 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 2), 6.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 3), 3.21f, 1e-8f);

    MatrixD matrix1(9.2, 1.0, 4.2, 5.2, 8.0, 5.5, 3.3, 4.4, 100.0, 5.6, 9.8, 7.3, 3.33, 4.44, 5.55, 6.66);

    ASSERT_APPROXIMATE(matrix1(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 4.4, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 6.66, 1e-10);

    Matrix3D matrix2 = matrix1.GetMatrix3();

    ASSERT_APPROXIMATE(matrix2(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 2), 9.8, 1e-10);

    HomogeneousPointD point0 = matrix1.GetRow(0);

    ASSERT_APPROXIMATE(point0[0], 9.2, 1e-10);
    ASSERT_APPROXIMATE(point0[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(point0[2], 4.2, 1e-10);
    ASSERT_APPROXIMATE(point0[3], 5.2, 1e-10);

    HomogeneousPointD point1(6.0, 5.0, 6.9, 2.2);
    matrix1.SetRow(0, point1);

    ASSERT_APPROXIMATE(matrix1(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 4.4, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 6.66, 1e-10);

    point1[0] = 9.99;
    point1[1] = 19.99;
    point1[2] = 29.99;
    point1[3] = 39.99;

    matrix1.SetRow(1, point1);

    ASSERT_APPROXIMATE(matrix1(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 6.66, 1e-10);

    point0 = matrix1.GetRow(1);

    ASSERT_APPROXIMATE(point0[0], 9.99, 1e-10);
    ASSERT_APPROXIMATE(point0[1], 19.99, 1e-10);
    ASSERT_APPROXIMATE(point0[2], 29.99, 1e-10);
    ASSERT_APPROXIMATE(point0[3], 39.99, 1e-10);

    point1[0] = -9.99;
    point1[1] = -19.99;
    point1[2] = -29.99;
    point1[3] = -39.99;

    matrix1.SetRow(2, point1);

    ASSERT_APPROXIMATE(matrix1(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), -9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), -19.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), -29.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), -39.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 6.66, 1e-10);

    point0 = matrix1.GetRow(2);

    ASSERT_APPROXIMATE(point0[0], -9.99, 1e-10);
    ASSERT_APPROXIMATE(point0[1], -19.99, 1e-10);
    ASSERT_APPROXIMATE(point0[2], -29.99, 1e-10);
    ASSERT_APPROXIMATE(point0[3], -39.99, 1e-10);

    point1[0] = 1.993;
    point1[1] = 1.992;
    point1[2] = 1.991;
    point1[3] = 1.99;

    matrix1.SetRow(3, point1);

    ASSERT_APPROXIMATE(matrix1(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), -9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), -19.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), -29.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), -39.99, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 1.993, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 1.992, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 1.991, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 1.99, 1e-10);

    point0 = matrix1.GetRow(3);

    ASSERT_APPROXIMATE(point0[0], 1.993, 1e-10);
    ASSERT_APPROXIMATE(point0[1], 1.992, 1e-10);
    ASSERT_APPROXIMATE(point0[2], 1.991, 1e-10);
    ASSERT_APPROXIMATE(point0[3], 1.99, 1e-10);

    std::vector<float> floatVector = matrix0.GetColumnMajor();

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ASSERT_APPROXIMATE(floatVector[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[4], 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[8], 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[12], 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[5], 3.3f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[9], 4.4f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[13], 5.5f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[2], 6.6f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[6], 7.7f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[10], 8.8f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[14], 9.9f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[3], 10.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[7], 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[11], 6.3f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[15], 3.21f, 1e-8f);

#include SYSTEM_WARNING_POP
}

void Mathematics::MatrixTesting::OperatorCalculateTest()
{
    const MatrixF matrix0(3.0f, 4.0f, 8.1f, 3.2f, 13.0f, 14.0f, 18.1f, 13.2f, 23.0f, 24.0f, 28.1f, 23.2f, 33.0f, 34.0f, 38.1f, 33.2f);

    MatrixF matrix1 = -matrix0;

    ASSERT_APPROXIMATE(matrix1(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 3), -3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), -13.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), -14.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), -18.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 3), -13.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), -23.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), -24.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), -28.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 3), -23.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 0), -33.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 1), -34.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 2), -38.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 3), -33.2f, 1e-8f);

    MatrixF matrix2(9.2f, 3.0f, 2.0f, 9.0f, 19.2f, 13.0f, 12.0f, 19.0f, 29.2f, 23.0f, 22.0f, 29.0f, 9.23f, 3.03f, 2.03f, 9.03f);

    matrix2 += matrix1;

    ASSERT_APPROXIMATE(matrix2(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 3), 5.8f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -23.77f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -30.97f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -36.07f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -24.17f, 1e-5f);

    matrix2 -= matrix0;

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 2.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -6.8f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -24.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -7.4f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -16.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -25.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -34.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -17.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -56.77f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -64.97f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -74.17f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -57.37f, 1e-5f);

    matrix2 *= 6.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 15.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -40.8f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -90.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -145.2f, 1e-4f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -44.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -100.8f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -150.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -205.2f, 1e-4f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -104.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -340.62f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -389.82f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -445.02f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -344.22f, 1e-4f);

    matrix2 /= 2.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 7.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -20.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -45.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -72.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -22.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -50.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -75.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -102.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -52.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -170.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -194.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -222.51f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -172.11f, 1e-4f);

    MatrixF matrix3 = matrix0 + matrix2;

    ASSERT_APPROXIMATE(matrix3(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), -7.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 1), -31.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), -54.5f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), -9.0f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(2, 0), -27.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 1), -51.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), -74.5f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 3), -29.0f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), -137.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), -160.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), -184.41f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), -138.91f, 1e-4f);

    matrix3 = matrix0 - matrix2;

    ASSERT_APPROXIMATE(matrix3(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(0, 3), -4.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 33.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 59.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 90.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 35.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 73.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 130.7f, 1e-4f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 75.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 203.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 228.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 260.61f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 205.31f, 1e-4f);

    matrix3 = matrix0 * 5.0f;

    ASSERT_APPROXIMATE(matrix3(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 16.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 65.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 70.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 90.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 66.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 115.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 120.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 140.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 116.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 165.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 170.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 190.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 166.0f, 1e-8f);

    matrix3 = 3.0f * matrix0;

    ASSERT_APPROXIMATE(matrix3(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 9.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 39.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 42.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 54.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 39.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 69.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 72.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 84.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 69.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 102.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 114.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 99.6f, 1e-5f);

    matrix3 = matrix0 / (-2.0f);

    ASSERT_APPROXIMATE(matrix3(0, 0), -1.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), -2.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), -4.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), -1.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), -6.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), -7.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), -9.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 3), -6.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), -11.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), -12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), -14.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), -11.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 0), -16.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), -17.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), -19.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), -16.6f, 1e-8f);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        MatrixF matrix4(randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator));

        MatrixF matrix5(randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator));

        MatrixF matrix6(matrix5);

        matrix6 *= matrix4;

        const MatrixF matrix31(matrix5(0, 0) * matrix4(0, 0) +
                                   matrix5(0, 1) * matrix4(1, 0) +
                                   matrix5(0, 2) * matrix4(2, 0) +
                                   matrix5(0, 3) * matrix4(3, 0),

                               matrix5(0, 0) * matrix4(0, 1) +
                                   matrix5(0, 1) * matrix4(1, 1) +
                                   matrix5(0, 2) * matrix4(2, 1) +
                                   matrix5(0, 3) * matrix4(3, 1),

                               matrix5(0, 0) * matrix4(0, 2) +
                                   matrix5(0, 1) * matrix4(1, 2) +
                                   matrix5(0, 2) * matrix4(2, 2) +
                                   matrix5(0, 3) * matrix4(3, 2),

                               matrix5(0, 0) * matrix4(0, 3) +
                                   matrix5(0, 1) * matrix4(1, 3) +
                                   matrix5(0, 2) * matrix4(2, 3) +
                                   matrix5(0, 3) * matrix4(3, 3),

                               matrix5(1, 0) * matrix4(0, 0) +
                                   matrix5(1, 1) * matrix4(1, 0) +
                                   matrix5(1, 2) * matrix4(2, 0) +
                                   matrix5(1, 3) * matrix4(3, 0),

                               matrix5(1, 0) * matrix4(0, 1) +
                                   matrix5(1, 1) * matrix4(1, 1) +
                                   matrix5(1, 2) * matrix4(2, 1) +
                                   matrix5(1, 3) * matrix4(3, 1),

                               matrix5(1, 0) * matrix4(0, 2) +
                                   matrix5(1, 1) * matrix4(1, 2) +
                                   matrix5(1, 2) * matrix4(2, 2) +
                                   matrix5(1, 3) * matrix4(3, 2),

                               matrix5(1, 0) * matrix4(0, 3) +
                                   matrix5(1, 1) * matrix4(1, 3) +
                                   matrix5(1, 2) * matrix4(2, 3) +
                                   matrix5(1, 3) * matrix4(3, 3),

                               matrix5(2, 0) * matrix4(0, 0) +
                                   matrix5(2, 1) * matrix4(1, 0) +
                                   matrix5(2, 2) * matrix4(2, 0) +
                                   matrix5(2, 3) * matrix4(3, 0),

                               matrix5(2, 0) * matrix4(0, 1) +
                                   matrix5(2, 1) * matrix4(1, 1) +
                                   matrix5(2, 2) * matrix4(2, 1) +
                                   matrix5(2, 3) * matrix4(3, 1),

                               matrix5(2, 0) * matrix4(0, 2) +
                                   matrix5(2, 1) * matrix4(1, 2) +
                                   matrix5(2, 2) * matrix4(2, 2) +
                                   matrix5(2, 3) * matrix4(3, 2),

                               matrix5(2, 0) * matrix4(0, 3) +
                                   matrix5(2, 1) * matrix4(1, 3) +
                                   matrix5(2, 2) * matrix4(2, 3) +
                                   matrix5(2, 3) * matrix4(3, 3),

                               matrix5(3, 0) * matrix4(0, 0) +
                                   matrix5(3, 1) * matrix4(1, 0) +
                                   matrix5(3, 2) * matrix4(2, 0) +
                                   matrix5(3, 3) * matrix4(3, 0),

                               matrix5(3, 0) * matrix4(0, 1) +
                                   matrix5(3, 1) * matrix4(1, 1) +
                                   matrix5(3, 2) * matrix4(2, 1) +
                                   matrix5(3, 3) * matrix4(3, 1),

                               matrix5(3, 0) * matrix4(0, 2) +
                                   matrix5(3, 1) * matrix4(1, 2) +
                                   matrix5(3, 2) * matrix4(2, 2) +
                                   matrix5(3, 3) * matrix4(3, 2),

                               matrix5(3, 0) * matrix4(0, 3) +
                                   matrix5(3, 1) * matrix4(1, 3) +
                                   matrix5(3, 2) * matrix4(2, 3) +
                                   matrix5(3, 3) * matrix4(3, 3));

        ASSERT_TRUE(Approximate(matrix31, matrix6, 1e-8f));

        matrix6 = matrix5 * matrix4;

        ASSERT_TRUE(Approximate(matrix31, matrix6, 1e-8f));

        HomogeneousPointF point0(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        const HomogeneousPointF point1 = matrix6 * point0;
        const HomogeneousPointF point2 = point0 * matrix6;

        HomogeneousPointF fourthPoint(matrix6(0, 0) * point0[0] +
                                          matrix6(0, 1) * point0[1] +
                                          matrix6(0, 2) * point0[2] +
                                          matrix6(0, 3) * point0[3],
                                      matrix6(1, 0) * point0[0] +
                                          matrix6(1, 1) * point0[1] +
                                          matrix6(1, 2) * point0[2] +
                                          matrix6(1, 3) * point0[3],
                                      matrix6(2, 0) * point0[0] +
                                          matrix6(2, 1) * point0[1] +
                                          matrix6(2, 2) * point0[2] +
                                          matrix6(2, 3) * point0[3],
                                      matrix6(3, 0) * point0[0] +
                                          matrix6(3, 1) * point0[1] +
                                          matrix6(3, 2) * point0[2] +
                                          matrix6(3, 3) * point0[3]);

        ASSERT_TRUE(Approximate(point1, fourthPoint, 1e-2f));

        fourthPoint[0] = matrix6(0, 0) * point0[0] +
                         matrix6(1, 0) * point0[1] +
                         matrix6(2, 0) * point0[2] +
                         matrix6(3, 0) * point0[3];

        fourthPoint[1] = matrix6(0, 1) * point0[0] +
                         matrix6(1, 1) * point0[1] +
                         matrix6(2, 1) * point0[2] +
                         matrix6(3, 1) * point0[3];

        fourthPoint[2] = matrix6(0, 2) * point0[0] +
                         matrix6(1, 2) * point0[1] +
                         matrix6(2, 2) * point0[2] +
                         matrix6(3, 2) * point0[3];

        fourthPoint[3] = matrix6(0, 3) * point0[0] +
                         matrix6(1, 3) * point0[1] +
                         matrix6(2, 3) * point0[2] +
                         matrix6(3, 3) * point0[3];

        ASSERT_TRUE(Approximate(point2, fourthPoint, 1e-3f));

        MatrixF matrix7 = TransposeTimes(matrix4, matrix5);
        MatrixF matrix8 = matrix4.Transpose() * matrix5;

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TimesTranspose(matrix4, matrix5);
        matrix8 = matrix4 * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TransposeTimesTranspose(matrix4, matrix5);
        matrix8 = matrix4.Transpose() * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));
    }
}

void Mathematics::MatrixTesting::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        HomogeneousPointF point0(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        const HomogeneousPointF point1(randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator));

        MatrixF matrix0(randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator));

        const float qForm = matrix0.QuadraticForm(point0, point1);

        HomogeneousPointF point2 = matrix0 * point1;

        const float testQFormValue = point0[0] * point2[0] + point0[1] * point2[1] + point0[2] * point2[2] + point0[3] * point2[3];

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        MatrixF matrix1 = matrix0.Transpose();

        for (int row = 0; row < 4; ++row)
        {
            for (int colomn = 0; colomn < 4; ++colomn)
            {
                ASSERT_APPROXIMATE(matrix0(row, colomn), matrix1(colomn, row), 1e-8f);
            }
        }

        const Matrix3F matrix03(matrix1(1, 1), matrix1(1, 2), matrix1(1, 3),
                                matrix1(2, 1), matrix1(2, 2), matrix1(2, 3),
                                matrix1(3, 1), matrix1(3, 2), matrix1(3, 3));

        const Matrix3F matrix13(matrix1(1, 0), matrix1(1, 2), matrix1(1, 3),
                                matrix1(2, 0), matrix1(2, 2), matrix1(2, 3),
                                matrix1(3, 0), matrix1(3, 2), matrix1(3, 3));

        const Matrix3F matrix23(matrix1(1, 0), matrix1(1, 1), matrix1(1, 3),
                                matrix1(2, 0), matrix1(2, 1), matrix1(2, 3),
                                matrix1(3, 0), matrix1(3, 1), matrix1(3, 3));

        const Matrix3F matrix33(matrix1(1, 0), matrix1(1, 1), matrix1(1, 2),
                                matrix1(2, 0), matrix1(2, 1), matrix1(2, 2),
                                matrix1(3, 0), matrix1(3, 1), matrix1(3, 2));

        const float determinant = matrix1(0, 0) * matrix03.Determinant() -
                                  matrix1(0, 1) * matrix13.Determinant() +
                                  matrix1(0, 2) * matrix23.Determinant() -
                                  matrix1(0, 3) * matrix33.Determinant();

        ASSERT_APPROXIMATE(determinant, matrix1.Determinant(), 1e-2f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const MatrixF matrix2 = matrix1.Inverse();

            MatrixF matrix3 = matrix1 * matrix2;

            MatrixF matrix4 = matrix1.Adjoint();
            matrix4 /= determinant;

            matrix3 = matrix4 * matrix1;
        }

        APointF fourthPoint(6.0f, 5.4f, 3.3f);

        matrix1 = matrix0.TimesDiagonal(fourthPoint);

        const MatrixF matrix4 = matrix0 * MatrixF(fourthPoint[0], fourthPoint[1], fourthPoint[2]);

        ASSERT_TRUE(Approximate(matrix4, matrix1, 1e-8f));

        matrix1 = matrix0.DiagonalTimes(fourthPoint);

        Matrix3F matrix5 = Matrix3F(fourthPoint[0], fourthPoint[1], fourthPoint[2]) * matrix0.GetMatrix3();

        ASSERT_APPROXIMATE(matrix5(0, 0), matrix1(0, 0), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(0, 1), matrix1(0, 1), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(0, 2), matrix1(0, 2), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(1, 0), matrix1(1, 0), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(1, 1), matrix1(1, 1), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(1, 2), matrix1(1, 2), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(2, 0), matrix1(2, 0), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(2, 1), matrix1(2, 1), 0.00001f);
        ASSERT_APPROXIMATE(matrix5(2, 2), matrix1(2, 2), 0.00001f);

        std::uniform_real_distribution<float> angleRandomDistribution(0.0f, MathF::GetPI() - 0.01f);

        const float angle = angleRandomDistribution(generator);
        AVectorF vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        vector0.Normalize();

        MatrixF matrix6(vector0, angle);

        MatrixF matrix7(matrix6);

        matrix6.Orthonormalize();

        Vector3F vector2(matrix7(0, 0), matrix7(1, 0), matrix7(2, 0));
        const Vector3F vector3(matrix6(0, 0), matrix6(1, 0), matrix6(2, 0));

        vector2.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector2, vector3, 1e-7f));

        Vector3F vector4(matrix7(0, 1), matrix7(1, 1), matrix7(2, 1));
        const Vector3F vector5(matrix6(0, 1), matrix6(1, 1), matrix6(2, 1));

        vector4 -= (Vector3ToolsF::DotProduct(vector3, vector4)) * vector3;

        vector4.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(vector4, vector5, 1e-3f));

        Vector3F seventhVector(matrix7(0, 2), matrix7(1, 2), matrix7(2, 2));
        const Vector3F eighthVector(matrix6(0, 2), matrix6(1, 2), matrix6(2, 2));

        seventhVector -= (Vector3ToolsF::DotProduct(vector3, seventhVector)) * vector3;

        seventhVector -= (Vector3ToolsF::DotProduct(vector5, seventhVector)) * vector5;

        seventhVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, eighthVector, 1e-6f));
    }
}

void Mathematics::MatrixTesting::ProjectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        AVectorF vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const APointF point0(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        AVectorF vector1(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const APointF point1(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        vector0.Normalize();
        vector1.Normalize();

        if (MathF::GetZeroTolerance() < Dot(vector0, vector1))
        {
            MatrixF matrix0;
            matrix0.MakeObliqueProjection(point0, vector0, vector1);

            APointF point2 = matrix0 * point1;

            point2 /= -Dot(vector0, vector1);

            const PlaneF firstPlane = PlaneF(vector0, point0);

            // 转换后的点的平面上。
            const float distance = firstPlane.DistanceTo(point2);

            ASSERT_APPROXIMATE(distance, 0.0f, 1e-2f);

            // 原来的点与转换后的点的差是direction或-direction
            AVectorF vector5 = point1 - point2;

            vector5.Normalize();

            const Vector3F seventhVector(vector5[0], vector5[1], vector5[2]);
            const Vector3F eighthVector(-seventhVector);
            const Vector3F ninthVector(vector1[0], vector1[1], vector1[2]);

            ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, ninthVector, 1e-4f) || Vector3ToolsF::Approximate(eighthVector, ninthVector, 1e-4f));
        }

        const APointF fourthPoint(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        MatrixF matrix1;
        matrix1.MakePerspectiveProjection(point0, vector0, fourthPoint);

        APointF fifthPoint = matrix1 * point1;

        fifthPoint /= (-Dot(point1, vector0) + Dot(fourthPoint, vector0));

        const PlaneF secondPlane = PlaneF(vector0, point0);

        // 原来的点与转换后的点和点eye在同一直线上
        AVectorF eleventhVector = point1 - fifthPoint;

        eleventhVector.Normalize();

        AVectorF twelfthVector = fifthPoint - fourthPoint;

        twelfthVector.Normalize();

        const Vector3F thirteenthVector(twelfthVector[0], twelfthVector[1], twelfthVector[2]);

        const Vector3F FourteenthVector(eleventhVector[0], eleventhVector[1], eleventhVector[2]);

        matrix1.MakeReflection(point0, vector0);

        const APointF sixthPoint = matrix1 * point1;

        const float firstDistance = secondPlane.DistanceTo(point1);

        const float secondDistance = secondPlane.DistanceTo(sixthPoint);

        ASSERT_APPROXIMATE(firstDistance, -secondDistance, 1e-4f);
    }
}

void Mathematics::MatrixTesting::CompareTest()
{
    const MatrixF matrix0(MatrixInitType::Zero);
    const MatrixF matrix1(MatrixInitType::Identity);

    ASSERT_TRUE(matrix0 == matrix0);
    ASSERT_FALSE(matrix0 == matrix1);
    ASSERT_TRUE(matrix0 != matrix1);

    ASSERT_TRUE(matrix0 < matrix1);
    ASSERT_TRUE(matrix0 <= matrix1);
    ASSERT_FALSE(matrix0 > matrix1);
    ASSERT_FALSE(matrix0 >= matrix1);

    ASSERT_TRUE(Approximate(matrix0, matrix0, 1e-8f));
    ASSERT_TRUE(Approximate(matrix1, matrix1));
    ASSERT_FALSE(Approximate(matrix0, matrix1));
}

void Mathematics::MatrixTesting::HomogeneousPointTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        HomogeneousPointF point0(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        MatrixF matrix0(randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator),
                        randomDistribution(generator));

        const HomogeneousPointF point1 = matrix0 * point0;
        const HomogeneousPointF point2 = point0 * matrix0;

        HomogeneousPointF fourthPoint(matrix0(0, 0) * point0[0] +
                                          matrix0(0, 1) * point0[1] +
                                          matrix0(0, 2) * point0[2] +
                                          matrix0(0, 3) * point0[3],

                                      matrix0(1, 0) * point0[0] +
                                          matrix0(1, 1) * point0[1] +
                                          matrix0(1, 2) * point0[2] +
                                          matrix0(1, 3) * point0[3],

                                      matrix0(2, 0) * point0[0] +
                                          matrix0(2, 1) * point0[1] +
                                          matrix0(2, 2) * point0[2] +
                                          matrix0(2, 3) * point0[3],

                                      matrix0(3, 0) * point0[0] +
                                          matrix0(3, 1) * point0[1] +
                                          matrix0(3, 2) * point0[2] +
                                          matrix0(3, 3) * point0[3]);

        ASSERT_TRUE(Approximate(point1, fourthPoint, 1e-02f));

        fourthPoint[0] = matrix0(0, 0) * point0[0] +
                         matrix0(1, 0) * point0[1] +
                         matrix0(2, 0) * point0[2] +
                         matrix0(3, 0) * point0[3];

        fourthPoint[1] = matrix0(0, 1) * point0[0] +
                         matrix0(1, 1) * point0[1] +
                         matrix0(2, 1) * point0[2] +
                         matrix0(3, 1) * point0[3];

        fourthPoint[2] = matrix0(0, 2) * point0[0] +
                         matrix0(1, 2) * point0[1] +
                         matrix0(2, 2) * point0[2] +
                         matrix0(3, 2) * point0[3];

        fourthPoint[3] = matrix0(0, 3) * point0[0] +
                         matrix0(1, 3) * point0[1] +
                         matrix0(2, 3) * point0[2] +
                         matrix0(3, 3) * point0[3];

        ASSERT_TRUE(Approximate(point2, fourthPoint, 1e-02f));

        APointF seventhPoint(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const APointF eighthPoint = matrix0 * seventhPoint;

        const APointF ninthPoint(matrix0(0, 0) * seventhPoint[0] +
                                     matrix0(0, 1) * seventhPoint[1] +
                                     matrix0(0, 2) * seventhPoint[2] +
                                     matrix0(0, 3),

                                 matrix0(1, 0) * seventhPoint[0] +
                                     matrix0(1, 1) * seventhPoint[1] +
                                     matrix0(1, 2) * seventhPoint[2] +
                                     matrix0(1, 3),

                                 matrix0(2, 0) * seventhPoint[0] +
                                     matrix0(2, 1) * seventhPoint[1] +
                                     matrix0(2, 2) * seventhPoint[2] +
                                     matrix0(2, 3));

        ASSERT_TRUE(Approximate(eighthPoint, ninthPoint, 1e-02f));

        AVectorF vector0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const AVectorF vector1 = matrix0 * vector0;

        const AVectorF vector2(matrix0(0, 0) * vector0[0] +
                                   matrix0(0, 1) * vector0[1] +
                                   matrix0(0, 2) * vector0[2],

                               matrix0(1, 0) * vector0[0] +
                                   matrix0(1, 1) * vector0[1] +
                                   matrix0(1, 2) * vector0[2],

                               matrix0(2, 0) * vector0[0] +
                                   matrix0(2, 1) * vector0[1] +
                                   matrix0(2, 2) * vector0[2]);

        ASSERT_TRUE(Approximate(vector1, vector2, 1e-02f));
    }

    std::vector<HomogeneousPointF> point0Vector;
    std::vector<APointF> firstAPointVector;
    std::vector<AVectorF> vector0Vector;

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const HomogeneousPointF fifthPoint(randomDistribution(generator),
                                           randomDistribution(generator),
                                           randomDistribution(generator),
                                           randomDistribution(generator));

        point0Vector.push_back(fifthPoint);

        const APointF tenthPoint(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        firstAPointVector.push_back(tenthPoint);

        const AVectorF vector3(randomDistribution(generator),
                               randomDistribution(generator),
                               randomDistribution(generator));

        vector0Vector.push_back(vector3);
    }

    MatrixF matrix1(randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator),
                    randomDistribution(generator));

    std::vector<HomogeneousPointF> point1Vector = BatchMultiply(matrix1, point0Vector);

    std::vector<APointF> secondAPointVector = BatchMultiply(matrix1, firstAPointVector);

    std::vector<AVectorF> vector1Vector = BatchMultiply(matrix1, vector0Vector);

    for (size_t i = 0; i < point1Vector.size(); ++i)
    {
        const HomogeneousPointF sixthPoint(matrix1(0, 0) * point0Vector.at(i)[0] +
                                               matrix1(0, 1) * point0Vector.at(i)[1] +
                                               matrix1(0, 2) * point0Vector.at(i)[2] +
                                               matrix1(0, 3) * point0Vector.at(i)[3],

                                           matrix1(1, 0) * point0Vector.at(i)[0] +
                                               matrix1(1, 1) * point0Vector.at(i)[1] +
                                               matrix1(1, 2) * point0Vector.at(i)[2] +
                                               matrix1(1, 3) * point0Vector.at(i)[3],

                                           matrix1(2, 0) * point0Vector.at(i)[0] +
                                               matrix1(2, 1) * point0Vector.at(i)[1] +
                                               matrix1(2, 2) * point0Vector.at(i)[2] +
                                               matrix1(2, 3) * point0Vector.at(i)[3],

                                           matrix1(3, 0) * point0Vector.at(i)[0] +
                                               matrix1(3, 1) * point0Vector.at(i)[1] +
                                               matrix1(3, 2) * point0Vector.at(i)[2] +
                                               matrix1(3, 3) * point0Vector.at(i)[3]);

        ASSERT_TRUE(Approximate(sixthPoint, point1Vector.at(i), 1e-02f));

        const APointF eleventhPoint(matrix1(0, 0) * firstAPointVector.at(i)[0] +
                                        matrix1(0, 1) * firstAPointVector.at(i)[1] +
                                        matrix1(0, 2) * firstAPointVector.at(i)[2] +
                                        matrix1(0, 3),

                                    matrix1(1, 0) * firstAPointVector.at(i)[0] +
                                        matrix1(1, 1) * firstAPointVector.at(i)[1] +
                                        matrix1(1, 2) * firstAPointVector.at(i)[2] +
                                        matrix1(1, 3),

                                    matrix1(2, 0) * firstAPointVector.at(i)[0] +
                                        matrix1(2, 1) * firstAPointVector.at(i)[1] +
                                        matrix1(2, 2) * firstAPointVector.at(i)[2] +
                                        matrix1(2, 3));

        ASSERT_TRUE(Approximate(eleventhPoint, secondAPointVector.at(i), 1e-03f));

        const AVectorF vector4(matrix1(0, 0) * vector0Vector.at(i)[0] +
                                   matrix1(0, 1) * vector0Vector.at(i)[1] +
                                   matrix1(0, 2) * vector0Vector.at(i)[2],

                               matrix1(1, 0) * vector0Vector.at(i)[0] +
                                   matrix1(1, 1) * vector0Vector.at(i)[1] +
                                   matrix1(1, 2) * vector0Vector.at(i)[2],

                               matrix1(2, 0) * vector0Vector.at(i)[0] +
                                   matrix1(2, 1) * vector0Vector.at(i)[1] +
                                   matrix1(2, 2) * vector0Vector.at(i)[2]);

        ASSERT_TRUE(Approximate(vector4, vector1Vector.at(i), 1e-03f));
    }
}

void Mathematics::MatrixTesting::Invert3x3Test()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const MatrixF matrix0(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const Matrix3F matrix1 = matrix0.GetMatrix3();

        if (MathF::GetZeroTolerance() < matrix1.Determinant())
        {
            const MatrixF matrix2 = matrix0.Invert3x3();

            const Matrix3F matrix3 = matrix2.GetMatrix3();

            const Matrix3F matrix4 = matrix1.Inverse();

            ASSERT_TRUE(Approximate(matrix3, matrix4, 1e-4f));
        }
    }
}
